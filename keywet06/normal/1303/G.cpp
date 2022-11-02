#include <bits/stdc++.h>

struct Line {
    long long k, b;
    Line(long long k = 0, long long b = std::numeric_limits<long long>::min())
        : k(k), b(b) {}
};

long long f(const Line &line, int x) { return line.k * x + line.b; }

struct Node {
    Node *lc, *rc;
    Line line;
    Node() : lc(nullptr), rc(nullptr) {}
};

Node *rt;

void addLine(Node *&p, int l, int r, Line line) {
    if (p == nullptr) p = new Node;
    int m = (l + r) / 2;
    bool fm = f(line, m) > f(p->line, m);
    bool fl = f(line, l) > f(p->line, l);
    if (fm) std::swap(p->line, line);
    if (r - l == 1) {
        return;
    } else if (fl != fm) {
        addLine(p->lc, l, m, line);
    } else {
        addLine(p->rc, m, r, line);
    }
}

long long queryMax(Node *p, int l, int r, int x) {
    if (p == nullptr) return std::numeric_limits<long long>::min();
    int m = (l + r) / 2;
    long long res = f(p->line, x);
    if (x < m) {
        res = std::max(res, queryMax(p->lc, l, m, x));
    } else {
        res = std::max(res, queryMax(p->rc, m, r, x));
    }
    return res;
}

int n;

long long ans;

std::vector<bool> vis;
std::vector<int> a, sz;
std::vector<std::vector<int>> e;

void dfsSz(int u, int p) {
    sz[u] = 1;
    for (int v : e[u]) {
        if (vis[v] || v == p) continue;
        dfsSz(v, u);
        sz[u] += sz[v];
    }
}

int findCen(int u, int p, int tot) {
    for (int v : e[u]) {
        if (vis[v] || v == p) continue;
        if (2 * sz[v] > tot) return findCen(v, u, tot);
    }
    return u;
}

void dfsQuery(int u, int p, int d, long long s, long long f) {
    ++d,
    s += a[u],
    f += s;
    ans = std::max(ans, queryMax(rt, 0, n, d) + f);
    for (int v : e[u]) {
        if (vis[v] || v == p) continue;
        dfsQuery(v, u, d, s, f);
    }
}

void dfsUpdate(int u, int p, int d, long long s, long long f) {
    ++d, s += a[u];
    f += 1LL * d * a[u];
    addLine(rt, 0, n, Line(s, f));
    for (int v : e[u]) {
        if (vis[v] || v == p) continue;
        dfsUpdate(v, u, d, s, f);
    }
}

void work(int u) {
    dfsSz(u, -1);
    u = findCen(u, -1, sz[u]);
    vis[u] = true;
    rt = nullptr;
    addLine(rt, 0, n, Line(a[u], a[u]));
    for (int v : e[u]) {
        if (vis[v]) continue;
        dfsQuery(v, -1, 0, 0, 0);
        dfsUpdate(v, -1, 1, a[u], a[u]);
    }
    std::reverse(e[u].begin(), e[u].end());
    rt = nullptr;
    for (int v : e[u]) {
        if (vis[v]) continue;
        dfsQuery(v, -1, 0, 0, 0);
        dfsUpdate(v, -1, 1, a[u], a[u]);
    }
    ans = std::max(ans, queryMax(rt, 0, n, 0));
    for (int v : e[u]) {
        if (!vis[v]) work(v);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    e.resize(n), a.resize(n);
    sz.resize(n), vis.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v, --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    work(0);
    std::cout << ans << "\n";
    return 0;
}