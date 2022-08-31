#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> w(n);
    std::vector<std::set<int>> s(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = 0;
    std::function<void(int, int)> dfs = [&](int u, int p) {
        s[u] = {w[u]};
        bool nice = true;
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            w[v] = w[u] ^ a[v];
            dfs(v, u);
            if (s[u].size() < s[v].size()) {
                std::swap(s[u], s[v]);
            }
            for (auto x : s[v]) {
                if (s[u].count(x ^ a[u])) {
                    nice = false;
                }
            }
            for (auto x : s[v]) {
                s[u].insert(x);
            }
            s[v].clear();
        }
        if (!nice) {
            ans++;
            s[u].clear();
        }
    };
    dfs(0, -1);
    
    std::cout << ans << "\n";
    
    return 0;
}