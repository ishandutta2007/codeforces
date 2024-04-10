#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 5E5, MAX_M = 5E5, MAX_K = 50, MAX_Q = 5E5;
int n, m, k, q;
int u[MAX_M], v[MAX_M], e[MAX_Q], c[MAX_Q];
int color[MAX_M], nxt[MAX_Q], lst[MAX_M];
vector<pair<int, int>> f[4 * MAX_Q];
class DSU {
private:
    int fa[MAX_N], d[MAX_N];
    stack<pair<int *, int>> stk;
    pair<int, int> find(int x) {
        int y = 0;
        while (fa[x] >= 0) {
            y ^= d[x];
            x = fa[x];
        }
        return {x, y};
    }
public:
    DSU() {
        memset(fa, -1, sizeof(fa));
        memset(d, 0, sizeof(d));
    }
    bool canLink(int u, int v) {
        int x, du, y, dv;
        tie(x, du) = find(u);
        tie(y, dv) = find(v);
        return x != y || du != dv;
    }
    void link(int u, int v) {
        int x, du, y, dv;
        tie(x, du) = find(u);
        tie(y, dv) = find(v);
        if (x == y) {
            stk.emplace(nullptr, 0);
            assert(du != dv);
            return;
        }
        if (fa[x] < fa[y]) {
            stk.emplace(&fa[x], fa[x]);
            fa[x] += fa[y];
            stk.emplace(&d[y], d[y]);
            d[y] = du ^ dv ^ 1;
            stk.emplace(&fa[y], fa[y]);
            fa[y] = x;
        } else {
            stk.emplace(&fa[y], fa[y]);
            fa[y] += fa[x];
            stk.emplace(&d[u], d[u]);
            d[x] = du ^ dv ^ 1;
            stk.emplace(&fa[x], fa[x]);
            fa[x] = y;
        }
    }
    void cancel() {
        if (stk.top().first == nullptr) {
            stk.pop();
            return;
        }
        for (int i = 0; i < 3; ++i) {
            int *p, v;
            tie(p, v) = stk.top();
            *p = v;
            stk.pop();
        }
    }
} s[MAX_K];
void cover(int p, int l, int r, int x, int y, int e, int c) {
    if (l >= y || r <= x)
        return;
    if (l >= x && r <= y) {
        f[p].emplace_back(e, c);
        return;
    }
    int mid = (l + r) / 2;
    cover(2 * p, l, mid, x, y, e, c);
    cover(2 * p + 1, mid, r, x, y, e, c);
}
void solve(int p, int l, int r) {
    for (auto x : f[p]) {
        int e, c;
        tie(e, c) = x;
        s[c].link(u[e], v[e]);
    }
    if (r - l == 1) {
        if (s[c[l]].canLink(u[e[l]], v[e[l]])) {
            cout << "YES" << "\n";
            color[e[l]] = c[l];
        } else
            cout << "NO" << "\n";
        if (color[e[l]] != -1)
            cover(1, 0, q, r, nxt[l], e[l], color[e[l]]);
    } else {
        int mid = (l + r) / 2;
        solve(2 * p, l, mid);
        solve(2 * p + 1, mid, r);
    }
    for (auto x : f[p]) {
        int e, c;
        tie(e, c) = x;
        s[c].cancel();
    }
}
int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    cin >> n >> m >> k >> q;
    memset(color, -1, m * sizeof(int));
    memset(lst, -1, m * sizeof(int));
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
        --u[i];
        --v[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> e[i] >> c[i];
        --e[i];
        --c[i];
        if (lst[e[i]] != -1)
            nxt[lst[e[i]]] = i;
        lst[e[i]] = i;
        nxt[i] = q;
    }
    solve(1, 0, q);
    return 0;
}