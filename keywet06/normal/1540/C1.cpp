#include <bits/stdc++.h>

namespace oct {

template <typename _Tp>
_Tp &mini(_Tp &x, _Tp y) {
    return x = std::min(x, y);
}
template <typename _Tp>
_Tp &maxi(_Tp &x, _Tp y) {
    return x = std::max(x, y);
}

#if __cplusplus >= 201103L

template <typename _Tp>
_Tp &mini(_Tp &x, std::initializer_list<_Tp> il) {
    return x = std::min(x, std::min(il));
}

template <typename _Tp>
_Tp &maxi(_Tp &x, std::initializer_list<_Tp> il) {
    return x = std::max(x, std::max(il));
}

#endif

}  // namespace oct

using int64 = long long;

const int P = 1000000007;
const int N = 105;
const int M = N * N;

int n, xl, xr, q, x, ps;
int sb[N], c[N], b[N];

int64 dp[N][M], f[N][M];

std::map<int, int> map;

int solve(int x) {
    memset(dp, 0, sizeof(dp));
    memset(f, 0, sizeof(f));
    dp[0][0] = 1;
    for (int i = 0; i < M; ++i) f[0][i] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = std::max(i * x + sb[i], 0); j < M; ++j) {
            dp[i][j] = f[i - 1][j];
            if (j - c[i] > 0) dp[i][j] -= f[i - 1][j - c[i] - 1];
            f[i][j] = j ? f[i][j - 1] + dp[i][j] : dp[i][j];
            dp[i][j] %= P, f[i][j] %= P;
        }
    }
    int64 ans = 0;
    for (int i = 0; i < M; ++i) ans += dp[n][i];
    return (ans % P + P) % P;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    ps = 1;
    for (int i = 1; i <= n; ++i) std::cin >> c[i], ps = ps * (c[i] + 1ll) % P;
    for (int i = 1; i < n; ++i) std::cin >> b[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) sb[i] += (i - j) * b[j];
    }
    xl = xr = P;
    for (int i = 1; i <= n; ++i) {
        oct::mini(xl, -((sb[i] - 1) / i + 1));
        oct::mini(xr, (n * N - sb[i] - 1) / i + 1);
    }
    for (int i = xl; i <= xr; ++i) map[i] = solve(i);
    std::cin >> q;
    while (q--) {
        std::cin >> x;
        if (x < xl) std::cout << ps << '\n';
        if (x > xr) std::cout << 0 << '\n';
        if (x >= xl && x <= xr) std::cout << map[x] << '\n';
    }
    return 0;
}