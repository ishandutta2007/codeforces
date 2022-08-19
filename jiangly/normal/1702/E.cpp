#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 2) {
            std::cout << "NO\n";
            return;
        }
    }
    
    std::vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i] && adj[i].size() == 2) {
            int j = i, k = adj[i][0];
            int len = 0;
            while (!vis[j] && adj[j].size() == 2) {
                vis[j] = true;
                len++;
                k ^= adj[j][0] ^ adj[j][1];
                std::swap(j, k);
            }
            
            if (j == i && len % 2 == 1) {
                std::cout << "NO\n";
                return;
            }
        }
    }
    
    std::cout << "YES\n";
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