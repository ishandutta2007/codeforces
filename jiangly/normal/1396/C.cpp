#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, r1, r2, r3, d;
    std::cin >> n >> r1 >> r2 >> r3 >> d;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::vector<int64_t> t1(n), t2(n);
    for (int i = 0; i < n; ++i) {
        t1[i] = 1ll * a[i] * r1 + r3;
        t2[i] = std::min(1ll * (a[i] + 2) * r1, 1ll * r2 + r1);
    }
    std::vector<int64_t> dp(n, 9e18);
    dp[0] = t1[0];
    dp[1] = 3ll * d + t2[0] + t2[1];
    for (int i = 1; i < n; ++i) {
        dp[i] = std::min(dp[i], dp[i - 1] + 3ll * d + t2[i]);
        if (i >= 2)
            dp[i] = std::min(dp[i], dp[i - 2] + 4ll * d + t2[i - 1] + t2[i]);
        dp[i] = std::min(dp[i], dp[i - 1] + d + t1[i]);
    }
    int64_t ans = dp[n - 1], res = t1[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        ans = std::min(ans, dp[i] + res + 1ll * d * (n - 1 - i + n - 1 - i - 1));
        res += t2[i];
    }
    ans = std::min(ans, res + 1ll * d * 2 * (n - 1));
    std::cout << ans << "\n";
    return 0;
}