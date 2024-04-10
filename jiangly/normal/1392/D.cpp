#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int ans = n;
        for (int k = 0; k < 4; ++k) {
            std::vector<int> dp(n + 1, n);
            dp[0] = 0;
            for (int i = 0; i < n; ++i) {
                if (i + 2 <= n)
                    dp[i + 2] = std::min(dp[i + 2], dp[i] + (s[i] != 'R') + (s[i + 1] != 'L'));
                if (i + 3 <= n)
                    dp[i + 3] = std::min(dp[i + 3], dp[i] + (s[i] != 'R') + (s[i + 1] != 'R') + (s[i + 2] != 'L'));
                if (i + 3 <= n)
                    dp[i + 3] = std::min(dp[i + 3], dp[i] + (s[i] != 'R') + (s[i + 1] != 'L') + (s[i + 2] != 'L'));
                if (i + 4 <= n)
                    dp[i + 4] = std::min(dp[i + 4], dp[i] + (s[i] != 'R') + (s[i + 1] != 'R') + (s[i + 2] != 'L') + (s[i + 3] != 'L'));
            }
            s = s.substr(1) + s[0];
            ans = std::min(ans, dp[n]);
        }
        std::cout << ans << "\n";
    }
    return 0;
}