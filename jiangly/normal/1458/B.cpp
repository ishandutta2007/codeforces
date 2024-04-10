#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdint>
#include <tuple>
#include <queue>
#include <complex>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <functional>

using i64 = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];
        sum += b[i];
    }
    
    int dp[10001][101] {};
    for (int i = 0; i <= 10000; ++i) {
        for (int j = 0; j <= 100; ++j) {
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 10000; j >= a[i]; --j) {
            for (int k = n; k > 0; --k) {
                dp[j][k] = std::max(dp[j][k], dp[j - a[i]][k - 1] + b[i]);
            }
        }
    }
    
    std::cout << std::fixed << std::setprecision(10);
    
    for (int i = 1; i <= n; ++i) {
        double ans = 0;
        for (int j = 0; j <= 10000; ++j) {
            ans = std::max(ans, std::min<double>(j, dp[j][i] + 0.5 * (sum - dp[j][i])));
        }
        std::cout << ans << " \n"[i == n];
    }
    
    return 0;
}