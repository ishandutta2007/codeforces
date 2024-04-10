#include <bits/stdc++.h>
constexpr int P = 1000000007;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int dp[4] = {};
    dp[0] = 1;
    for (auto c : s) {
        if (c == 'c') dp[3] = (dp[3] + dp[2]) % P;
        else if (c == 'b') dp[2] = (dp[2] + dp[1]) % P;
        else if (c == 'a') dp[1] = (dp[1] + dp[0]) % P;
        else {
            for (int i = 3; i > 0; --i) dp[i] = (3ll * dp[i] + dp[i - 1]) % P;
            dp[0] = 3ll * dp[0] % P;
        }
    }
    std::cout << dp[3] << "\n";
    
    return 0;
}