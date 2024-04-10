#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct Edge {
    int v, w, r;
};

struct MaxFlow {
    static const int mxn = 205;
    int n, S, T;
    std::vector <Edge> adj[mxn];
    int dis[mxn], que[mxn], ql, qr;
    int id[mxn];

    void init(int _n, int _S, int _T) {
        n = _n, S = _S, T = _T;
        rep(i, n) adj[i].clear();
    }

    void add_edge(int u, int v, int w) {
        adj[u].push_back({v, w, (int) adj[v].size()});
        adj[v].push_back({u, 0, (int) adj[u].size() - 1});
    }

    bool bfs() {
        rep(i, n) dis[i] = i == S ? 0 : -1;
        ql = qr = 0, que[qr ++] = S;
        while (ql < qr) {
            int u = que[ql ++];
            for (Edge e : adj[u]) {
                if (e.w && dis[e.v] == -1) {
                    dis[e.v] = dis[u] + 1;
                    que[qr ++] = e.v;
                }
            }
        }
        return dis[T] != -1;
    }

    int dfs(int u, int f = 0x3f3f3f3f) {
        if (u == T) return f;
        int flow = 0;
        for (int &i = id[u]; i < (int) adj[u].size(); ++ i) {
            Edge e = adj[u][i];
            if (e.w && dis[e.v] == dis[u] + 1) {
                int d = dfs(e.v, std::min(f, e.w));
                if (d) {
                    adj[u][i].w -= d;
                    adj[e.v][adj[u][i].r].w += d;
                    flow += d, f -= d;
                    if (f == 0) break;
                }
            }
        }
        return flow;
    }

    int solve() {
        int ans = 0;
        while (bfs()) {
            rep(i, n) id[i] = 0;
            ans += dfs(S);
        }
        return ans;
    }
} mf;

struct PrimeChecker {
    static const int mxn = 2e5 + 5;
    bool is_p[mxn];

    PrimeChecker() {
        for (int i = 2; i < mxn; ++ i) is_p[i] = true;
        for (int i = 2; i * i < mxn; ++ i) if (is_p[i])
            for (int j = i * i; j < mxn; j += i) is_p[j] = false;
    }

    bool check(int x) { return is_p[x]; }
} pc;

const int mxn = 105;

int n, K;
int p[mxn], c[mxn], l[mxn];
bool have[mxn];
int mn1 = -1;
int ans;

void add(int i) {
    have[i] = true;
    if (c[i] == 1) {
        if (mn1 == -1 || p[mn1] < p[i]) {
            if (mn1 != -1) have[mn1] = false;
            mn1 = i;
        } else have[i] = false;
    }
    int sum = 0;
    int S = n, T = n + 1;
    mf.init(n + 2, S, T);
    rep(i, n) if (have[i]) {
        sum += p[i];
        if (c[i] % 2 == 1) mf.add_edge(S, i, p[i]);
        else mf.add_edge(i, T, p[i]);
    }
    rep(i, n) if (have[i]) {
        if (c[i] % 2 == 1) {
            rep(j, n) if (have[j]) {
                if (c[j] % 2 == 0) {
                    if (pc.check(c[i] + c[j])) {
                        mf.add_edge(i, j, 0x3f3f3f3f);
                    }
                }
            }
        }
    }
    ans = sum - mf.solve();
}

int main() {
    scanf("%d %d", &n, &K);
    static int id[mxn];
    rep(i, n) scanf("%d %d %d", &p[i], &c[i], &l[i]), id[i] = i;
    std::sort(id, id + n, [&] (int i, int j) { return l[i] < l[j]; });
    rep(i, n) {
        add(id[i]);
        if (ans >= K) {
            printf("%d\n", l[id[i]]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}