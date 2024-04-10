#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 19;
const llint INF = 1000000000000000000LL;

int n, ind, cnt;
llint a[1 << MAXN], dp[MAXN][1 << MAXN], br[MAXN];

void precompute () {
    int pot = n;
    while (pot > 1) {
        pot /= 2;
        cnt++;
        br[cnt] = br[cnt - 1] + pot;
    }
}

llint calc (int ost, int pos) {
    if (dp[ost][pos] != -1) return dp[ost][pos];
    if (pos == 0) return 0;
    llint res = INF;
    if (ost < cnt) res = min(res, calc(ost + 1, pos - 1) + a[pos]);
    if (n - pos <= br[ost]) res = min(res, calc(ost, pos - 1));
    return dp[ost][pos] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    precompute();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) ind = i;
    }
    for (int i = 0; i < ind; i++) a[i] = 0;
    swap(a[0], a[ind]);
    cout << calc(0, n - 1);
    return 0;
}