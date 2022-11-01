#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

int dp[2005][2005]; // len l with open r
char s[100005];

int main() {
    dp[0][0] = 1;
    FO(i,1,2005) {
        FO(j,0,2005) {
            if (j) dp[i][j] += dp[i-1][j-1];
            if (j+1 < 2005) dp[i][j] += dp[i-1][j+1];
            if (dp[i][j] >= MOD) dp[i][j] -= MOD;
        }
    }
    int n, m;
    scanf("%d%d %s", &n, &m, s);
    int c = 0, o = 0;
    FO(i,0,m) {
        if (s[i] == '(') o++;
        else o--;
        if (o<0) {
            o++;
            c++;
        }
    }
    int ans = 0;
    // len on left
    FO(l,0,2005) {
        // #open excess on left
        FO(r,0,2005) {
            if (r >= c) {
                // n-m-l, r-c +o
                int l2 = n-m-l;
                int r2 = r-c+o;
                if (0 <= l2 && l2 < 2005 && 0 <= r2 && r2 < 2005) ans += dp[l][r] * 1ll * dp[l2][r2] % MOD;
                if (ans >= MOD) ans %= MOD;
            }
        }
    }
    printf("%d\n", ans);
}