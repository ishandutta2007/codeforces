#include <bits/stdc++.h>

constexpr int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int dp[2] = {1, 0};
    for (int i = 1; i < n; ++i) dp[i & 1] = (dp[i & 1] + dp[~i & 1]) % P;
    
    int ans = dp[~n & 1];
    for (int i = 0; i < n; ++i) ans = int64_t(ans) * (P + 1) / 2 % P;
    
    std::cout << ans << "\n";
    
    return 0;
}