#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6e5;
int ans[MAXN];
vector<array<int, 2>> g[MAXN];
int p[MAXN], sz[MAXN];

int get(int v) {
    if (v == p[v]) {
        return p[v];
    }
    return p[v] = get(p[v]);
}

void join(int u, int v) {
    u = get(u); v = get(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
}

int d[MAXN];

vector<int> gg[MAXN];

void calc_d(int v) {
    sz[v] = 1;
    for (auto e : g[v]) {
        if (e[0] == p[v]) continue;
        p[e[0]] = v;
        gg[v].push_back(e[0]);
        d[e[0]] = d[v] + e[1];
        calc_d(e[0]);
        sz[v] += sz[e[0]];
    }
    int ind = 0;
    for (int i = 1; i < gg[v].size(); ++i) {
        if (sz[gg[v][i]] > sz[gg[v][ind]]) {
            ind = i;
        }
    }
    if (gg[v].size()) {
        swap(gg[v][0], gg[v][ind]);
    }
}

vector<int> euler;
int hld[MAXN];
int ind[MAXN];
int tim = 0;
int tin[MAXN], tout[MAXN];

void build_e(int v, int par = -1) {
    if (par == -1) par = v;
    ind[v] = euler.size();
    tin[v] = tim++;
    euler.push_back(v);
    hld[v] = par;
    if (gg[v].size()) {
        build_e(gg[v][0], par);
        for (int i = 1; i < gg[v].size(); ++i) {
            build_e(gg[v][i]);
        }
    }
    tout[v] = tim++;
}

int tree[4 * MAXN];
int add[4 * MAXN];

void push(int v) {
    tree[v] = max(tree[v], add[v]);
    add[v * 2] = max(add[v], add[v * 2]);
    add[v * 2 + 1] = max(add[v], add[v * 2 + 1]);
    add[v] = 0;
}

void pull(int v) {
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}

void update(int v, int vl, int vr, int l, int r) {
    push(v);
    if (l >= vr || r <= vl) {
        return;
    }
    if (l <= vl && r >= vr) {
        add[v] = 1;
        push(v);
        return;
    }
    int vm = (vl + vr) / 2;
    update(v * 2, vl, vm, l, r);
    update(v * 2 + 1, vm, vr, l, r);
    pull(v);
}

int get(int v, int vl, int vr, int l, int r) {
    push(v);
    if (l >= vr || r <= vl) {
        return 0;
    }
    if (l <= vl && r >= vr) {
        return tree[v];
    }
    int vm = (vl + vr) / 2;
    int res1 = get(v * 2, vl, vm, l, r);
    int res2 = get(v * 2 + 1, vm, vr, l, r);
    return max(res1, res2);
}

bool is_anc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int l = -1;

void update(int u, int v) {
    for (int i = 0; i < 2; ++i, swap(u, v)) {
        while (!is_anc(hld[u], v)) {
            update(1, 0, euler.size(), ind[hld[u]], ind[u] + 1);
            u = p[hld[u]];
        }
    }
    if (sz[u] < sz[v]) swap(u, v);
    update(1, 0, euler.size(), ind[u] + 1, ind[v] + 1);
}

int get(int u, int v) {
    int ans = 0;
    for (int i = 0; i < 2; ++i, swap(u, v)) {
        while (!is_anc(hld[u], v)) {
            ans = max(ans, get(1, 0, euler.size(), ind[hld[u]], ind[u] + 1));
            u = p[hld[u]];
        }
    }
    if (sz[u] < sz[v]) swap(u, v);
    l = u;
    ans = max(ans, get(1, 0, euler.size(), ind[u] + 1, ind[v] + 1));
    return ans;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        p[i] = i; sz[i] = 1;
    }
    vector<array<int, 4>> ed;
    for (int i = 0; i < m; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        u--; v--;
        if (get(u) != get(v)) {
            join(u, v);
            ans[i] = 1;
            g[u].push_back({v, x});
            g[v].push_back({u, x});
        } else {
            ed.push_back({u, v, x, i});
        }
    }
    /// cout << "d" << endl;
    fill(p, p + n, -1);
    vector<int> rts;
    for (int i = 0; i < n; ++i) {
        if (p[i] == -1) {
            /// cout << i << endl;
            calc_d(i);
            /// cout << i << endl;
            rts.push_back(i);
            build_e(i);
        }
    }
    /// cout << "e" << endl;
    for (auto elem : ed) {
        /// cout << elem[0] << " " << elem[1] << endl;
        int k = get(elem[0], elem[1]);
        /**if (elem[3] == 6) {
            cout << elem[0] << " " << elem[1] << endl;
            cout << k << endl;
        }*/
        if (k) {
            continue;
        }
        int u = elem[0], v = elem[1];
        int cnt = elem[2] + d[u] - d[l] + d[v] - d[l];
        if (cnt % 2 == 0) {
            continue;
        }
        ans[elem[3]] = 1;
        update(u, v);
    }
    for (int i = 0; i < m; ++i) {
        if (ans[i]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}