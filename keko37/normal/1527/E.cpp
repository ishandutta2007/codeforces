#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 35005;
const int MAXK = 105;
const llint INF = 1000000000000000000LL;

int n, k, ofs = 1;
int a[MAXN], pos[MAXN];
llint t[MAXN * 4], prop[MAXN * 4];
llint dp[MAXN][MAXK];

void propagate (int x) {
    if (prop[x] == 0) return;
    if (x < ofs) {
        prop[2 * x] += prop[x];
        prop[2 * x + 1] += prop[x];
    }
    t[x] += prop[x];
    prop[x] = 0;
}

void update (int x, int from, int to, int lo, int hi, int val) {
    //for (int i = from; i <= to; i++) t[i + ofs] += val;
    //return;
    propagate(x);
    if (from <= lo && hi <= to) {
        prop[x] += val;
        propagate(x);
        return;
    }
    if (to < lo || hi < from) return;
    update(2 * x, from, to, lo, (lo + hi) / 2, val);
    update(2 * x + 1, from, to, (lo + hi) / 2 + 1, hi, val);
    t[x] = min(t[2 * x], t[2 * x + 1]);
}

llint upit (int x, int from, int to, int lo, int hi) {
    /*llint res = INF;
    for (int i = from; i <= to; i++) {
        res = min(res, t[i + ofs]);
    }
    return res;*/
    propagate(x);
    if (from <= lo && hi <= to) return t[x];
    if (to < lo || hi < from) return INF;
    return min(upit(2 * x, from, to, lo, (lo + hi) / 2), upit(2 * x + 1, from, to, (lo + hi) / 2 + 1, hi));
}

void calc (int j) {
    for (int i = 0; i < 2 * ofs; i++) t[i] = INF, prop[i] = 0;
    for (int i = 1; i <= n; i++) {
        t[i + ofs] = dp[i - 1][j - 1];
        //if (j == 2) cout << "bla " << i << " " << t[i + ofs] << endl;
    }
    for (int i = ofs - 1; i > 0; i--) {
        t[i] = min(t[2 * i], t[2 * i + 1]);
    }
    for (int i = 1; i <= n; i++) pos[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (pos[a[i]] != 0) {
            //if (j == 2) cout << "upd " << 1 << " " << pos[a[i]] << "  " << i - pos[a[i]] << endl;
            update(1, 1, pos[a[i]], 0, ofs - 1, i - pos[a[i]]);
        }
        pos[a[i]] = i;
        dp[i][j] = upit(1, 1, i, 0, ofs - 1);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    while (ofs < n + 1) ofs *= 2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][0] = INF;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) calc(i);
    cout << dp[n][k];
    return 0;
}