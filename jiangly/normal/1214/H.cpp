#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<int> parent(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> color(n);
    if (k == 2) {
        function<void(int)> dfs = [&](int u) {
            for (int v : g[u]){
                if (v == parent[u])
                    continue;
                parent[v] = u;
                color[v] = color[u] ^ 1;
                dfs(v);
            }
        };
        parent[0] = -1;
        dfs(0);
    } else {
        vector<vector<int>> down(n, vector<int>(3));
        vector<int> up(n);
        function<void(int)> dfs1 = [&](int u) {
            for (int v : g[u]) {
                if (v == parent[u])
                    continue;
                parent[v] = u;
                dfs1(v);
                int x = down[v][0] + 1;
                for (int i = 0; i < 3; ++i)
                    if (x > down[u][i])
                        swap(x, down[u][i]);
            }
        };
        function<void(int)> dfs2 = [&](int u) {
            for (int v : g[u]) {
                if (v == parent[u])
                    continue;
                up[v] = max(up[u], down[u][0] != down[v][0] + 1 ? down[u][0] : down[u][1]) + 1;
                dfs2(v);
            }
        };
        parent[0] = -1;
        dfs1(0);
        dfs2(0);
        for (int i = 0; i < n; ++i) {
            int x = up[i];
            for (int j = 0; j < 3; ++j)
                if (x > down[i][j])
                    swap(x, down[i][j]);
            if (g[i].size() >= 3 && down[i][1] + down[i][2] >= k - 1) {
                cout << "NO" << endl;
                return 0;
            }
        }
        vector<int> dep(n);
        function<void(int)> dfs = [&](int u) {
            for (int v : g[u]) {
                if (v == parent[u])
                    continue;
                parent[v] = u;
                dep[v] = dep[u] + 1;
                dfs(v);
            }
        };
        dfs(0);
        int s = 0;
        for (int i = 1; i < n; ++i)
            if (dep[i] > dep[s])
                s = i;
        parent[s] = 0;
        dep[s] = 0;
        dfs(s);
        int t = 0;
        for (int i = 1; i < n; ++i)
            if (dep[i] > dep[t])
                t = i;
        int len = dep[t] + 1;
        if (len >= k) {
            for (int i = 0; i < len / 2 - 1; ++i)
                t = parent[t];
            s = parent[t];
            parent[s] = t;
            color[s] = 1;
            function<void(int, int)> dfs3 = [&](int u, int delta) {
                for (int v : g[u]) {
                    if (v == parent[u])
                        continue;
                    parent[v] = u;
                    color[v] = (color[u] + delta + k) % k;
                    dfs3(v, delta);
                }
            };
            dfs3(s, 1);
            dfs3(t, -1);
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i){
        cout << color[i] + 1;
        if (i < n - 1)
            cout << ' ';
    }
    cout << endl;
    return 0;
}