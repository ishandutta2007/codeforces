#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int64_t> t(n + 1), x(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> t[i] >> x[i];
    std::vector<bool> ok(n + 1);
    std::vector<int64_t> dp(n + 1, 1e9 + 1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (ok[i] && i + 2 <= n) {
            int64_t val = std::max(t[i + 1], t[i] + std::abs(x[i] - x[i + 2]));
            if (val <= t[i + 2]) dp[i + 2] = std::min(dp[i + 2], val);
            for (int j = i + 3; j <= n; ++j) {
                if (j >= i + 4 &&
                    t[j - 1] - t[j - 2] < std::abs(x[j - 1] - x[j - 2])) {
                    break;
                }
                int64_t val = std::max(t[i] + std::abs(x[i] - x[j]), t[i + 1]) +
                              std::abs(x[j] - x[i + 2]);
                if (val <= t[i + 2]) ok[j - 1] = true;
            }
        }
        if (dp[i] <= 1e9) {
            int64_t val = std::max(t[i], dp[i] + std::abs(x[i] - x[i + 1]));
            if (val <= t[i + 1]) dp[i + 1] = std::min(dp[i + 1], val);
            for (int j = i + 2; j <= n; ++j) {
                if (j >= i + 3 &&
                    t[j - 1] - t[j - 2] < std::abs(x[j - 1] - x[j - 2])) {
                    break;
                }
                int64_t val = std::max(t[i], dp[i] + std::abs(x[i] - x[j])) +
                              std::abs(x[j] - x[i + 1]);
                if (val <= t[i + 1]) ok[j - 1] = true;
            }
        }
    }
    if (ok[n - 1] || dp[n] <= 1e9) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}