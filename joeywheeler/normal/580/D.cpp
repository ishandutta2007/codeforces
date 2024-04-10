#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n, m, k;
ll a[20];
ll dp[1<<19][19];
ll v[20][20];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    FO(i,0,n) scanf("%lld", a+i);
    FO(i,0,k) {
        int x, y, c; scanf("%d%d%d", &x, &y, &c); x--; y--;
        v[x][y] = c;
    }
    ll res= 0;
    for (int i = (1<<n)-1; i >= 1; i--) {
        FO(j,0,n) if (i&(1<<j)) {
            if (__builtin_popcount(i) < m) {
                FO(k,0,n) if (~i&(1<<k)) dp[i][j] = max(dp[i][j],dp[i|(1<<k)][k] + v[j][k]);
            } else if (__builtin_popcount(i) == m) {
                dp[i][j] = 0;
                FO(k,0,n) if (i&(1<<k)) dp[i][j] += a[k];
            }
            if (__builtin_popcount(i) == 1) res =  max(res, dp[i][j]);
        }
    }
    printf("%lld\n", res);
}