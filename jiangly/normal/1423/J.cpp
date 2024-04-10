#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
constexpr int P = 1000000007;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int64_t n;
        std::cin >> n;
        int dp[7] = {};
        dp[0] = 1;
        for (int i = 59; i >= 0; --i) {
            int g[14] = {};
            for (int j = 0; j < 7; ++j) g[2 * j + (n >> i & 1)] = dp[j];
            for (int j = 1; j < 14; ++j) {
                g[j] += g[j - 1];
                if (g[j] >= P) g[j] -= P;
            }
            for (int j = 0; j < 7; ++j) {
                dp[j] = g[j + 7];
                if (j > 0) dp[j] += P - g[j - 1];
                if (dp[j] >= P) dp[j] -= P;
            }
        }
        std::cout << dp[0] << "\n";
    }
    return 0;
}