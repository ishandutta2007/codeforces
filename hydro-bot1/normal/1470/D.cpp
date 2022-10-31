// Hydro submission #618a56841edf93b3ad6598cf@1636456068749
#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;

const int N = 3e5 + 5;
int n, m, cnt;

std::vector<int> col;
std::vector<bool> vis;
std::vector<std::vector<int>> g;
std::stack<int> ans;

void dfs(int u, int lastCol) {
    vis[u] = true, ++cnt;
    int color = lastCol ^ 1;
    if (color) for (auto v : g[u]) color &= ~col[v];
    if (color) col[u] = color, ans.push(u);
    for (auto v : g[u]) if (!vis[v]) dfs(v, color);
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr);

    int _;
    for (cin >> _; _--; cnt = 0, col.clear(), vis.clear(), g.clear()) {
        for (; !ans.empty(); ans.pop());
        cin >> n >> m;
        col.resize(n + 1), vis.resize(n + 1), g.resize(n + 1);
        for (int i = 1, u, v; i <= m; ++i) {
            cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
        }
        dfs(1, 0);
        if (cnt != n) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n" << ans.size() << '\n';
        for (; !ans.empty(); ans.pop()) cout << ans.top() << ' ';
        cout << '\n';
    }
    return 0;
}