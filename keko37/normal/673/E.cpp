#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

const int MAXN = 200005;
const int MAXK = 53;
const ld INF = 10000000000000000LL;

int n, k, curr;
ld t[MAXN], dp[MAXN] [MAXK], s[MAXN], p[MAXN], r[MAXN];

ld cost (int x, int y) {
    if (x == 1) return s[y];
    return s[y] - s[x-1] - p[x-1] * (r[y] - r[x-1]);
}

void calc (int lef, int rig, int p_lef, int p_rig) {
    if (lef > rig) return;
    int mid = (lef + rig) / 2, piv;
    ld res = INF;
    for (int i=min(p_rig, mid); i>=p_lef; i--) {
        ld val = dp[i-1] [curr-1] + cost(i, mid);
        if (val < res) {
            res = val;
            piv = i;
        }
    }
    dp[mid] [curr] = res;
    calc(lef, mid-1, p_lef, piv);
    calc(mid+1, rig, piv, p_rig);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    s[1] = 1, p[1] = t[1], r[1] = 1 / t[1];
    for (int i=2; i<=n; i++) {
        r[i] = r[i-1] + 1 / t[i];
        p[i] = p[i-1] + t[i];
        s[i] = s[i-1] + p[i] / t[i];
    }
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            dp[i] [j] = INF;
        }
    }
    for (int i=1; i<=n; i++) {
        dp[i] [1] = cost(1, i);
    }
    for (curr = 2; curr <= k; curr++) {
        calc(curr, n, 1, n);
    }
    cout << fixed << setprecision(12) << dp[n] [k];
    return 0;
}