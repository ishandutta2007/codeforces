#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k, z;
        std::cin >> n >> k >> z;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(z + 1, -1e9));
        dp[0][0] = a[0];
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j <= z && 2 * j <= i; ++j) {
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j] + a[i - 2 * j + 1]);
                if (j < z && i + 2 <= k)
                    dp[i + 2][j + 1] = std::max(dp[i + 2][j + 1], dp[i][j] + a[i - 2 * j + 1] + a[i - 2 * j]);
            }
        }
        int ans = 0;
        for (int i = 0; i <= z; ++i)
            ans = std::max(ans, dp[k][i]);
        std::cout << ans << "\n";
    }
    return 0;
}