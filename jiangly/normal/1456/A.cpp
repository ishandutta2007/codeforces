#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, p, k;
        std::cin >> n >> p >> k;
        --p;
        std::string s;
        std::cin >> s;
        int x, y;
        std::cin >> x >> y;
        
        int ans = 1e9;
        
        std::vector<int> dp(n);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = (s[i] == '0' ? x : 0);
            if (i + k < n) dp[i] += dp[i + k];
        }
        for (int i = p; i < n; ++i) ans = std::min(ans, dp[i] + (i - p) * y);
        
        std::cout << ans << "\n";
    }
    
    return 0;
}