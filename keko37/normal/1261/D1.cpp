#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 2010;
const int OFS = 2005;
const int MOD = 998244353;

int n, k;
int h[MAXN];
int dp[MAXN][MAXN * 2];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int f (int pos, int d) {
    if (pos == n) {
        if (d > 0) return 1; return 0;
    }
    if (dp[pos][d + OFS] != -1) return dp[pos][d + OFS];
    int res = 0;
    if (h[pos] == h[(pos + 1) % n]) {
        res = add(res, mul(k, f(pos + 1, d)));
    } else {
        res = add(res, f(pos + 1, d + 1));
        res = add(res, f(pos + 1, d - 1));
        res = add(res, mul(k - 2, f(pos + 1, d)));
    }
    return dp[pos][d + OFS] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    cout << f(0, 0);
    return 0;
}