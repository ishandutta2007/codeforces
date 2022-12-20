#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;

long long m[N], d[N], a, x[N], c[N], d1[N];
int l[N], r[N], v;

void recalc(int v) {
    m[v] = max(m[2*v + 1], m[2*v + 2]);
}

void push(int v) {
    if (d[v] != 0) {
        d[2*v + 1] += d[v];
        d[2*v + 2] += d[v];
        m[2*v + 1] += d[v];
        m[2*v + 2] += d[v];
        d[v] = 0;
    }
}

void add(int v, int vl, int vr, int l, int r, long long x) {
    if (l <= vl && vr <= r) {
        m[v] += x;
        d[v] += x;
    } else if (vl >= r || l >= vr)
            return;
        else {
            push(v);
            add(2*v + 1, vl, (vl + vr) / 2, l, r, x);
            add(2*v + 2, (vl + vr) / 2, vr, l, r, x);
            recalc(v);
        }
}

long long get(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r)
        return m[v];
    else if (l >= vr || vl >= r)
            return -1e9;
        else {
            push(v);
            return max(get(2*v + 1, vl, (vl + vr) / 2, l, r), get(2*v + 2, (vl + vr) / 2, vr, l, r));
        }
}

set <pair<long long, int> > s;

int main() {
    int i, j, n, top;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a;
    for (i = 1; i <= n; ++i) {
        cin >> d1[i] >> c[i];
        if (i > 1)
            x[i - 1] = (d1[i] - d1[i - 1]) * (d1[i] - d1[i - 1]);
    }
    top = 1;
    for (i = 1; i < n; ++i) {
        l[i] = i + 1;
        while (s.size() > 0 && (*s.begin()).fi <= x[i]) {
            r[(*s.begin()).se] = i;
            s.erase(s.begin());
        }
        s.insert({x[i], i});
    }
    while (s.size() > 0) {
        pair <long long, int> p = *s.begin();
        s.erase(p);
        r[p.se] = n;
    }
    v = 1;
    while (v < n) v *= 2;
    for (i = 1; i <= n; ++i)
        add(0, 1, v + 1, i, n + 1, a - c[i]);
    j = 1;
    while (j < n) {
        add(0, 1, v + 1, j + 1, r[j] + 1, -x[j]);
        j = r[j];
    }
    long long ans = max((long long) 0, get(0, 1, v + 1, 1, n + 1));
    for (i = 2; i <= n; ++i) {
        add(0, 1, v + 1, i, n + 1, c[i - 1] - a);
        add(0, 1, v + 1, i, r[i - 1] + 1, x[i - 1]);
        int p = i;
        int cnt = 0;
        while (p < r[i - 1] && i != n) {
            add(0, 1, v + 1, p + 1, r[p] + 1, -x[p]);
            p = r[p];
        }
        ans = max(ans, get(0, 1, v + 1, 1, n + 1));
    }
    cout << ans;
}