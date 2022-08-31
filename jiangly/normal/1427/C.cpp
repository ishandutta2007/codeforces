#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int r, n;
    std::cin >> r >> n;
    int mx = -1e9, ans = 0;
    std::vector<int> x(n + 1), y(n + 1), t(n + 1), dp(n + 1);
    x[0] = y[0] = 1;
    for (int i = 1; i <= n; ++i) {
        std::cin >> t[i] >> x[i] >> y[i];
        if (i >= 2 * r) mx = std::max(mx, dp[i - 2 * r]);
        dp[i] = mx;
        for (int j = std::max(0, i - 2 * r); j < i; ++j)
            if (std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]) <= t[i] - t[j]) dp[i] = std::max(dp[i], dp[j]);
        ++dp[i];
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << "\n";
    
    return 0;
}