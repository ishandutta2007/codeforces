#include <iostream>
#include <vector>
#include <algorithm>
constexpr int INF = 1'000'000'000;
int n;
std::vector<std::vector<std::vector<int>>> dp;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    int even = n / 2;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    dp.resize(n);
    for (auto &v : dp)
        v.assign(even + 1, std::vector<int>(2, INF));
    if (even > 0 && (a[0] == 0 || a[0] % 2 == 0))
        dp[0][even - 1][0] = 0;
    if (a[0] == 0 || a[0] % 2 == 1)
        dp[0][even][1] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= even; ++j) {
            for (int x = 0; x < 2; ++x) {
                if (j > 0 && (a[i] == 0 || a[i] % 2 == 0))
                    dp[i][j - 1][0] = std::min(dp[i][j - 1][0], dp[i - 1][j][x] + (x == 1));
                if (j < n - i && (a[i] == 0 || a[i] % 2 == 1))
                    dp[i][j][1] = std::min(dp[i][j][1], dp[i - 1][j][x] + (x == 0));
            }
        }
    }
    std::cout << std::min(dp[n - 1][0][0], dp[n - 1][0][1]) << "\n";
    return 0;
}