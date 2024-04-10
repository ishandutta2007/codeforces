#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int LN = 1e7 + 1;

int m[LN], l[LN], r[LN], suf[LN], pr[LN], h[N], root[N], sz, top = 1;

void recalc(int v, int vl, int vr) {
    m[v] = max(max(m[l[v]], m[r[v]]), suf[l[v]] + pr[r[v]]);
    if (pr[l[v]] == (vr - vl) / 2)
        pr[v] = pr[l[v]] + pr[r[v]];
    else
        pr[v] = pr[l[v]];
    if (suf[r[v]] == (vr - vl) / 2)
        suf[v] = suf[r[v]] + suf[l[v]];
    else
        suf[v] = suf[r[v]];
}

int als(int v, int vl, int vr, int lq, int rq) {
    if (lq <= vl && vr <= rq) {
        ++top;
        m[top] = 1;
        suf[top] = 1;
        pr[top] = 1;
        return top;
    } else if (lq >= vr || vl >= rq)
            return v;
        else {
            int u = ++top;
            l[u] = als(l[v], vl, (vl + vr) / 2, lq, rq);
            r[u] = als(r[v], (vl + vr) / 2, vr, lq, rq);
            recalc(u, vl, vr);
            return u;
        }
}

bool flag = 0;

int mxk(int v, int vl, int vr, int lq, int rq, int &sf, int &pre) {
    if (v == 0) {
        sf = 0;
        pre = 0;
        return 0;
    }
    if (lq <= vl && vr <= rq) {
        sf = suf[v];
        pre = pr[v];
        if (flag) {
        }
        return m[v];
    } else if (lq >= vr || vl >= rq) {
            sf = 0;
            pre = 0;
            return 0;
        } else {
            int sf1, pr1, sf2, pr2, ans;
            ans = max(mxk(l[v], vl, (vl + vr) / 2, lq, rq, sf1, pr1), mxk(r[v], (vl + vr) / 2, vr, lq, rq, sf2, pr2));
            if (pr1 == (vr - vl) / 2)
                pre = pr1 + pr2;
            else
                pre = pr1;
            if (sf2 == (vr - vl) / 2)
                sf = sf2 + sf1;
            else
                sf = sf2;
            return max(ans, sf1 + pr2);
        }
}

vector <pair<int, int> > v;

int main() {
    int i, j, k, n, a, b, q, w, l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> h[i];
        v.push_back({-h[i], i});
    }
    sort(v.begin(), v.end());
    sz = 1;
    while (sz < n) sz *= 2;
    root[0] = 1;
    top = 1;
    for (i = 1; i <= v.size(); ++i)
        root[i] = als(root[i - 1], 1, sz + 1, v[i - 1].se, v[i - 1].se + 1);
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> l >> r >> w;
        int l1 = 1, r1 = v.size() + 1;
        while (r1 - l1 > 1) {
            int x = (l1 + r1) / 2 - 1;
            if (mxk(root[x], 1, sz + 1, l, r + 1, a, b) < w)
                l1 = x + 1;
            else
                r1 = x + 1;
        }
        cout << -v[l1 - 1].fi << "\n";
    }
}