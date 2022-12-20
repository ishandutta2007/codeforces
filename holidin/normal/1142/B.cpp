#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 6e5;
const int LogN = 20;
int d[N], v, a[N], p[N], num[N], pr[LogN][N], t[LogN];
set <int> s[N];

void als(int i, int j) {
    i = i + v - 2;
    d[i] = j;
    while (i > 0) {
        i = (i - 1) / 2;
        d[i] = min(d[2*i + 1], d[2*i + 2]);
    }
}

int mn(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r)
        return d[v];
    else if (l >= vr || vl >= r)
            return 1e9;
        else
            return min(mn(2*v + 1, vl, (vl + vr) / 2, l, r), mn(2*v + 2, (vl + vr) / 2, vr, l, r));
}

int main() {
    int i, j, n, m, q, l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (i = 0; i < n; ++i) {
        cin >> p[i];
        num[p[i]] = i;
    }
    for (i = 0; i < m; ++i) {
        cin >> a[i];
        s[a[i]].insert(i);
    }
    pr[0][m] = m;
    for (i = 0; i < m; ++i) {
        int next = p[(num[a[i]] + 1) % n];
        if (s[next].lower_bound(i + 1) == s[next].end())
            pr[0][i] = m;
        else
            pr[0][i] = *s[next].lower_bound(i + 1);
    }
    t[0] = 1;
    for (i = 1; i < LogN; ++i) {
        t[i] = t[i - 1] * 2;
        for (j = 0; j <= m; ++j)
            pr[i][j] = pr[i - 1][pr[i - 1][j]];
    }
    v = 1;
    while (v < m) v *= 2;
    for (i = 0; i < m; ++i) {
        int x = n - 1, u = i;
        for (j = LogN - 1; j >= 0; --j)
        if (x >= t[j]) {
            x -= t[j];
            u = pr[j][u];
        }
        als(i + 1, u + 1);
    }
    for (i = 0; i < q; ++i) {
        cin >> l >> r;
        if (mn(0, 1, v + 1, l, r + 1) <= r)
            cout << 1;
        else
            cout << 0;
    }
}