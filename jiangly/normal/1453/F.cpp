#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 1e9));
        dp[n - 1][n - 1] = 0;
        std::vector<int> b(n);
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j <= i + a[i]; ++j) {
                dp[i][j - 1] = dp[j][i + a[i]] + b[j];
                ++b[j];
            }
            for (int j = n - 2; j >= i; --j) {
                dp[i][j] = std::min(dp[i][j], dp[i][j + 1]);
            }
        }
        std::cout << dp[0][0] << "\n";
    }
    
    return 0;
}