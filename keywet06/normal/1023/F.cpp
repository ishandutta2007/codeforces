#include <bits/stdc++.h>

const int N = 500005;
const int M = 500005;

int n, k, m, fa[N];

int find(int i) { return fa[i] == i ? i : fa[i] = find(fa[i]); }

struct edge {
    int to, ty;
    edge* next;
} E[N * 2], *ne = E, *fir[N];

void link(int u, int v, int ty) {
    *ne = (edge){v, ty, fir[u]};
    fir[u] = ne++;
}

void link2(int u, int v, int ty) {
    link(u, v, ty);
    link(v, u, ty);
}

int a[M], b[M], val[M], cnt;
int f[N], d[N], res[N];

void dfs(int i) {
    for (edge* e = fir[i]; e; e = e->next) {
        if (e->to != f[i]) f[e->to] = i, d[e->to] = d[i] + 1, dfs(e->to);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    while (k--) {
        int u, v;
        std::cin >> u >> v;
        fa[find(u)] = find(v);
        link2(u, v, 0);
    }
    while (m--) {
        int u, v, w;
        std::cin >> u >> v >> w;
        if (find(u) == find(v)) {
            a[cnt] = u, b[cnt] = v, val[cnt++] = w;
        } else {
            fa[find(u)] = find(v), link2(u, v, 1);
        }
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 0; i < cnt; ++i) {
        int u = find(a[i]), v = find(b[i]);
        while (u != v) {
            if (d[u] > d[v]) {
                res[u] = val[i], fa[u] = find(f[u]), u = fa[u];
            } else {
                res[v] = val[i], fa[v] = find(f[v]), v = fa[v];
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (edge* e = fir[i]; e; e = e->next) {
            if (e->to == f[i] && !e->ty) {
                if (fa[i] == i) return puts("-1"), 0;
                ans += res[i];
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}