#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    auto v = a;
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    int m = v.size();
    std::vector<std::vector<int>> dp(2, std::vector<int>(m, n));
    dp[0][0] = 0;
    int cur = 0;
    for (int i = 1; i <= n + 1; ++i) {
        auto suf = dp[cur];
        for (int i = m - 2; i >= 0; --i)
            suf[i] = std::min(suf[i], suf[i + 1]);
        cur ^= 1;
        std::fill(dp[cur].begin(), dp[cur].end(), n);
        for (int j = 0, pre = n; j < m; ++j) {
            pre = std::min(pre, dp[!cur][j] - v[j]);
            if (v[j] <= a[i])
                dp[cur][j] = std::min(dp[cur][j], std::min(pre + v[j], suf[j]) + (v[j] < a[i]));
        }
    }
    std::cout << dp[cur][0] << "\n";
    return 0;
}