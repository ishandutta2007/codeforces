#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            std::vector<std::vector<int>> dp(n, std::vector<int>(2, n + 1));
            std::function<void(int, int)> dfs = [&](int u, int p) {
                int t[2][2] = {};
                for (auto v : e[u]) {
                    if (v == p) continue;
                    dfs(v, u);
                    for (int i = 0; i < 2; ++i) {
                        int x = std::min(dp[v][i], dp[v][!i] + 1);
                        for (int j = 0; j < 2; ++j)
                            if (x > t[i][j]) std::swap(x, t[i][j]);
                    }
                }
                if (a[u] != 2 && t[0][0] + t[0][1] <= m) dp[u][0] = t[0][0];
                if (a[u] != 1 && t[1][0] + t[1][1] <= m) dp[u][1] = t[1][0];
            };
            dfs(0, -1);
            if (dp[0][0] > n && dp[0][1] > n)
                l = m + 1;
            else
                r = m;
        }
        std::cout << (l + 1) / 2 + 1 << "\n";
    }

    return 0;
}