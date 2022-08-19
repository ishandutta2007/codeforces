#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int P = 998244353, Inv6 = (P + 1) / 6;
int calc(int x, bool deg3 = false) {
    int res = i64(x) * (x + 1) / 2 % P;
    if (deg3) {
        res = (res + i64(x) * (x + 1) % P * (x + 2) % P * Inv6) % P;
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "5\n";
        return 0;
    }
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (1 + i64(dp[i - 1]) * (dp[i - 1] + 3) / 2) % P;
    }
    std::vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = calc(dp[i - 1]);
    }
    int ans = (calc(dp[n - 1], true) - calc(dp[n - 2], true) + P) % P;
    ans = 2 * ans % P;
    ans = (i64(ans) + dp[n - 1] - dp[n - 2] + P) % P;
    for (int i = n; i > 0; i--) {
        dp[i] = (dp[i] - dp[i - 1] + P) % P;
        f[i] = (f[i] - f[i - 1] + P) % P;
    }
    for (int i = 1; i < n; i++) {
        ans = (ans + i64(f[i]) * dp[n - i - 1]) % P;
    }
    std::cout << ans << "\n";
    return 0;
}