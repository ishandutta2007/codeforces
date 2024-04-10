// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
vector<vector<int>> e;
string cut, leaf;
vector<int> buds;
int main_leaves;

void dfs1(int x, int p) {
    int children = 0, leaf_children = 0;
    for (int y : e[x]) {
        if (y == p) continue;
        dfs1(y, x);
        if (cut[y]) continue;
        children++;
        if (leaf[y]) leaf_children++;
    }

    if (children == 0) {
        leaf[x] = true;
    } else if (leaf_children == children && x != 0) {
        cut[x] = true;
        buds.push_back(children);
    }
}

void dfs2(int x, int p) {
    int children = 0;
    for (int y : e[x]) {
        if (y == p || cut[y]) continue;
        dfs2(y, x);
        children++;
    }

    if (children == 0) main_leaves++;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        e.assign(n, {});
        cut = leaf = string(n, 0);
        buds = {};
        main_leaves = 0;

        for (int i=0; i<n-1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        dfs1(0, 0);
        dfs2(0, 0);

        int sol = main_leaves;
        for (int x : buds) {
            sol -= 1;
            sol += x;
        }

        cout << sol << '\n';
    }
}