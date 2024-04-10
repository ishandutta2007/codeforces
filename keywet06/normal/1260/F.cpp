#include <bits/stdc++.h>

using namespace std;

constexpr int P = 1000000007, N = 100000;

void inc(int &a, int b) { (a += b) >= P ? a -= P : 0; }

void dec(int &a, int b) { (a -= b) < 0 ? a += P : 0; }

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = 1LL * result * base % P;
        base = 1LL * base * base % P;
        exp >>= 1;
    }
    return result;
}

struct Node {
    int f, g, h;
} t[262144];

void push(int p, int l, int r) {
    int mid = (l + r) / 2;
    inc(t[2 * p].f, t[p].f);
    inc(t[2 * p + 1].f, t[p].f);
    inc(t[2 * p].g, t[p].g);
    inc(t[2 * p + 1].g, (t[p].g + 1LL * (mid - l) * t[p].h) % P);
    inc(t[2 * p].h, t[p].h);
    inc(t[2 * p + 1].h, t[p].h);
    t[p].f = t[p].g = t[p].h = 0;
}

void rangeAdd(int p, int l, int r, int x, int y, int v) {
    if (l >= y || r <= x) return;
    if (l >= x && r <= y) {
        inc(t[p].f, v);
        return;
    }
    int mid = (l + r) / 2;
    push(p, l, r);
    rangeAdd(2 * p, l, mid, x, y, v);
    rangeAdd(2 * p + 1, mid, r, x, y, v);
}

void rangeAdd(int p, int l, int r, int x, int y, int fi, int d) {
    if (l >= y || r <= x) return;
    if (l >= x && r <= y) {
        inc(t[p].g, (fi + 1LL * (l - x) * d) % P);
        inc(t[p].h, d);
        return;
    }
    int mid = (l + r) / 2;
    push(p, l, r);
    rangeAdd(2 * p, l, mid, x, y, fi, d);
    rangeAdd(2 * p + 1, mid, r, x, y, fi, d);
}

int get1(int p, int l, int r, int x) {
    if (r - l == 1) return t[p].f;
    int mid = (l + r) / 2;
    push(p, l, r);
    if (x < mid) {
        return get1(2 * p, l, mid, x);
    } else {
        return get1(2 * p + 1, mid, r, x);
    }
}

int get2(int p, int l, int r, int x) {
    if (r - l == 1) return t[p].g;
    int mid = (l + r) / 2;
    push(p, l, r);
    if (x < mid) {
        return get2(2 * p, l, mid, x);
    } else {
        return get2(2 * p + 1, mid, r, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int total = 1;
    vector<vector<int>> ins(N), del(N);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r, --l, --r;
        total = 1LL * total * (r - l + 1) % P;
        p[i] = power(r - l + 1, P - 2);
        ins[l].push_back(i);
        del[r].push_back(i);
    }
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> parent(n, -1), sz(n), dep(n), top(n), in(n), out(n);
    int dfs_now = 0;
    function<void(int)> dfsSz = [&](int u) {
        if (parent[u] != -1) e[u].erase(find(e[u].begin(), e[u].end(), parent[u]));
        sz[u] = 1;
        for (int &v : e[u]) {
            dep[v] = dep[u] + 1;
            parent[v] = u;
            dfsSz(v);
            sz[u] += sz[v];
            if (sz[v] > sz[e[u][0]]) swap(v, e[u][0]);
        }
    };
    dfsSz(0);
    function<void(int)> dfsHLD = [&](int u) {
        in[u] = dfs_now++;
        for (int v : e[u]) {
            top[v] = v == e[u][0] ? top[u] : v;
            dfsHLD(v);
        }
        out[u] = dfs_now;
    };
    dfsHLD(0);
    int ans = 0, sum = 0, tot = 0;
    auto add = [&](int u, int val) {
        int v = -1, d = dep[u];
        inc(tot, val);
        while (u != -1) {
            if (v != -1) {
                rangeAdd(1, 0, n, in[u], in[v], 1LL * val * (d + 2LL * (P - dep[u])) % P);
                rangeAdd(1, 0, n, out[v], out[u], 1LL * val * (d + 2LL * (P - dep[u])) % P);
            } else {
                rangeAdd(1, 0, n, in[u], out[u], 1LL * val * (d + 2LL * (P - dep[u])) % P);
            }
            int t = top[u];
            rangeAdd(1, 0, n, in[t], in[u], 1LL * val * (d + 2LL * (P - dep[t])) % P, 2LL * (P - val) % P);
            v = t;
            u = parent[t];
        }
    };
    auto query = [&](int u) {
        int res = (1LL * dep[u] * tot + get1(1, 0, n, in[u])) % P;
        while (u != -1) {
            inc(res, get2(1, 0, n, in[u]));
            u = parent[top[u]];
        }
        return res;
    };
    for (int i = 0; i < 100000; ++i) {
        for (int u : ins[i]) {
            inc(sum, 1LL * p[u] * query(u) % P);
            add(u, p[u]);
        }
        inc(ans, sum);
        for (int u : del[i]) {
            add(u, P - p[u]);
            dec(sum, 1LL * p[u] * query(u) % P);
        }
    }
    cout << 1LL * ans * total % P << endl;
    return 0;
}