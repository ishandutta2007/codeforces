#include <iostream>
#include <vector>
#include <algorithm>
int n, h, l, r;
std::vector<std::vector<int>> dp;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> h >> l >> r;
    dp.resize(2, std::vector<int>(h, -1));
    dp[0][0] = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        cur ^= 1;
        std::fill(dp[cur].begin(), dp[cur].end(), -1);
        for (int j = 0; j < h; ++j) {
            if (dp[cur ^ 1][j] != -1) {
                for (int x = a - 1; x <= a; ++x) {
                    int k = (j + x) % h;
                    dp[cur][k] = std::max(dp[cur][k], dp[cur ^ 1][j] + (l <= k && k <= r));
                }
            }
        }
    }
    std::cout << *std::max_element(dp[cur].begin(), dp[cur].end()) << "\n";
    return 0;
}