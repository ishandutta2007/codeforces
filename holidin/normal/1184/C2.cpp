#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int LN = 4e6 + 1;
long double eps = 1e-12;
int m[3 * LN], d[3* LN];

void push(int v) {
    if (d[v] != 0) {
        d[2*v + 1] += d[v];
        d[2*v + 2] += d[v];
        m[2*v + 1] += d[v];
        m[2*v + 2] += d[v];
        d[v] = 0;
    }
}

void recalc(int v) {
    m[v] = max(m[2*v + 1], m[2*v + 2]) + d[v];
}

void add(int v, int vl, int vr, int l, int r, int x) {
    if (l <= vl && vr <= r) {
        m[v] += x;
        d[v] += x;
    } else if (l >= vr || vl >= r)
            return;
        else {
            push(v);
            add(2*v + 1, vl, (vl + vr) / 2, l, r, x);
            add(2*v + 2, (vl + vr) / 2, vr, l, r, x);
            recalc(v);
        }
}

int okv(long double x) {
    return x + 1 - eps;
}

int okn(long double x) {
    return x;
}

vector <pair<long double, pair<int, int> > > v;

int main() {
    int i, j, k, n, x, y, a, b, vv;
    long double r;
    //freopen("input.txt", "r", stdin);
    cin >> n >> r;
    r *= sqrt(4);
    for (i = 0; i < n; ++i) {
        cin >> a >> b;
        x = a + b;
        y = a - b;
        x += 2e6 + 1;
        y += 2e6 + 1;
        v.push_back({okv(x - r), {y, 1}});
        v.push_back({x + 4 * eps, {y, -1}});
    }
    vv = 1;
    while (vv < 4e6)
        vv *= 2;
    sort(v.begin(), v.end());
    int ans = 0;
    j = 0;
    for (i = 0; i < v.size(); ++i) {
        int p = j;
        while (j < v.size() && v[j].fi - v[p].fi < eps) {
            add(0, 1, vv + 1, okv(v[j].se.fi - r), v[j].se.fi + 1, v[j].se.se);
            ++j;
        }
        ans = max(ans, m[0]);
    }
    cout << ans;
}