#include <iostream>
#include <vector>
constexpr int P = 998244353;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k, m;
    std::cin >> n >> k >> m;
    int ans = 1;
    std::vector<int> l(m), r(m), x(m);
    for (int i = 0; i < m; ++i)
        std::cin >> l[i] >> r[i] >> x[i];
    for (int d = 0; d < k; ++d) {
        std::vector<int> c(n + 2);
        std::vector<int> b(n + 1);
        std::vector<int> dp(n + 2);
        for (int i = 0; i < m; ++i) {
            if (x[i] >> d & 1) {
                ++c[l[i]];
                --c[r[i] + 1];
            } else {
                b[r[i]] = std::max(b[r[i]], l[i]);
            }
        }
        for (int i = 1; i <= n + 1; ++i)
            c[i] += c[i - 1];
        for (int i = 1; i <= n; ++i)
            b[i] = std::max(b[i], b[i - 1]);
        dp[0] = 1;
        for (int i = 1; i <= n + 1; ++i) {
            if (c[i] == 0)
                dp[i] = (dp[i - 1] - (b[i - 1] == 0 ? 0 : dp[b[i - 1] - 1]) + P) % P;
            if (i == n + 1)
                break;
            dp[i] = (dp[i] + dp[i - 1]) % P;
        }
        ans = 1ll * ans * dp[n + 1] % P;
    }
    std::cout << ans << "\n";
    return 0;
}