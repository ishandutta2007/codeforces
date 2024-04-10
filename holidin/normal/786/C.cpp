#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int LN = 6e6 + 1;

int root[N], ls[N], nx[N], a[N], top = 1, v;
int l[LN], r[LN], m[LN];

int als(int v, int vl, int vr, int lq, int rq, int x) {
    if (lq <= vl && vr <= rq) {
        ++top;
        m[top] = x;
        return top;
    } else if (lq >= vr || vl >= rq)
            return v;
        else {
            int u = ++top;
            l[u] = als(l[v], vl, (vl + vr) / 2, lq, rq, x);
            r[u] = als(r[v], (vl + vr) / 2, vr, lq, rq, x);
            m[u] = m[l[u]] + m[r[u]];
            return u;
        }
}

int sp(int v, int vl, int vr, int cnt) {
    if (m[v] <= cnt)
        return vr - 1;
    if (vr - vl == 1)
        if (cnt < m[v])
            return vl - 1;
        else
            return vl;
    if (m[l[v]] <= cnt)
        return sp(r[v], (vl + vr) / 2, vr, cnt - m[l[v]]);
    else
        return sp(l[v], vl, (vl + vr) / 2, cnt);

}

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    //freopen("test.txt", "r", stdin);
    //freopen("test1.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    v = 1;
    while (v < n) v *= 2;
    root[1] = 1;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        if (ls[a[i]] != 0)
            nx[ls[a[i]]] = i;
        else
            root[1] = als(root[1], 1, v + 1, i, i + 1, 1);
        ls[a[i]] = i;
    }
    for (i = 2; i <= n; ++i) {
        root[i] = als(root[i - 1], 1, v + 1, i - 1, i, 0);
        root[i] = als(root[i], 1, v + 1, nx[i - 1], nx[i - 1] + 1, 1);
    }
    for (i = 1; i <= n; ++i) {
        j = 1;
        int ans = 0;
        while (j <= n) {
            ++ans;
            j = sp(root[j], 1, v + 1, i) + 1;
        }
        cout << ans << ' ';
    }
}