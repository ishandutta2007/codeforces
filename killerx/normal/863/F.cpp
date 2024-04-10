#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct MinCostFlow {
    static const int mxn = 105;

    struct Edge {
        int v, w, c, r;
    };

    int n, S, T;
    std::vector <Edge> adj[mxn];
    int dis[mxn], que[mxn], ql, qr;
    bool inq[mxn];
    int prv[mxn], pre[mxn];

    void init(int _n, int _S, int _T) {
        n = _n, S = _S, T = _T;
        rep(i, n) adj[i].clear();
    }

    inline void add_edge(int u, int v, int w, int c) {
        adj[u].push_back({v, w, c, (int) adj[v].size()});
        adj[v].push_back({u, 0, -c, (int) adj[u].size() - 1});
    }

    bool spfa() {
        ql = qr = 0, que[qr ++] = S;
        rep(i, n) dis[i] = i == S ? 0 : 0x3f3f3f3f;
        rep(i, n) inq[i] = i == S ? true : false;
        while (ql != qr) {
            int u = que[ql ++]; inq[u] = false; if (ql == mxn) ql = 0;
            rep(i, adj[u].size()) {
                Edge e = adj[u][i];
                if (e.w && dis[e.v] > dis[u] + e.c) {
                    dis[e.v] = dis[u] + e.c;
                    prv[e.v] = u;
                    pre[e.v] = i;
                    if (!inq[e.v]) {
                        inq[e.v] = true;
                        que[qr ++] = e.v; if (qr == mxn) qr = 0;
                    }
                }
            }
        }
        return dis[T] < 1e9;
    }

    int solve() {
        int ans = 0;
        while (spfa()) {
            int f = 0x3f3f3f3f;
            for (int u = T; u != S; u = prv[u])
                f = std::min(f, adj[prv[u]][pre[u]].w);
            ans += f * dis[T];
            for (int u = T; u != S; u = prv[u]) {
                adj[prv[u]][pre[u]].w -= f;
                adj[u][adj[prv[u]][pre[u]].r].w += f;
            }
        }
        return ans;
    }
} mcf;

const int mxn = 55;

int n, q;
int min[mxn], max[mxn];

int main() {
    scanf("%d %d", &n, &q);
    rep(i, n) max[i] = 0, max[i] = n - 1;
    rep(i, q) {
        int tp, l, r, v;
        scanf("%d %d %d %d", &tp, &l, &r, &v);
        -- l, -- r, -- v;
        for (int x = l; x <= r; ++ x) {
            if (tp == 1) min[x] = std::max(min[x], v);
            else max[x] = std::min(max[x], v);
        }
    }
    int S = n * 2, T = n * 2 + 1;
    mcf.init(n * 2 + 2, S, T);
    rep(i, n) for (int j = 1; j <= n; ++ j) mcf.add_edge(S, i, 1, j * j - (j - 1) * (j - 1));
    rep(i, n) mcf.add_edge(i + n, T, 1, 0);
    rep(i, n) if (min[i] <= max[i]) for (int j = min[i]; j <= max[i]; ++ j) mcf.add_edge(j, i + n, 1, 0);
    else { printf("-1\n"); return 0; }
    printf("%d\n", mcf.solve());
    return 0;
}