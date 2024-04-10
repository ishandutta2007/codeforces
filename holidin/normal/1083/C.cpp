#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 4e5 + 1;
const int LogN = 20;

int t[LogN], pa[4*N], pb[4*N];
int deep[N], m[LogN][N], tin[N], tout[N], p[N], top = 0, v;
vector <int> e[N];

void dfs(int u, int pr) {
    m[0][u] = pr;
    for (int i = 1; i < LogN; ++i)
        m[i][u] = m[i - 1][m[i - 1][u]];
    ++top;
    tin[u] = top;
    for (int i = 0; i < e[u].size(); ++i) {
        deep[e[u][i]] = deep[u] + 1;
        dfs(e[u][i], u);
    }
    ++top;
    tout[u] = top;
}

int lca(int a, int b) {
    if (deep[a] > deep[b])
        swap(a, b);
    for (int i = LogN - 1; i >= 0; --i)
    if (deep[b] - t[i] >= deep[a])
        b = m[i][b];
    if (a == b)
        return a;
    for (int i = LogN - 1; i >= 0; --i)
    if (m[i][a] != m[i][b]) {
        a = m[i][a];
        b = m[i][b];
    }
    return m[0][a];
}

int lc(int a, int b) {
    for (int i = LogN - 1; i >= 0; --i)
    if (t[i] <= b) {
        b-= t[i];
        a = m[i][a];
    }
    return a;
}

bool inv(int a, int b) {
    return (tin[a] <= tin[b] && tout[b] <= tout[a]);
}

pair <int, int> cntr(pair<int, int> p) {
    if (inv(p.se, p.fi))
        swap(p.fi, p.se);
    return p;
}

pair <int, int> merg(int a1, int b1, int a2, int b2) {
    if (a1 == 0 || b1 == 0 || a2 == 0 || b2 == 0)
        return {0, 0};
    if (a1 == -1 || b1 == -1)
        return {a2, b2};
    vector <pair<int, int> > v;
    v.push_back({deep[a1], a1});
    v.push_back({deep[b1], b1});
    v.push_back({deep[a2], a2});
    v.push_back({deep[b2], b2});
    sort(v.begin(), v.end());
    bool cn = true;
    for (int i = 0; i < 3; ++i)
    if (!inv(v[i].se, v[i + 1].se))
        cn = false;
    if (cn)
        return {v[0].se, v[3].se};
    int u = lca(lca(a1, b1), lca(a2, b2));
    int h[4];
    for (int i = 0; i < 4; ++i)
        h[i] = lc(v[i].se, deep[v[i].se] - deep[u] - 1);
    for (int i = 0; i < 4; ++i)
    for (int j = i + 1; j < 4; ++j) {
        cn = h[i] != h[j];
        for (int l = 0; l < 4; ++l)
        if (l != i && l != j && (!(inv(v[l].se, v[i].se) ^ inv(v[l].se, v[j].se))) && (u != v[l].se))
            cn = false;
        if (cn)
            return {v[i].se, v[j].se};
    }
    return {0, 0};
}

void als(int i, int j) {
    i = i + v - 2;
    pa[i] = j;
    pb[i] = j;
    while (i > 0) {
        i = (i - 1) / 2;
        pair<int, int> f = merg(pa[2*i + 1], pb[2*i + 1], pa[2*i + 2], pb[2*i + 2]);
        pa[i] = f.fi;
        pb[i] = f.se;
    }
}

int aft(int v, int vl, int vr, int &a, int &b) {
    if (vr - vl == 1) {
        pair <int, int> H = merg(a, b, pa[v], pb[v]);
        if (H.fi != 0) {
            a = H.fi;
            b = H.se;
            return vl;
        } else
            return vl - 1;
    } else {
        pair <int, int> H = merg(a, b, pa[2 * v + 1], pb[2 * v + 1]);
        if (H.fi != 0) {
            a = H.fi;
            b = H.se;
            return aft(2*v + 2, (vl + vr) / 2, vr, a, b);
        } else
            return aft(2*v + 1, vl, (vl + vr) / 2, a, b);
    }
}

int main() {
    int i, j, n, k, q, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    t[0] = 1;
    for (i = 1; i < LogN; ++i)
        t[i] = t[i - 1] * 2;
    for (i = 1; i <= n; ++i)
        cin >> p[i];
    for (i = 2; i <= n; ++i) {
        cin >> j;
        e[j].push_back(i);
    }
    dfs(1, 1);
    v = 1;
    while (v < n) v *= 2;
    for (i = 1; i <= n; ++i) {
        ++p[i];
        als(p[i], i);
    }
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> j;
        if (j == 2) {
            a = -1;
            b = -1;
            cout << aft(0, 1, v + 1, a, b) << "\n";
        } else {
            cin >> a >> b;
            swap(p[a], p[b]);
            als(p[a], a);
            als(p[b], b);
        }
    }

}