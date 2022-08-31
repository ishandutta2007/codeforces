#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<long long>> a(n, std::vector<long long>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                std::cin >> a[i][j];
        long long ans = -1;
        auto work = [&](long long x) {
            std::vector<std::vector<long long>> dp(n, std::vector<long long>(m, -1));
            if (x > a[0][0])
                return;
            dp[0][0] = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] < x + i + j)
                        dp[i][j] = -1;
                    if (dp[i][j] == -1)
                        continue;
                    dp[i][j] += a[i][j] - x - i - j;
                    if (i + 1 < n && (dp[i + 1][j] == -1 || dp[i + 1][j] > dp[i][j]))
                        dp[i + 1][j] = dp[i][j];
                    if (j + 1 < m && (dp[i][j + 1] == -1 || dp[i][j + 1] > dp[i][j]))
                        dp[i][j + 1] = dp[i][j];
                }
            }
            if (dp[n - 1][m - 1] != -1 && (ans == -1 || ans > dp[n - 1][m - 1]))
                ans = dp[n - 1][m - 1];
        };
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                work(a[i][j] - i - j);
        std::cout << ans << "\n";
    }
    return 0;
}