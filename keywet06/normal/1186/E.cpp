#include <bits/stdc++.h>

using int64 = long long;

const int N = 1005;

int n, m;
int a[N][N];

int64 solve(int x, int y) {
    if (x == 0 || y == 0) return 0;
    int p = x / n;
    int q = y / m;
    int64 ans = (int64)p * q / 2 * n * m;
    if (p % 2 == 1 && q % 2 == 1) {
        if (__builtin_popcount((p - 1) ^ (q - 1)) % 2 == 1) {
            ans += n * m - a[n][m];
        } else {
            ans += a[n][m];
        }
    }
    ans += (int64)p / 2 * n * (y % m);
    if (p % 2 == 1) {
        if (__builtin_popcount((p - 1) ^ q) % 2 == 1) {
            ans += n * (y % m) - a[n][y % m];
        } else {
            ans += a[n][y % m];
        }
    }
    ans += (int64)q / 2 * (x % n) * m;
    if (q % 2 == 1) {
        if (__builtin_popcount(p ^ (q - 1)) % 2 == 1) {
            ans += (x % n) * m - a[x % n][m];
        } else {
            ans += a[x % n][m];
        }
    }
    if (__builtin_popcount(p ^ q) % 2 == 1) {
        ans += (x % n) * (y % m) - a[x % n][y % m];
    } else {
        ans += a[x % n][y % m];
    }
    return ans;
}
int main() {
    int q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%1d", &a[i][j]);
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    for (; q--;) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%lld\n", solve(x2, y2) - solve(x2, y1 - 1) - solve(x1 - 1, y2) +
                             solve(x1 - 1, y1 - 1));
    }
    return 0;
}