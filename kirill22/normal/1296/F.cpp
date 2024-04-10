#include<bits/stdc++.h>

using namespace std;

int n, id = 0;
vector<vector<int>> g;
vector<int> sz, h, parent, first, ID, t, d;
vector<pair<int, int>> R;

void prec(int v, int pr) {
    for (auto u : g[v]) {
        if (u != pr) {
            prec(u, v);
            sz[v] += sz[u];
        }
    }
}

void dfs(int v, int pr, int root) {
    ID[v] = id; id++;
    first[ID[v]] = ID[root];
    if (pr != -1) {
        h[ID[v]] = h[ID[pr]] + 1;
        parent[ID[v]] = ID[pr];
    }
    int j = -1;
    for (auto u : g[v]) {
        if (u != pr && sz[u] * 2 >= sz[v]) {
            j = u;
        }
    }
    if (j != -1) {
        dfs(j, v, root);
    }
    for (auto u : g[v]) {
        if (u != pr && u != j) {
            dfs(u, v, u);
        }
    }
}

void push(int v) {
    if (v * 2 + 1 < 4 * n) {
        t[v * 2 + 1] = max(t[v * 2 + 1], d[v]);
        d[v * 2 + 1] = max(d[v * 2 + 1], d[v]);
    }
    if (v * 2 + 2 < 4 * n) {
        t[v * 2 + 2] = max(t[v * 2 + 2], d[v]);
        d[v * 2 + 2] = max(d[v * 2 + 2], d[v]);
    }
    d[v] = 1;
}

void update(int v, int l, int r, int l1, int r1, int k) {
    if (l >= r1 || l1 >= r) return;
    if (l == l1 && r == r1) {
        t[v] = max(t[v], k);
        d[v] = max(d[v], k);
        return;
    }
    push(v);
    int m = (l + r) / 2;
    update(v * 2 + 1, l, m, l1, min(r1, m), k);
    update(v * 2 + 2, m, r, max(l1, m), r1, k);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}


int get(int v, int l, int r, int l1, int r1) {
    if (l >= r1 || l1 >= r) return 1e7;
    if (l == l1 && r == r1) return t[v];
    int m = (l + r) / 2;
    int res = get(2 * v + 1, l, m, l1, min(r1, m));
    int res2 = get(v * 2 + 2, m, r, max(l1, m), r1);
    return min(res, res2);
}

void upd(int x, int y, int k) {
    while (true) {
        if (x == y) break;
        if (first[x] == first[y]) {
            if (x < y) swap(x, y);
            update(0, 0, n, y + 1, x + 1, k);
            break;
        }
        if (h[first[x]] < h[first[y]]) swap(x, y);
        update(0, 0, n, first[x], x + 1, k);
        x = parent[first[x]];
    }
}

int ans(int x, int y) {
    int res = 1e7;
    while (true) {
        if (first[x] == first[y]) {
            if (x < y) swap(x, y);
            res = min(res, get(0, 0, n, y + 1, x + 1));
            break;
        }
        if (h[first[x]] < h[first[y]]) swap(x, y);
        res = min(res, get(0, 0, n, first[x], x + 1));
        x = parent[first[x]];
    }
    return res;
}


void new_build(int v, int l, int r) {
    if (l + 1 == r) {
        return;
    }
    push(v);
    int m = (l + r) / 2;
    new_build(2 * v + 1, l, m);
    new_build(2 * v + 2, m, r);
    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

signed main() {
    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        R.push_back({x - 1, y - 1});
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    sz.resize(n, 1);
    prec(0, -1);
    ID.resize(n, 0);
    parent.resize(n, -1);
    first.resize(n, 0);
    h.resize(n, 0);
    dfs(0, -1, 0);
    t.resize(4 * n, 1);
    d.resize(4 * n, 1);
    int q;
    cin >> q;
    vector<int> X, Y, K;
    while (q--) {
        int x, y, k;
        cin >> x >> y >> k;
        X.push_back(x);
        Y.push_back(y);
        K.push_back(k);
        x = ID[x - 1];
        y = ID[y - 1];
        upd(x, y, k);
    }
    new_build(0, 0, n);
    for (int i = 0; i < X.size(); i++) {
        int x = X[i], y = Y[i], k = K[i];
        x = ID[x - 1];
        y = ID[y - 1];
        int t = ans(x, y);
        if (t != k) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int x = R[i].first, y = R[i].second;
        x = ID[x];
        y = ID[y];
        if (h[x] < h[y]) swap(x, y);
        cout << get(0, 0, n, x, x + 1) << " ";
    }
}