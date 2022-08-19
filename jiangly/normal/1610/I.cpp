#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = (n - 1) % 2;
    std::vector<int> mn(n), parent(n, -1);
    std::function<void(int)> dfs = [&](int u) {
        mn[u] = u;
        for (auto v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            dfs(v);
            mn[u] = std::min(mn[u], mn[v]);
        }
    };
    dfs(0);
    
    std::vector<std::vector<int>> rem(n);
    for (int i = 1; i < n; i++) {
        rem[mn[i]].push_back(i);
    }
    
    std::vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        deg[i] = adj[i].size();
    }
    
    std::string out(n, '0');
    
    std::vector<int> f(n);
    
    std::function<void(int)> work = [&](int u) {
        deg[u] = -1;
        for (auto v : adj[u]) {
            if (deg[v] >= 0) {
                ans ^= 1 ^ f[u];
                ans ^= 1 + f[u];
                f[v] ^= 1 + f[u];
                if (deg[v] == 0) {
                    work(v);
                }
            }
        }
    };
    
    for (int k = n - 1; k >= 0; k--) {
        out[k] = (ans > 0) ? '1' : '2';
        for (auto u : rem[k]) {
            deg[u]--;
            deg[parent[u]]--;
        }
        if (deg[k] == 0) {
            work(k);
        }
    }
    
    std::cout << out << '\n';
    
    return 0;
}