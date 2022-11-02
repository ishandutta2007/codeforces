#include <bits/stdc++.h>

int n, k;

std::vector<std::vector<int>> dp[2][2];

void checkMax(int &a, int b) { a = std::max(a, b); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[i][j].resize(n + 1);
            for (int k = 0; k <= n; ++k) {
                dp[i][j][k].assign(1 << (n - k), (i | j) ? -1 : 0);
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        int a;
        std::cin >> a, --a;
        dp[1][0][0][a] = 0;
    }
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        if (dp[1][0][0][2 * i] != -1 && dp[1][0][0][2 * i + 1] != -1) {
            dp[1][1][1][i] = 1;
        }
        if (dp[1][0][0][2 * i] != -1 || dp[1][0][0][2 * i + 1] != -1) {
            dp[1][0][1][i] = dp[0][1][1][i] = 1;
        }
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < (1 << (n - i)); ++j) {
            for (int flu = 0; flu < 2; ++flu) {
                for (int fll = 0; fll < 2; ++fll) {
                    if (dp[flu][fll][i - 1][2 * j] != -1) {
                        for (int fru = 0; fru < 2; ++fru) {
                            for (int frl = 0; frl < 2; ++frl) {
                                if (dp[fru][frl][i - 1][2 * j + 1] != -1) {
                                    for (int ru = 0; ru < 2; ++ru) {
                                        for (int rl1 = 0; rl1 < 2; ++rl1) {
                                            for (int rl2 = 0; rl2 < 2; ++rl2) {
                                                checkMax(
                                                    dp[ru ? flu : fru]
                                                      [rl2   ? (ru ? fru : flu)
                                                       : rl1 ? fll
                                                             : frl][i][j],
                                                    dp[flu][fll][i - 1][2 * j] +
                                                        dp[fru][frl][i - 1]
                                                          [2 * j + 1] +
                                                        (flu | fru) +
                                                        (fll | frl) +
                                                        ((rl1 ? fll : frl) |
                                                         (ru ? fru : flu)));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int fu = 0; fu < 2; ++fu) {
        for (int fl = 0; fl < 2; ++fl) {
            checkMax(ans, dp[fu][fl][n][0] + (fu | fl));
        }
    }
    std::cout << ans << "\n";
    return 0;
}