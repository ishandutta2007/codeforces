#include <bits/stdc++.h>

int d[55][55];
int a[55];
int c[55][55];

int ss[55], ee[55];

int p[55], q[55], tt[55];

int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }

int main() {
    int L, R, M, S;
    int i, j, k, l, n, m, t;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (i != j) d[i][j] = 1e9;
        }
    }
    for (i = 1; i < n; ++i) {
        scanf("%d%d%d", &j, &k, &l);
        ss[i] = j, ee[i] = k;
        d[j][k] = d[k][j] = l, ++a[j], ++a[k];
    }
    scanf("%d%d", &S, &m);
    for (i = 1; i <= n; ++i) p[i] = i;
    for (i = 1; i < n; ++i) {
        if (ss[i] != S && ee[i] != S) p[f(ss[i])] = f(ee[i]);
    }
    for (i = 0; i < m; ++i) scanf("%d", &j), ++q[f(j)];
    for (k = 1; k <= n; ++k) {
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= n; ++j) {
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for (i = 1; i <= m; ++i) {
        for (j = 1; j <= n; ++j) {
            if (a[j] == 1) {
                L = 0;
                R = 1e9;
                while (L < R) {
                    M = L + R + 1 >> 1;
                    t = 0;
                    for (k = 1; k <= n; ++k)
                        if (a[k] == 1) {
                            for (l = 0; l < i && c[l][k] + d[j][k] < M; ++l) true;
                            t += i - l;
                        }
                    if (t < i) {
                        R = M - 1;
                    } else {
                        L = M;
                    }
                }
                c[i][j] = L;
            }
        }
    }
    L = 0, R = 1e9;
    while (L < R) {
        M = L + R + 1 >> 1;
        for (k = 1; k <= n; ++k) tt[k] = 0;
        for (k = 1; k <= n; ++k) {
            if (a[k] == 1) {
                for (l = 0; l < m && c[l][k] + d[S][k] < M; ++l) true;
                tt[f(k)] += m - l;
            }
        }
        for (k = 1; k <= n; ++k) {
            if (tt[k] < q[k]) break;
        }
        if (k > n) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    printf("%d\n", L);
    return 0;
}