#include <bits/stdc++.h>
constexpr int inf = 1e9;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    std::vector<char> tp(m);
    std::vector<int> team(m);
    for (int i = 0; i < m; i++) {
        std::cin >> tp[i] >> team[i];
    }
    std::sort(a.begin(), a.end(), std::greater<>());
    std::vector<int> dp(1 << m);
    for (int s = 1; s < (1 << m); s++) {
        int k = m - __builtin_popcount(s);
        if (team[k] == 1) {
            dp[s] = -inf;
        } else {
            dp[s] = inf;
        }
        for (int i = 0; i < m; i++) {
            if (~s >> i & 1) {
                continue;
            }
            if (team[k] == 1) {
                dp[s] = std::max(dp[s], dp[s & ~(1 << i)] + a[i] * (tp[k] == 'p'));
            } else {
                dp[s] = std::min(dp[s], dp[s & ~(1 << i)] - a[i] * (tp[k] == 'p'));
            }
        }
    }
    std::cout << dp[(1 << m) - 1] << "\n";
    return 0;
}