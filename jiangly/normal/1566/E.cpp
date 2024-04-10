#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int parent[n];
    bool f[n][2] = {};
    parent[0] = -1;
    
    bool g[n] = {};
    
    int res = 0;
    std::function<void(int)> dfs = [&](int u) {
        bool leaf = true;
        for (auto v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            dfs(v);
            if (g[v]) {
                continue;
            }
            leaf = false;
            f[u][0] |= f[v][1];
            f[u][1] |= f[v][0];
        }
        if (leaf) {
            res++;
            f[u][0] = true;
        }
        if (u != 0 && !f[u][0]) {
            g[u] = true;
            res--;
        }
    };
    
    dfs(0);
    
    std::cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}