#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int dp[1001] = {};
    dp[0] = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (i % 2 == 1) {
            dp[i] = i - dp[i - 1];
        } else {
            dp[i] = i - std::min(dp[i - 1], dp[i / 2]);
        }
    }
    
    int t;
    std::cin >> t;
    while (t--) {
        int64_t n;
        std::cin >> n;
        int64_t ans = 0;
        int cur = 0;
        while (n > 0) {
            if (n <= 1000) {
                if (cur == 0) ans += dp[n];
                else ans += n - dp[n];
                break;
            }
            int64_t take = (n % 2 == 1 || n % 4 == 0) ? 1 : n / 2;
            if (cur == 0) ans += take;
            n -= take;
            cur ^= 1;
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}