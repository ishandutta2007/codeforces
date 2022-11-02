#include <bits/stdc++.h>

const int MIN = std::numeric_limits<int>::min();

int n, m;

std::vector<int> l, cost, c, sum, cto;
std::vector<std::vector<int>> dp;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    l.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
        --l[i];
    }
    cost.resize(n);
    for (int i = 0; i < n; ++i) std::cin >> cost[i];
    c.resize(n + m);
    for (int i = 0; i < n + m; ++i) std::cin >> c[i];
    dp.resize(m);
    dp[0].resize(1);
    sum.resize(n + m + 1);
    for (int i = 0; i < n + m; ++i) sum[i + 1] = sum[i] + c[i];
    cto.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        while (i & (1 << cto[i])) ++cto[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = l[i]; j >= 0; --j) {
            for (int k = dp[j].size() - 1; k >= 0; --k) {
                if (dp[j][k] == MIN) continue;
                int nk = l[i] - j > 30 ? 0 : (k >> (l[i] - j));
                if (int(dp[l[i]].size()) <= nk + 1) {
                    dp[l[i]].resize(nk + 2, MIN);
                }
                int d = cto[nk];
                dp[l[i]][nk + 1] = std::max(
                    dp[l[i]][nk + 1],
                    dp[j][k] - cost[i] + sum[l[i] + d + 1] - sum[l[i]]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int v : dp[i]) ans = std::max(ans, v);
    }
    std::cout << ans << "\n";
    return 0;
}