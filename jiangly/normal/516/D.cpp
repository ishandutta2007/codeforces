#include <bits/stdc++.h>
using namespace std;
template<typename T>
void cmax(T &a, const T &b) {
    if (a < b)
        a = b;
}
using LL = long long;
constexpr int MAX_N = 1E5;
int n;
vector<pair<int, int>> e[MAX_N];
LL down[MAX_N][2], up[MAX_N];
LL c[MAX_N];
int parent[MAX_N], fa[MAX_N], p[MAX_N];
void dfs1(int u, int p) {
    for (auto pr : e[u]) {
        int v, w;
        tie(v, w) = pr;
        if (v == p)
            continue;
        dfs1(v, u);
        LL x = down[v][0] + w;
        if (x > down[u][0])
            swap(x, down[u][0]);
        cmax(down[u][1], x);
    }
}
void dfs2(int u, int p) {
    for (auto pr : e[u]) {
        int v, w;
        tie(v, w) = pr;
        if (v == p)
            continue;
        up[v] = max(up[u], (down[v][0] + w == down[u][0] ? down[u][1] : down[u][0])) + w;
        dfs2(v, u);
    }
}
void dfs(int u) {
    for (int i = 0; i < e[u].size(); ++i) {
        int v, w;
        tie(v, w) = e[u][i];
        if (v == parent[u]) {
            swap(e[u][i], e[u].back());
            e[u].pop_back();
            --i;
            continue;
        }
        parent[v] = u;
        dfs(v);
    }
}
int find(int x) {
    while (fa[x] >= 0 && fa[fa[x]] >= 0)
        x = fa[x] = fa[fa[x]];
    return fa[x] >= 0 ? fa[x] : x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    for (int i = 0; i < n; ++i)
        c[i] = max(up[i], down[i][0]);
    int rt = min_element(c, c + n) - c;
    parent[rt] = -1;
    dfs(rt);
    iota(p, p + n, 0);
    sort(p, p + n, [&](int u, int v) {return c[u] > c[v] || v == rt;});
    int q;
    cin >> q;
    while (q--) {
        LL l;
        cin >> l;
        int ans = 0;
        fill(fa, fa + n, -2);
        for (int i = 0, j = 0; i < n; ++i) {
            for (auto pr : e[p[i]]) {
                int v = find(pr.first);
                int u = find(p[i]);
                if (fa[u] > fa[v])
                    swap(u, v);
                fa[u] += fa[v] + 1;
                fa[v] = u;
            }
            while (c[p[j]] - c[p[i]] > l) {
                ++fa[find(p[j])];
                ++j;
            }
            cmax(ans, -fa[find(p[i])] - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}