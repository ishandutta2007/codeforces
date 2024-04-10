#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.length();
        int dp[4] {};
        for (int i = 0; i < n; ++i) {
            int g[4];
            for (int j = 0; j < 4; ++j) {
                g[j] = n;
            }
            for (int j = 0; j < 4; ++j) {
                g[j >> 1 | 2] = std::min(g[j >> 1 | 2], dp[j] + 1);
                if (((j & 1) == 1 || i < 2 || s[i] != s[i - 2]) && ((j >> 1) == 1 || i < 1 || s[i] != s[i - 1])) {
                    g[j >> 1] = std::min(g[j >> 1], dp[j]);
                }
            }
            for (int j = 0; j < 4; ++j) {
                dp[j] = g[j];
            }
        }
        int ans = n;
        for (int i = 0; i < 4; i++) {
            ans = std::min(ans, dp[i]);
        }
        std::cout << ans << "\n";
    }
    return 0;
}