#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::vector<int> a, dp;
std::vector<std::vector<int>> f;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    f.assign(n + 1, std::vector<int>(n + 1, -1));
    for (int i = 0; i < n; ++i)
        f[i][i + 1] = a[i];
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len;
            for (int m = l + 1; m < r; ++m)
                if (f[l][m] != -1 && f[l][m] == f[m][r])
                    f[l][r] = f[l][m] + 1;
        }
    }
    dp.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = i;
        for (int j = 0; j < i; ++j)
            if (f[j][i] != -1)
                dp[i] = std::min(dp[i], dp[j] + 1);
    }
    std::cout << dp[n] << "\n";
    return 0;
}