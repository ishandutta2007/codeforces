#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int mxN = 20e6;
const int inf = 2e9 + 1;

map <int, int> xn;
long long x[N], t[N], cnt[N];
int d[mxN], m[mxN], l[mxN], r[mxN], v, top = 0;

void minr(int v, int vl, int vr, int l1, int r1, int x) {
    if (l1 <= vl && vr <= r1) {
        m[v] = min(m[v], x);
        d[v] = min(d[v], x);
    } else if (l1 >= vr || vl >= r1)
            return;
        else {
            if (l[v] == 0) {
                l[v] = ++top;
                m[top] = inf;
                d[top] = inf;
            }
            minr(l[v], vl, (vl + vr) / 2, l1, r1, x);
            if (r[v] == 0) {
                r[v] = ++top;
                m[top] = inf;
                d[top] = inf;
            }
            minr(r[v], (vl + vr) / 2, vr, l1, r1, x);
            m[v] = min(min(m[l[v]], m[r[v]]), d[v]);
        }
}

int mn(int v, int vl, int vr, int l1, int r1) {
    if (l1 <= vl && vr <= r1)
        return m[v];
    else if (l1 >= vr || vl >= r1)
            return inf;
        else {
            int ans = inf;
            if (l[v] != 0)
                ans = min(ans, mn(l[v], vl, (vl + vr) / 2, l1, r1));
            if (r[v] != 0)
                ans = min(ans, mn(r[v], (vl + vr) / 2, vr, l1, r1));
            return min(ans, d[v]);
        }
}

multiset <pair<int, int> > s;

void recalc(int u) {
    while (s.lower_bound({x[u], 0}) != s.end()) {
        pair <int, int> p = *s.lower_bound({x[u], 0});
        if (p.first <= x[u] + t[u]) {
            t[u] += p.second;
            ++cnt[u];
            s.erase(s.lower_bound({x[u], 0}));
        } else
            break;
    }
    minr(0, 1, v + 1, x[u], min(x[u] + t[u], (long long)v) + 1, x[u]);
}

int main() {
    int i, j, n, k, ans = 0, l, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v = 1;
    while (v < 1e9)
        v *= 2;
    d[0] = inf;
    m[0] = inf;
    for (i = 1; i <= n; ++i) {
        cin >> x[i] >> t[i];
        ++x[i];
        xn[x[i]] = i;
        minr(0, 1, v + 1, x[i], min((long long)v, x[i] + t[i]) + 1, x[i]);
    }
    for (i = 0; i < k; ++i) {
        cin >> a >> b;
        ++a;
        int c = mn(0, 1, v + 1, a, a + 1);
        if (c != inf) {
            t[xn[c]] += b;
            ++cnt[xn[c]];
            recalc(xn[c]);
        } else
            s.insert({a, b});
    }
    for (i = 1; i <= n; ++i)
        cout << cnt[i] << ' ' << t[i] << "\n";
}