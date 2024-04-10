#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> t(n);
        for (int i = 0; i < n; ++i) std::cin >> t[i];
        std::sort(t.begin(), t.end());
        std::vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= 2 * n; ++i)
            for (int j = n; j > 0; --j) dp[j] = std::min(dp[j], dp[j - 1] + std::abs(t[j - 1] - i));
        std::cout << dp[n] << "\n";
    }
    
    return 0;
}