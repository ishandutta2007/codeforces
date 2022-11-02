#include <bits/stdc++.h>

using int64 = long long;

const int N = 60;
const int P = 1000000007;

int n, d[N], s[N];

int64 dp[N][N][N], f[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> d[i];
        s[i] = s[i - 1] + (d[i] == 2);
    }
    dp[0][0][0] = 1;
    for (int j = 0; j <= n; ++j) {
        for (int i = 0; i <= n; ++i) {
            for (int k = 0; k <= n; ++k) {
                int64 o = 0;
                if (j) {
                    if (k >= 2) o = k * (k - 1) / 2 * dp[i][j - 1][k - 2];
                    if (i && k) o += k * i * dp[i - 1][j - 1][k - 1];
                    if (j >= 2 && k) o += k * (j - 1) * dp[i + 1][j - 2][k - 1];
                    if (i >= 2) o += i * (i - 1) / 2 * dp[i - 2][j - 1][k];
                    if (j >= 2) o += i * (j - 1) * dp[i][j - 2][k];
                    if (j >= 3) o += (j - 1) * (j - 2) / 2 * dp[i + 2][j - 3][k];
                    dp[i][j][k] = o % P;
                } else if (i) {
                    if (k) o = k * dp[i - 1][0][k - 1];
                    if (i >= 2) o += (i - 1) * dp[i - 2][0][k];
                    dp[i][j][k] = o % P;
                }
            }
        }
    }
    f[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (j + 1 == i) {
                if (j == d[1]) f[i][j] = 1;
            } else {
                for (int k = 1; k < i - j; ++k) {
                    (f[i][j] += f[i - j][k] * dp[s[i - j] - s[i - j - k]][k - s[i - j] + s[i - j - k]][j]) %= P;
                }
            }
        }
    }
    int64 ans = 0;
    for (int i = 2; i <= n; ++i) (ans += f[n][i] * dp[s[n] - s[n - i]][i - s[n] + s[n - i]][0]) %= P;
    std::cout << ans << std::endl;
    return 0;
}