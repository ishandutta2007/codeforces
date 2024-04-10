#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
const long long inf = 1e18;

vector <pair<int, int> > e[N];
int nz[N], up[N], v, top;
long long d[N];
set <pair<long long, int> > s;

void build_do(int v, int vl, int vr) {
    nz[v] = ++top;
    up[v] = ++top;
    for (int i = vl; i < vr; ++i) {
        e[i].push_back({up[v], 0});
        e[nz[v]].push_back({i, 0});
    }
    if (vr - vl > 1) {
        build_do(2*v + 1, vl, (vl + vr) / 2);
        build_do(2*v + 2, (vl + vr) / 2, vr);
    }
}

void edgefrom(int v, int vl, int vr, int l, int r, int x, int y) {
    if (l <= vl && vr <= r)
        e[up[v]].push_back({x, y});
    else if (l >= vr || vl >= r)
            return;
        else {
            edgefrom(2*v + 1, vl, (vl + vr) / 2, l, r, x, y);
            edgefrom(2*v + 2, (vl + vr) / 2, vr, l, r, x, y);
        }
}

void edgeto(int v, int vl, int vr, int l, int r, int x, int y) {
    if (l <= vl && vr <= r)
        e[x].push_back({nz[v], y});
    else if (l >= vr || vl >= r)
            return;
        else {
            edgeto(2*v + 1, vl, (vl + vr) / 2, l, r, x, y);
            edgeto(2*v + 2, (vl + vr) / 2, vr, l, r, x, y);
        }
}

int main() {
    int i, j, k, n, type, l, r, c, q, st, u;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q >> st;
    v = 1;
    while (v < n) v *= 2;
    top = v;
    build_do(0, 1, v + 1);
    for (i = 0; i < q; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> l >> r >> c;
            edgefrom(0, 1, v + 1, l, l + 1, r, c);
        }
        if (type == 2) {
            cin >> u >> l >> r >> c;
            edgeto(0, 1, v + 1, l, r + 1, u, c);
        }
        if (type == 3) {
            cin >> u >> l >> r >> c;
            edgefrom(0, 1, v + 1, l, r + 1, u, c);
        }
    }
    for (i = 1; i <= top; ++i) {
        d[i] = inf;
        if (i == st)
            d[i] = 0;
        s.insert({d[i], i});
    }
    while (s.size() > 0) {
        int u = (*s.begin()).second;
        s.erase(s.begin());
        for (int i = 0; i < e[u].size(); ++i)
        if (d[e[u][i].fi] > d[u] + e[u][i].se) {
            s.erase({d[e[u][i].fi], e[u][i].fi});
            d[e[u][i].fi] = d[u] + e[u][i].se;
            s.insert({d[e[u][i].fi], e[u][i].fi});
        }
    }
    for (i = 1; i <= n; ++i)
    if (d[i] == inf)
        cout << -1 << ' ';
    else
        cout << d[i] << ' ';
}