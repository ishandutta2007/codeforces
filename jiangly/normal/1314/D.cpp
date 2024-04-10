#include <iostream>
#include <vector>
#include <chrono>
#include <random>
int n, k;
std::vector<int> t;
std::vector<std::vector<int>> a, dp;
auto now = std::chrono::steady_clock::now();
std::mt19937 rnd(now.time_since_epoch().count());
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    a.assign(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> a[i][j];
    int ans = std::numeric_limits<int>::max();
    t.resize(n);
    while ((std::chrono::steady_clock::now() - now).count() < 2500000000) {
        for (int i = 0; i < n; ++i)
            t[i] = rnd() % 2;
        dp.assign(k + 1, std::vector<int>(n, -1));
        dp[0][0] = 0;
        for (int i = 0; i < k; ++i)
            for (int u = 0; u < n; ++u)
                if (dp[i][u] != -1)
                    for (int v = 0; v < n; ++v)
                        if (t[u] != t[v] && (dp[i + 1][v] == -1 || dp[i + 1][v] > dp[i][u] + a[u][v]))
                            dp[i + 1][v] = dp[i][u] + a[u][v];
        if (dp[k][0] != -1)
            ans = std::min(ans, dp[k][0]);
    }
    std::cout << ans << "\n";
    return 0;
}