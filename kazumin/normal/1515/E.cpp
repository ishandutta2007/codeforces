#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 405;
int n, MOD, dp[2][MN][MN], ans, fact[MN], inv[MN], p2[MN], wy[MN], iwy[MN]; //index, last auto, how many autos

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    else return ret * ret % MOD;
}

inline int ways(int x) {
    if (x < 1) return 1;
    return p2[x - 1];
}

int32_t main() {
    boost();


    cin >> n >> MOD;
    fact[0] = 1;
    p2[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = fpow(fact[i], MOD - 2);
        p2[i] = p2[i - 1] * 2 % MOD;
    }
    for (int i = 0; i < MN; i++) {
        wy[i] = ways(i);
        iwy[i] = fpow(wy[i], MOD - 2);
    }
    dp[1][0][0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                int len = i - j;
                dp[i & 1][j][k] = dp[1 - (i & 1)][j][k] * iwy[len - 1] % MOD * wy[len] % MOD;
                dp[i & 1][j][k] = dp[i & 1][j][k] * (i - k) % MOD; //new fact
                dp[i & 1][j][k] = dp[i & 1][j][k] * fact[len - 1] % MOD; //remove old div
                dp[i & 1][j][k] = dp[i & 1][j][k] * inv[len] % MOD; //add new div
                if (j < i - 1) dp[i & 1][i][k + 1] = (dp[i & 1][i][k + 1] + dp[1 - (i & 1)][j][k]) % MOD;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) ans = (ans + dp[n & 1][j][k]) % MOD;
    }
    printf("%lld\n", ans);

    return 0;
}