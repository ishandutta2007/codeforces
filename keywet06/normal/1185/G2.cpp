#include <bits/stdc++.h>

const int N = 50 + 5, T = 2500 + 5, P = 1e9 + 7;

int f[N][T], g[N][N][T], h[N][N][N][4], t[N][N][N], fac[N];

void chk(int &x) { x >= P ? x -= P : x < 0 ? x += P : 0; }

int main() {
    int n, tot;
    scanf("%d %d", &n, &tot);
    f[0][0] = 1;
    g[0][0][0] = 1;
    int sum[3] = {}, cnt[3] = {};
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --y;
        if (y == 0) {
            for (int j = cnt[0]; j >= 0; --j) {
                for (int k = sum[0]; k >= 0; --k) {
                    chk(f[j + 1][k + x] += f[j][k]);
                }
            }
        } else {
            for (int j = cnt[1]; j >= 0; --j) {
                for (int k = cnt[2]; k >= 0; --k) {
                    for (int l = sum[1] + sum[2]; l >= 0; --l) {
                        chk(g[j + (y == 1)][k + (y == 2)][l + x] += g[j][k][l]);
                    }
                }
            }
        }
        ++cnt[y];
        sum[y] += x;
    }
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = 1ll * fac[i - 1] * i % P;
    }
    h[0][0][0][3] = 1;
    for (int i = 0; i <= cnt[0]; ++i) {
        for (int j = 0; j <= cnt[1]; ++j) {
            for (int k = 0; k <= cnt[2]; ++k) {
                for (int l = 0; l <= 3; ++l) {
                    chk(t[i][j][k] += h[i][j][k][l]);
                }
                chk(h[i + 1][j][k][0] += t[i][j][k] - h[i][j][k][0]);
                chk(h[i][j + 1][k][1] += t[i][j][k] - h[i][j][k][1]);
                chk(h[i][j][k + 1][2] += t[i][j][k] - h[i][j][k][2]);
                t[i][j][k] =
                    1ll * t[i][j][k] * fac[i] % P * fac[j] % P * fac[k] % P;
            }
        }
    }
    int ans = 0;
    for (int x = 0; x <= tot; ++x) {
        for (int i = 0; i <= cnt[0]; ++i) {
            for (int j = 0; j <= cnt[1]; ++j) {
                for (int k = 0; k <= cnt[2]; ++k) {
                    chk(ans +=
                        1ll * f[i][x] * g[j][k][tot - x] % P * t[i][j][k] % P);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}