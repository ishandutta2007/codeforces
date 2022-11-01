#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> sm[1<<13];
int n, m, q;
int u[13];
vector<int> r[13];
bool gd[13][1<<13];
bool gd2[13][1<<13];
long long dp[13][1<<13];
long long dp2[13][1<<13];

int main() {
    FO(i,0,1<<13) FO(j,0,1<<13) if ((i&j) == j) {
        sm[i].push_back(j);
    }
    scanf("%d %d %d", &n, &m, &q);
    FO(i,0,m) {
        int x, v; scanf("%d%d", &x, &v); x--; v--;
        u[x] |= 1<<v;
        u[v] |= 1<<x;
    }
    FO(i,0,q) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--; c--;
        r[c].push_back((1<<a) | (1<<b));
    }
    FO(i,0,n) {
        FO(j,0,1<<n) {
            gd[i][j] = true;
            for (int x : r[i]) if ((j&x) == x) {
                gd[i][j] = false;
            }
            FO(k,0,n) {
                if ((j&(1<<k)) && (u[k]&(j|(1<<i))) != u[k]) {
                    gd[i][j] = false;
                }
            }
            if (__builtin_popcount(j&u[i]) > 1) {
                gd[i][j] = false;
            }
        }
    }
    FO(i,0,n) {
        FO(j,0,1<<n) {
            gd2[i][j] = true;
            for (int x : r[i]) if (((j|(1<<i))&x) != x) {
                gd2[i][j] = false;
            }
        }
    }
    FO(m,0,1<<n) FO(i,0,n) if (!(m&(1<<i))) {
        if (m == 0) {
            dp[i][m] = 1;
            dp2[i][m] = gd2[i][m];
        } else {
            for (int s : sm[m]) if (gd[i][s] && __builtin_ctz(m) == __builtin_ctz(s)) {
                if (__builtin_popcount(s&u[i]) == 1) {
                    dp[i][m] += dp[i][m^s] * dp2[__builtin_ctz(s&u[i])][s^(1<<__builtin_ctz(s&u[i]))];
                } else {
                    FO(r,0,n) if (s&(1<<r)) {
                        dp[i][m] += dp[i][m^s] * dp2[r][s^(1<<r)];
                    }
                }
            }
            if (gd2[i][m]) {
                dp2[i][m] = dp[i][m];
            }
        }
    }
    printf("%lld\n", dp[0][(1<<n)-2]);
}