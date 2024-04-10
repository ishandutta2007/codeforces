#include <bits/stdc++.h>

#define Deb std::cerr
#define Debug Deb << "Debug(" << __LINE__ << "): "
#define fi first
#define se second
#define mkp std::make_pair

using int32 = int;
using int64 = long long;
using i3 = int32;
using i4 = int64;
using pi33 = std::pair<i3, i3>;
using pi34 = std::pair<i3, i4>;
using pi43 = std::pair<i4, i3>;
using pi44 = std::pair<i4, i4>;

const int B = 2;
const int N = 1000005;
const int P = 998244353;

int n, m, d, x, y, z, D, M, c;
int l[N], r[N], p[N], vis[N], e[N];

int64 ans, sum;
int64 dp[N][B];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 2; i <= m; i++) {
        if (!vis[i]) p[++p[0]] = i;
        for (int j = 1; j <= p[0] && i * p[j] <= m; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
    for (int i = 1; i <= n; ++i) std::cin >> l[i] >> r[i];
    e[1] = 1;
    for (int i = 1; i <= m; ++i) {
        if (!vis[i]) {
            e[i] = i == 1 ? 1 : -1;
        } else {
            if (!e[i / vis[i]] || i / vis[i] % vis[i] == 0) continue;
            e[i] = -e[i / vis[i]];
        }
        M = m / i, x = i;
        for (int i = 1; i <= n; ++i) M -= (l[i] - 1) / x;
        for (int i = 0; i <= M; ++i) dp[i][c] = 0;
        dp[0][c] = 1;
        for (int i = 1; i <= n; ++i) {
            D = r[i] / x - (l[i] - 1) / x;
            for (int k = 1; k <= M; ++k) {
                dp[k][c] = (dp[k - 1][c] + dp[k][c]) % P;
            }
            for (int k = 0; k <= M; ++k) {
                dp[k][!c] = dp[k - 1][c];
                if (k > D) dp[k][!c] -= dp[k - D - 1][c];
            }
            c ^= 1;
            // std::cout << M << std::endl;
            // for (int k = 0; k <= M; ++k) std::cout << dp[k][c] << ' ';
            // std::cout << std::endl;
        }
        sum = 0;
        for (int i = 0; i <= M; ++i) sum += dp[i][c];
        ans += (sum * e[i] % P + P) % P;
        // std::cout << i << ": " << sum << std::endl;
    }
    std::cout << ans % P << std::endl;
    return 0;
}