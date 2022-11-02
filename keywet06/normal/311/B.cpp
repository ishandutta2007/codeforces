#include <bits/stdc++.h>

#define Deb std::cerr
#define Debug Deb << "Debug(" << __LINE__ << "): "

using int64 = long long;

const int N = 200005;

int n, m, p, l, r, mid, h, t, x, y;
int q[N];

int64 d[N], pre[N], dp[N], g[N], a[N], ndp[N];

inline bool better(int x, int y, int64 c) {
    return g[x] - g[y] < (x - y) * c;
}

inline bool better(int x, int y, int z) {
    return (g[x] - g[y]) * (y - z) < (g[y] - g[z]) * (x - y);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> p;
    for (int i = 2; i <= n; ++i) std::cin >> d[i], d[i] += d[i - 1];
    for (int i = 1; i <= m; ++i) std::cin >> x >> y, a[i] = y - d[x];
    std::sort(a + 1, a + m + 1);
    // Debug << "a = {";
    // for (int i = 1; i <= m; ++i) Deb << a[i] << ", ";
    // Deb << "...};" << std::endl;
    for (int i = 1; i <= m; ++i) pre[i] = pre[i - 1] + a[i];
    memset(dp, 0x3f, sizeof(dp)), dp[0] = 0;
    for (int i = 1; i <= m; ++i) dp[i] /= N;
    while (p--) {
        h = t = 0;
        for (int i = 0; i <= m; ++i) g[i] = dp[i] + pre[i];
        for (int i = 1; i <= m; ++i) {
            while (h != t && !better(q[h], q[h + 1], a[i])) ++h;
            dp[i] = (i - q[h]) * a[i] - pre[i] + g[q[h]];
            while (h < t && !better(q[t - 1], q[t], i)) --t;
            q[++t] = i;
        }
        // Debug << "dp = {";
        // for (int i = 1; i <= m; ++i) Deb << dp[i] << ", ";
        // Deb << "...};" << std::endl;
    }
    std::cout << dp[m] << std::endl;
    return 0;
}