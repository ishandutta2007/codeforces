#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i < n) dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j] - 1);
            if (j < m) dp[i][j + 1] = std::max(dp[i][j + 1], dp[i][j] - 1);
            if (i < n && j < m && s[i] == t[j]) dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + 2);
            ans = std::max(ans, dp[i][j]);
        }
    }
    std::cout << ans << "\n";
    
    return 0;
}