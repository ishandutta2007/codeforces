#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n;
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
    
    std::vector<int> ans(n);
    auto dfs = [&](auto self, int u, int p, int x) -> void {
        ans[u] = x;
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u, x == 0 ? 1 : -x);
            ans[u] -= x == 0 ? 1 : -x;
        }
    };
    dfs(dfs, 0, -1, 0);
    
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
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