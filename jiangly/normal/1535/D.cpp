#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int k;
    std::cin >> k;
    int n = 1 << k;
    std::string s;
    std::cin >> s;
    std::vector<int> dp(2 * n);
    for (int i = 0; i < n; i++) {
        dp[i + n] = 1;
    }
    for (int i = n - 1; i; i--) {
        dp[i] = (s[n - 1 - i] == '0') ? dp[2 * i + 1] : (s[n - 1 - i] == '1') ? dp[2 * i] : dp[2 * i] + dp[2 * i + 1];
    }
    int q;
    std::cin >> q;
    while (q--) {
        int p;
        char c;
        std::cin >> p >> c;
        p--;
        s[p] = c;
        for (int u = n - 1 - p; u; u /= 2) {
            dp[u] = (s[n - 1 - u] == '0') ? dp[2 * u + 1] : (s[n - 1 - u] == '1') ? dp[2 * u] : dp[2 * u] + dp[2 * u + 1];
        }
        std::cout << dp[1] << "\n";
    }
    return 0;
}