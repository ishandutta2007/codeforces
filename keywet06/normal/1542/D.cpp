#include <bits/stdc++.h>

using int64 = long long;

const int N = 505;
const int P = 998244353;

int n, a[N];

int64 ans;
int64 dp[N][N];

std::string s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> s;
        s[0] == '-' ? void(a[i] = -1) : void(std::cin >> a[i]);
    }
    for (int p = 1; p <= n; ++p) {
        if (a[p] < 0) continue;
        int x = a[p];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == p) {
                memcpy(dp[i], dp[i - 1], sizeof dp[i]);
                continue;
            }
            for (int j = 0; j <= n; ++j) {
                if (a[i] < 0) {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % P;
                    if (j == 0 && i < p) (dp[i][j] += dp[i - 1][j]) %= P;
                } else if (a[i] < x || (a[i] == x && i < p)) {
                    dp[i][j] = dp[i - 1][j];
                    if (j > 0) (dp[i][j] += dp[i - 1][j - 1]) %= P;
                } else
                    dp[i][j] = 2 * dp[i - 1][j] % P;
            }
        }
        int64 sum = 0;
        for (int j = 0; j <= n; ++j) (sum += dp[n][j]) %= P;
        (ans += sum * x % P) %= P;
    }
    std::cout << ans << std::endl;
    return 0;
}