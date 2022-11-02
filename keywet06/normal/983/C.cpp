#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int K = 805;
const int C = 10;
const int M = 10005;

int n, ans = 1e9, p;
int x[C];
int m[K], v[K];
int a[N], b[N];
int w[M];
int c[K][C], d[K][C], u[K][C];
int f[N][C][K];

inline void dfs(int i, int l) {
    int j, k = 0;
    if (i == l) {
        p++;
        m[p] = i - 1;
        for (j = 1, k = 0; j < i; ++j) u[p][j] = x[j], k = k * C + x[j];
        v[p] = k;
        w[k] = p;
        return;
    }
    for (j = x[i - 1]; j <= 9; ++j) {
        x[i] = j;
        dfs(i + 1, l);
    }
}

inline int del(int i, int j) {
    int k, l;
    for (k = 1, l = 0; k <= m[i]; ++k) {
        if (u[i][k] != j) l = l * C + u[i][k];
    }
    return w[l];
}

inline int add(int i, int j) {
    if (m[i] == 4) return 0;
    int k, l;
    for (k = 1, l = 0; k <= m[i] && u[i][k] < j; ++k) l = l * C + u[i][k];
    l = l * C + j;
    for (; k <= m[i]; ++k) l = l * C + u[i][k];
    return w[l];
}

inline void minn(int &a, int b) { a = min(a, b); }

int main() {
    int i, j, k, l;
    x[0] = 1;
    for (i = 1; i <= 5; ++i) dfs(1, i);
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]);
    for (i = 1; i <= p; ++i) {
        for (j = 1; j <= 9; ++j) {
            c[i][j] = add(i, j);
            d[i][j] = del(i, j);
        }
    }
    for (i = 1; i <= n + 1; ++i) {
        for (j = 1; j <= 9; ++j) {
            for (k = 1; k <= p; ++k) f[i][j][k] = 1e9;
        }
    }
    f[1][1][1] = 0;
    for (i = 1; i <= n + 1; ++i) {
        for (k = p; k > 0; --k) {
            for (j = 1; j <= 9; ++j) {
                for (l = 1; l <= m[k]; ++l) {
                    minn(f[i][u[k][l]][d[k][u[k][l]]],
                         f[i][j][k] + abs(j - u[k][l]));
                }
                if (m[k] < 4 && i <= n) {
                    minn(f[i + 1][a[i]][c[k][b[i]]],
                         f[i][j][k] + abs(j - a[i]));
                }
                if (i == n + 1 && k == 1) minn(ans, f[i][j][k]);
            }
        }
    }
    printf("%d\n", ans + 2 * n);
    return 0;
}