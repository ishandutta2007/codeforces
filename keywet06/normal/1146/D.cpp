#include <bits/stdc++.h>
using int64 = long long;
const int N = 1000005;
int m, a, b, l, r, u, t = 1, i, g, e;
int dp[N], que[2 * N];
int64 ans;
inline void update(int max) {
    while (l <= r) {
        u = que[l++];
        if (u - b >= 0 && !dp[u - b]) dp[u - b] = 1, que[++r] = u - b, ++t;
        if (u + a <= max && !dp[u + a]) dp[u + a] = 1, que[++r] = u + a, ++t;
    }
}
int main() {
    std::cin >> m >> a >> b;
    g = std::__gcd(a, b);
    e = m;
    m = m / g;
    a /= g, b /= g;
    dp[0] = 1;
    for (i = 1; i <= m; ++i) {
        ans += t;
        if (i - a < 0 || !dp[i - a]) continue;
        que[++r] = i - a;
        update(i);
        if (t > i) break;
    }
    ans += t;
    if (t > i) {
        ans += 1ll * (m + 1) * (m + 2) / 2 - 1ll * t * (t + 1) / 2;
        ans *= g;
        ans -= (m + 1) * ((m + 1) * g - e - 1);
    } else {
        ans *= g;
        ans -= t * ((m + 1) * g - e - 1);
    }
    std::cout << ans << std::endl;
    return 0;
}