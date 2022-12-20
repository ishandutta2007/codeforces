#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 1;
const int MXN = 19e6 + 1;
const int long long inf = 1e18;


vector <pair<int, int > > e[N];
int tin[N], tout[N], root[N];
long long rs[N];
int l[MXN], r[MXN];
long long m[MXN], d[MXN];
int top, v;

void build(int v, int vl, int vr) {
    if (vr - vl == 1)
        m[v] = rs[vl];
    else {
        l[v] = 2 * v + 1;
        r[v] = 2 * v + 2;
        build(2 * v + 1, vl, (vl + vr) / 2);
        build(2 * v + 2, (vl + vr) / 2, vr);
        m[v] = min(m[2*v + 1], m[2*v + 2]);
    }
}

int add(int v, int vl, int vr, int lq, int rq, long long x) {
    if (m[v] >= inf / 2)
        return v;
    if (lq <= vl && vr <= rq) {
        ++top;
        m[top] = m[v] + x;
        d[top] = d[v] + x;
        l[top] = l[v];
        r[top] = r[v];
        return top;
    } else if (vl >= rq || lq >= vr)
            return v;
        else {
            int u = ++top;
            d[u] = d[v];
            l[u] = add(l[v], vl, (vl + vr) / 2, lq, rq, x);
            r[u] = add(r[v], (vl + vr) / 2, vr, lq, rq, x);
            m[u] = min(m[l[u]], m[r[u]]) + d[u];
            return u;
        }
}


long long mn(int v, int vl, int vr, int lq, int rq) {
    if (lq <= vl && vr <= rq)
        return m[v];
    else if (vl >= rq || lq >= vr)
            return inf;
        else
            return min(mn(l[v], vl, (vl + vr) / 2, lq, rq), mn(r[v], (vl + vr) / 2, vr, lq, rq)) + d[v];
}

void dfs(int u, int pr, long long dr) {
    top = u;
    if (e[u].size() != 0)
        rs[u] = inf;
    else
        rs[u] = dr;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].fi != pr)
        dfs(e[u][i].fi, u, dr + e[u][i].se);
    tin[u] = u;
    tout[u] = top;
}

void dfs_trees(int u, int pr, int rt) {
    root[u] = rt;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].fi != pr) {
        int f = ++top;
        m[f] = m[rt];
        d[f] = d[rt] + e[u][i].se;
        l[f] = l[rt];
        r[f] = r[rt];
        f = add(f, 1, v + 1, tin[e[u][i].fi], tout[e[u][i].fi] + 1, -2 * e[u][i].se);
        dfs_trees(e[u][i].fi, u, f);
    }
}

int main() {
    int i, j, n, q, u, l, r, a, b, c;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (i = 2; i <= n; ++i) {
        cin >> b >> c;
        a = i;
        e[b].push_back({a, c});
    }
    for (i = 1; i <= n; ++i)
        sort(e[i].begin(), e[i].end());
    dfs(1, 0, 0);
    v = 1;
    while (v < n)
        v *= 2;
    build(0, 1, v + 1);
    top = 2 * v - 1;
    dfs_trees(1, 0, 0);
    for (i = 0; i < q; ++i) {
        cin >> u >> l >> r;
        cout << mn(root[u], 1, v + 1, l, r + 1) << "\n";
    }
}