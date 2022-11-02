#include <bits/stdc++.h>

using int64 = long long;

const int P = int(1e9) + 7;
const int N = 2005;

int n, m, s;
int dp[N][N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    s = std::max(n, m);
    for (int i = 1; i <= s; i++) {
        int ds1 = 0, ds2 = 0;
        for (int j = 2; j <= s; j++) {
            ds1 += dp[i - 1][j];
            ds2 += 1ll * dp[i - 1][j] * (j - 1) % P;
            ds1 %= P, ds2 %= P;
            dp[i][j] = P + 1 + 1ll * ds1 * j % P - ds2;
            dp[i][j] %= P;
        }
    }
    int64 ret = 0;
    for (int i = 1; i <= n; i++) {
        int ds1 = 0, ds2 = 0;
        for (int j = 2; j <= m; j++) {
            int le = dp[i][j];
            int ri = 1 + 1ll * ds1 * j % P + P - ds2;
            ri %= P;
            ds1 += dp[n - i][j];
            ds2 += 1ll * dp[n - i][j] * (j - 1) % P;
            ds1 %= P;
            ds2 %= P;
            ret += (1ll * le * ri % P) * (m - j + 1) % P;
            ret %= P;
        }
    }
    std::cout << ret << '\n';
    return 0;
}