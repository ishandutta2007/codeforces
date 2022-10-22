#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 255, mod = 1e9 + 7;

int n, m;
char map[mxn][mxn];

inline void uadd(int &x, int y) {
    x += y - mod;
    x += x >> 31 & mod;
}

int main() {
    scanf("%d %d", &n, &m);
    rep(i, n) scanf("%s", map[i]);
    if (n > m) {
        static char temp[mxn][mxn];
        rep(i, n) rep(j, m) temp[j][i] = map[i][j];
        std::swap(n, m);
        rep(i, n) rep(j, m) map[i][j] = temp[i][j];
    }
    static int dp[1 << 15][2][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    rep(j, m) {
        rep(i, n) {
            static int ndp[1 << 15][2][2];
            memset(ndp, 0, sizeof(ndp));
            rep(mask, 1 << n) rep(f, 2) rep(c, 2) {
                if (map[i][j] == 'x') {
                    uadd(ndp[mask & ~(1 << i)][0][c], dp[mask][f][c]);
                } else {
                    int nc = c + (!(mask >> i & 1) && !f);
                    if (nc < 2) uadd(ndp[mask][f][nc], dp[mask][f][c]);
                    uadd(ndp[mask | 1 << i][1][c], dp[mask][f][c]);
                }
            }
            memcpy(dp, ndp, sizeof(dp));
        }
        static int ndp[1 << 15][2][2];
        memset(ndp, 0, sizeof(ndp));
        rep(mask, 1 << n) rep(f, 2) rep(c, 2) {
            uadd(ndp[mask][0][c], dp[mask][f][c]);
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    int ans = 0;
    rep(mask, 1 << n) rep(f, 2) rep(c, 2) uadd(ans, dp[mask][f][c]);
    printf("%d\n", ans);
    return 0;
}