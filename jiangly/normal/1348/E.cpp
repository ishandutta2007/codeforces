#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<long long, int>> dp(k, std::make_pair(-1e18, 0));
    dp[0] = std::make_pair(0, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::vector<std::pair<long long, int>> newDp(k, std::make_pair(-1e18, 0));
        for (int x = 0; x < k; ++x) {
            for (int t = 0; t <= a && t < k; ++t) {
                int ra = a - t;
                int rb = (k - ra % k) % k;
                int p = b - rb;
                if (rb > b)
                    continue;
                newDp[(x + t) % k] = std::max(newDp[(x + t) % k], std::make_pair(dp[x].first + (x + t >= k) + (dp[x].second + p + ra + rb) / k, (dp[x].second + p) % k));
            }
        }
        dp = newDp;
    }
    std::cout << std::max_element(dp.begin(), dp.end()) -> first << "\n";
    return 0;
}