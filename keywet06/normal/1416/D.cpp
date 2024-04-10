#include <bits/stdc++.h>
struct DisjointSetUnion {
    std::vector<int> fa;
    DisjointSetUnion(int n) : fa(n, -1) {}
    int find(int x) {
        while (fa[x] >= 0 && fa[fa[x]] >= 0) x = fa[x] = fa[fa[x]];
        return fa[x] >= 0 ? fa[x] : x;
    }
    bool query(int x, int y) { return find(x) == find(y); }
    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        fa[x] += fa[y];
        fa[y] = x;
        return true;
    }
};
struct SegmentTree {
    int n;
    std::vector<std::pair<int, int>> mx;
    SegmentTree(int n) : n(n), mx(4 * n) {}
    void pull(int p) { mx[p] = std::max(mx[2 * p], mx[2 * p + 1]); }
    void modify(int p, int l, int r, int x, int v) {
        if (r - l == 1) {
            mx[p] = {v, x};
        } else {
            int m = (l + r) / 2;
            if (x < m) {
                modify(2 * p, l, m, x, v);
            } else {
                modify(2 * p + 1, m, r, x, v);
            }
            pull(p);
        }
    }
    void modify(int x, int v) { modify(1, 0, n, x, v); }
    std::pair<int, int> rangeMax(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) return {-1, -1};
        if (l >= x && r <= y) return mx[p];
        int m = (l + r) / 2;
        return std::max(rangeMax(2 * p, l, m, x, y),
                        rangeMax(2 * p + 1, m, r, x, y));
    }
    int query(int l, int r) { return rangeMax(1, 0, n, l, r).second; }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> p(n);
    std::vector<int> u(m), v(m), t(m);
    for (int i = 0; i < n; ++i) std::cin >> p[i];
    for (int i = 0; i < m; ++i) {
        std::cin >> u[i] >> v[i];
        --u[i], --v[i];
        t[i] = q;
    }
    std::vector<int> type(q), x(q), node(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> type[i] >> x[i];
        --x[i];
        if (type[i] == 2) t[x[i]] = i;
    }
    std::vector<int> lc(2 * n, -1), rc(2 * n, -1);
    int cur = n;
    DisjointSetUnion dsu(2 * n);
    for (int i = 0; i < m; ++i) {
        if (t[i] != q) continue;
        int a = dsu.find(u[i]), b = dsu.find(v[i]);
        if (a != b) {
            lc[cur] = a;
            rc[cur] = b;
            dsu.join(cur, a);
            dsu.join(cur, b);
            ++cur;
        }
    }
    for (int i = q - 1; i >= 0; --i) {
        if (type[i] == 1) {
            node[i] = dsu.find(x[i]);
        } else {
            int a = dsu.find(u[x[i]]), b = dsu.find(v[x[i]]);
            if (a != b) {
                lc[cur] = a;
                rc[cur] = b;
                dsu.join(cur, a);
                dsu.join(cur, b);
                ++cur;
            }
        }
    }
    int now = 0;
    std::vector<int> in(2 * n), out(2 * n), a(n);
    auto dfs = [&](auto dfs, int u) {
        in[u] = now;
        if (u < n) {
            a[now] = u;
            out[u] = ++now;
            return;
        }
        dfs(dfs, lc[u]);
        dfs(dfs, rc[u]);
        out[u] = now;
    };
    for (int i = 0; i < cur; ++i)
        if (dsu.find(i) == i) dfs(dfs, i);

    SegmentTree tr(n);
    for (int i = 0; i < n; ++i) tr.modify(in[i], p[i]);
    for (int i = 0; i < q; ++i) {
        if (type[i] == 2) continue;
        int s = tr.query(in[node[i]], out[node[i]]);
        std::cout << p[a[s]] << "\n";
        p[a[s]] = 0;
        tr.modify(s, 0);
    }

    return 0;
}