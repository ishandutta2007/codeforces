#include <bits/stdc++.h>

const int C = 25;
const int N = 100005;

int n, l, r;
int x[N], w[N], u[N];
int f[N][C], g[N][C];

inline int Min(int l, int r) {
    int k = u[r - l + 1];
    return std::min(f[l][k], f[r - (1 << k) + 1][k]);
}

inline int Max(int l, int r) {
    int k = u[r - l + 1];
    return std::max(g[l][k], g[r - (1 << k) + 1][k]);
}

inline bool check(int p) {
    int i, k, l, r, m, a, b;
    for (i = 1; i <= n; ++i) {
        for (l = i, r = n; l < r;) {
            m = (l + r + 1 >> 1);
            a = Min(i, m);
            b = Max(i, m);
            if (a >= x[i] - p && b <= x[i] + p) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        w[i] = l;
    }
    for (i = 3, k = std::max(w[1], w[2]); i <= k; ++i) k = std::max(k, w[i]);
    return i > n;
}

int main() {
    int i, j;
    scanf("%d", &n);
    n += 2;
    for (i = 1; i <= n; ++i) scanf("%d", &x[i]);
    for (i = n; i > 0; --i) {
        f[i][0] = g[i][0] = x[i];
        for (j = 1; j <= 20; ++j) {
            f[i][j] = std::min(f[i][j - 1], f[std::min(i + (1 << j - 1), n)][j - 1]);
            g[i][j] = std::max(g[i][j - 1], g[std::min(i + (1 << j - 1), n)][j - 1]);
        }
    }
    for (i = 2; i <= n; ++i) u[i] = u[i >> 1] + 1;
    l = std::abs(x[1] - x[2]), r = 1000000000;
    while (l < r) {
        if (check(l + r >> 1)) {
            r = (l + r >> 1);
        } else {
            l = (l + r >> 1) + 1;
        }
    }
    printf("%d\n", l);
    return 0;
}