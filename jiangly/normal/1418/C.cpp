#include <bits/stdc++.h>

constexpr int N = 2e5;

int a[N];
int dp[N + 1][2];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        
        for (int i = 0; i <= n; ++i)
            dp[i][0] = dp[i][1] = n;
        dp[0][1] = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c < 2; ++c) {
                dp[i + 1][!c] = std::min(dp[i + 1][!c], dp[i][c] + c * a[i]);
                if (i + 2 <= n)
                    dp[i + 2][!c] = std::min(dp[i + 2][!c], dp[i][c] + c * (a[i] + a[i + 1]));
            }
        }
        
        std::cout << std::min(dp[n][0], dp[n][1]) << "\n";
    }
    
    return 0;
}