#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int P = 998244353;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    int s = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i] + s) % P;
        for (int j = 2 * i; j <= n; j += i) {
            dp[j] = (dp[j] + 1) % P;
        }
        s = (dp[i] + s) % P;
    }
    std::cout << dp[n] << "\n";
    return 0;
}