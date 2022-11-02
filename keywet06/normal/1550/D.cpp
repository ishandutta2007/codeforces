#include <bits/stdc++.h>

using int64 = long long;

const int64 P = 1000000007;
const int N = 200005;

int T, n, x, y, c, tx, ty;

int64 ans;
int64 pre[N], cre[N];

inline int64 power(int64 x, int y) {
    return y ? power(x * x % P, y / 2) * (y & 1 ? x : 1) % P : 1;
}

inline int64 C(int m, int n) {
    return m >= n && n >= 0 ? pre[m] * cre[n] % P * cre[m - n] % P : 0;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    pre[0] = 1;
    for (int i = 1; i < N; ++i) pre[i] = pre[i - 1] * i % P;
    cre[N - 1] = power(pre[N - 1], P - 2);
    for (int i = N - 2; ~i; --i) cre[i] = cre[i + 1] * (i + 1) % P;
    while (T--) {
        std::cin >> n >> x >> y;
        c = std::min(1 - x, y - n);
        ans = (n & 1 ? C(n, n / 2) + C(n, n / 2 + 1) : C(n, n / 2)) * c % P;
        while (++c) {
            tx = std::max(x + c, 1), ty = std::min(y - c, n);
            if (tx > n || ty < 0) break;
            ans = (ans + C(ty - tx + 1, n / 2 - tx + 1)) % P;
            if (n & 1) ans = (ans + C(ty - tx + 1, n / 2 - tx + 2)) % P;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}