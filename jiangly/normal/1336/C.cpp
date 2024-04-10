#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
constexpr int P = 998244353;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    std::string t;
    std::cin >> t;
    int n = s.length(), m = t.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = m; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= m && j <= n - i - 1; ++j) {
            if (j == m) {
                dp[i][j] = (dp[i][j] + dp[i + 1][j]) % P;
            } else if (s[i] == t[j]) {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i + 1][j]) % P;
            }
            if (i + j >= m || s[i] == t[i + j])
                dp[i][j] = (dp[i][j] + dp[i + 1][j]) % P;
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; ++i)
        ans = (ans + dp[0][i]) % P;
    std::cout << ans << "\n";
    return 0;
}