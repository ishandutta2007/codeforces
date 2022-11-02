#include <bits/stdc++.h>

const int N = 250;
const int M = 28;
const int INF = 1e9;

int dp[2][M * 2 + 1][N][N];

std::string s;

int main() {
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    s += "0";
    for (int k = 0; k <= M << 1; ++k) {
        for (int cp = 0; cp < N; ++cp) {
            for (int cn = 0; cn < N; ++cn) dp[0][k][cp][cn] = INF;
        }
    }
    dp[0][M][N - 1][N - 1] = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int k = 0; k <= M << 1; ++k) {
            for (int cp = 0; cp < N; ++cp) {
                for (int cn = 0; cn < N; ++cn) dp[1][k][cp][cn] = INF;
            }
        }
        for (int k = 0; k <= M << 1; ++k) {
            for (int cp = N - 1; cp >= 0; --cp) {
                for (int cn = N - 1; cn >= 0; --cn) {
                    if (dp[0][k][cp][cn] != INF) {
                        if (cp > 0) {
                            dp[0][k][cp - 1][cn] = std::min(
                                dp[0][k][cp - 1][cn], dp[0][k][cp][cn]);
                        }
                        if (cn > 0) {
                            dp[0][k][cp][cn - 1] = std::min(
                                dp[0][k][cp][cn - 1], dp[0][k][cp][cn]);
                        }
                        int rc = k - M, val = rc + cp - cn, dg = val % 10;
                        if (dg < 0) dg += 10;
                        int e = val / 10;
                        if (val < 0 && dg != 0) --e;
                        if (dg == s[i] - '0') {
                            dp[1][e + M][cp][cn] =
                                std::min(dp[1][e + M][cp][cn],
                                         dp[0][k][cp][cn] + cp + cn);
                        }
                    }
                }
            }
        }
        std::swap(dp[0], dp[1]);
    }
    int ans = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ans = std::min(ans, dp[0][M][i][j]);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}