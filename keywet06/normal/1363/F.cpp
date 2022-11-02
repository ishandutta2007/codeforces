#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s, t;
        std::cin >> s >> t;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
        std::vector<int> a(n + 1);
        int cs[26] = {}, ct[26] = {};
        for (int i = 0, j = 0; i <= n; ++i) {
            while (j <= n && [&]() {
                for (int k = 0; k < 26; ++k)
                    if (ct[k] < cs[k]) return true;
                return false;
            }()) {
                if (j < n) ++ct[t[j] - 'a'];
                ++j;
            }
            a[i] = j;
            if (i < n) ++cs[s[i] - 'a'];
        }
        if (a[n] > n) {
            std::cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i < n) dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
                if (j < n) dp[i][j + 1] = std::max(dp[i][j + 1], dp[i][j]);
                if (i < n && j < n && s[i] == t[j] && j >= a[i]) {
                    dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + 1);
                }
            }
        }
        std::cout << n - dp[n][n] << "\n";
    }
    return 0;
}