#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct MinCostFlow {
    struct Edge {
        int v, w, c, r;

        Edge(int _v, int _w, int _c, int _r): v(_v), w(_w), c(_c), r(_r) { }
    };

    vector <Edge> g[6005];
    int deg[6005], dis[6005], ndis[6005], prv[6005], pre[6005];
    int que[6005], ql, qr;
    priority_queue <pair <int, int> > pq;

    void add_edge(int u, int v, int w, int c) {
        g[u].pb(Edge(v, w, c, g[v].size()));
        g[v].pb(Edge(u, 0, -c, g[u].size() - 1));
    }

    void prep(int S, int T) {
        memset(dis, 0x3f, sizeof(dis)); dis[S] = 0;
        ql = qr = 0;
        rep(i, 6005) rep(j, g[i].size()) {
            int v = g[i][j].v;
            int w = g[i][j].w;
            int c = g[i][j].c;
            if (w) ++ deg[v];
        }
        rep(i, 6005) if (!deg[i]) que[qr ++] = i;
        while (ql < qr) {
            int u = que[ql ++];
            rep(i, g[u].size()) {
                int v = g[u][i].v;
                int w = g[u][i].w;
                int c = g[u][i].c;
                if (w) {
                    dis[v] = min(dis[v], dis[u] + c);
                    if (-- deg[v] == 0) que[qr ++] = v;
                }
            }
        }
    }

    bool dij(int S, int T) {
        memset(ndis, 0x3f, sizeof(ndis)); ndis[S] = 0;
        pq.push(mp(-ndis[S], S));
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = -pq.top().first;
            pq.pop();
            if (d != ndis[u]) continue;
            rep(i, g[u].size()) {
                int v = g[u][i].v;
                int w = g[u][i].w;
                int c = g[u][i].c;
                if (w && ndis[v] > d + c + dis[u] - dis[v]) {
                    ndis[v] = d + c + dis[u] - dis[v];
                    prv[v] = u;
                    pre[v] = i;
                    pq.push(mp(-ndis[v], v));
                }
            }
        }
        rep(i, 6005) dis[i] += ndis[i];
        return dis[T] < 1e9;
    }

    int flow(int S, int T) {
        prep(S, T);
        int ans = 0;
        while (dij(S, T)) {
            int f = 1e9 + 7;
            for (int u = T; u != S; u = prv[u])
                f = min(f, g[prv[u]][pre[u]].w);
            ans += f * dis[T];
            for (int u = T; u != S; u = prv[u]) {
                g[prv[u]][pre[u]].w -= f;
                g[u][g[prv[u]][pre[u]].r].w += f;
            }
        }
        return ans;
    }
};

int n, a[3005];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);
    MinCostFlow mcf;
    int S = n << 1, T = S + 1, nS = T + 1;
    mcf.add_edge(S, nS, 4, 0);
    rep(i, n) {
        mcf.add_edge(i << 1, i << 1 | 1, 1, -1);
        mcf.add_edge(nS, i << 1, 1, 0);
        mcf.add_edge(i << 1 | 1, T, 1, 0);
    }
    rep(j, n) rep(i, j) if (abs(a[i] - a[j]) == 1 || a[i] % 7 == a[j] % 7)
        mcf.add_edge(i << 1 | 1, j << 1, 1, 0);
    printf("%d\n", -mcf.flow(S, T));
    return 0;
}