#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isLeaf(TreeNode *r) {
        return r && !r->left && !r->right;
    }

    void DFS(TreeNode *r, int remains, bool &found) {
        found = isLeaf(r) && r->val == remains;
        if (!found && r->left)
            DFS(r->left, remains - r->val, found);
        if (!found && r->right)
            DFS(r->right, remains - r->val, found);
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        bool found = false;
        DFS(root, sum, found);
        return found;
    }
};

void func(TreeNode *tx) {
    cout << tx->val << ",";
}

void test1() {
    vector<int> v1{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, -1, 1};

    TreeNode *t1 = new TreeNode(v1);
    cout << "t ? " << Solution().hasPathSum(new TreeNode(vector<int>{1}), 1) << endl;
    cout << "f ? " << Solution().hasPathSum(t1, 21) << endl;
    cout << "t ? " << Solution().hasPathSum(t1, 22) << endl;
//    cout << " ? " << Solution().func() << endl;
//    cout << " ? " << Solution().func() << endl;
}

void test2() {

}

void test3() {

}