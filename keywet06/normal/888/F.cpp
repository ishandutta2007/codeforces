#include <bits/stdc++.h>

using int64 = long long;

const int P = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) std::cin >> a[i][j];
    }
    std::vector<std::vector<int64>> dp(n + 1, std::vector<int64>(n + 1));
    std::vector<std::vector<int64>> dm(n + 1, std::vector<int64>(n + 1));
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;
            if (len == 1) {
                dp[l][r] = 1, dm[l][r] = 1;
            } else {
                if (len == 2) {
                    dm[l][r] = 1;
                } else {
                    int64 Com = 0;
                    for (int j = l + 1; j < r; ++j) {
                        if (a[l][j]) Com = (Com + dm[j][r] * dm[l][j]) % P;
                    }
                    Com = (Com + dp[l + 1][r]) % P;
                    dm[l][r] = Com;
                }
                int64 Com = 0;
                for (int j = l + 1; j <= r; ++j) {
                    if (a[l][j]) {
                        if (j - l == 1) {
                            Com = (Com + dp[j][r] * 1) % P;
                        } else {
                            Com = (Com + dp[j][r] * (dm[l][j])) % P;
                        }
                    }
                }
                dp[l][r] = Com;
            }
        }
    }
    std::cout << dp[0][n - 1] << std::endl;
    return 0;
}