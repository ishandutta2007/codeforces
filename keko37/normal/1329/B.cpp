#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 35;

int t, d, n, m;
int pot[MAXN];
int dp[MAXN][MAXN];

int add (int x, int y) {x += y; if (x >= m) return x - m; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + m; return x;}
int mul (int x, int y) {return (llint) x * y % m;}

int calc (int pos, int len) {
    if (dp[pos][len] != -1) return dp[pos][len];
    int val;
    if (len == n) val = d - pot[n - 1] + 1; else val = pot[len - 1];
    int res = val % m;
    if (len + 1 <= n) res = add(res, calc(pos, len + 1));
    if (pos + 1 <= n && len + 1 <= n) res = add(res, mul(calc(pos + 1, len + 1), val));
    return dp[pos][len] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof dp);
        cin >> d >> m;
        n = 0;
        while ((1LL << n) <= d) n++;
        pot[0] = 1;
        for (int i = 1; i <= n; i++) {
            pot[i] = mul(pot[i - 1], 2);
        }
        cout << calc(1, 1) << '\n';
    }
    return 0;
}