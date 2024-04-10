#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        std::vector<int> dp(n);
        std::function<void(int, int, int)> dfs = [&](int u, int p, int k) {
            int cnt = 0, mn = n + 1;
            for (auto v : e[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u, k);
                if (dp[v] >= k) {
                    dp[u] = n;
                    return;
                }
                if (dp[v] == k - 1) {
                    ++cnt;
                } else {
                    mn = std::min(mn, dp[v]);
                }
            }
            if (cnt > 1) {
                dp[u] = n;
            } else if (cnt > 0) {
                dp[u] = k;
            } else if (mn > n) {
                dp[u] = 0;
            } else {
                dp[u] = std::min(n, mn + 1);
            }
        };
        int l = 1, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            dfs(0, -1, m);
            if (dp[0] <= m) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        std::cout << l << "\n";
    }
    
    return 0;
}