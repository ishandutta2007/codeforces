#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 105;

int n, a, b;
int p[MAXN];
int dp[MAXN][MAXN][MAXN][3];

int calc (int pos, int par, int nep, int tip) {
    if (pos == n) return 0;
    if (dp[pos][par][nep][tip] != -1) return dp[pos][par][nep][tip];
    int res = MAXN;
    if (p[pos] != 0) {
        if (p[pos] % 2 == 0) {
            res = (tip == 1) + calc(pos + 1, par, nep, 0);
        } else {
            res = (tip == 0) + calc(pos + 1, par, nep, 1);
        }
    } else {
        if (par > 0) {
            res = min(res, (tip == 1) + calc(pos + 1, par - 1, nep, 0));
        }
        if (nep > 0) {
            res = min(res, (tip == 0) + calc(pos + 1, par, nep - 1, 1));
        }
    }
    return dp[pos][par][nep][tip] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    a = n / 2;
    b = n - a;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == 0) continue;
        if (p[i] % 2 == 0) a--; else b--;
    }
    cout << calc(0, a, b, 2);
    return 0;
}