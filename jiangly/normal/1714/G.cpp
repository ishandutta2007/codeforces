#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<std::array<int, 3>>> adj(n);
    for (int i = 1; i < n; i++) {
        int x, a, b;
        std::cin >> x >> a >> b;
        x--;
        adj[x].push_back({i, a, b});
    }
    
    std::vector<int> ans(n);
    
    std::vector<i64> A(n), B(n), s;
    std::function<void(int)> dfs = [&](int u) {
        s.push_back(B[u]);
        if (u > 0) {
            ans[u] = std::upper_bound(s.begin(), s.end(), A[u]) - s.begin() - 1;
        }
        for (auto [v, a, b] : adj[u]) {
            A[v] = A[u] + a;
            B[v] = B[u] + b;
            dfs(v);
        }
        s.pop_back();
    };
    dfs(0);
    
    for (int i = 1; i < n; i++) {
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