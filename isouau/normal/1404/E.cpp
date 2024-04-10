#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7fffffff;

struct max_flow_t {
    struct edge_t {
        int u, v, next, cap, flow;
        edge_t () {}
        edge_t (int a, int b, int c, int d, int e) : u(a), v(b), next(c), cap(d), flow(e) {}
    };

    vector <edge_t> G;
    vector <int> head, nowhead, d;
    int n, s, t, tot;

    max_flow_t () { G.clear(); head.clear(); tot = 1; }
    max_flow_t (int nn) {
        n = nn; s = 0; t = n + 1;
        G.clear(); head.clear(); head.resize(n + 2, 0); tot = 1;
    }

    inline void addedge(int u, int v, int cap) {
        G.resize(tot + 3);
        G[++tot] = (edge_t) {u, v, head[u], cap, 0}, head[u] = tot;
        G[++tot] = (edge_t) {v, u, head[v], 0, 0}, head[v] = tot;
    }

    int bfs() {
        d.clear(); d.resize(n + 2, 0); d[s] = 1;
        queue <int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = head[u]; i; i = G[i].next) {
                int v = G[i].v;
                if (G[i].cap > G[i].flow && d[v] == 0) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t];
    }

    int dfs(int u, int Flow) {
        if (u == t || !Flow) return Flow;
        int flow = 0, f;
        for (int &i = nowhead[u]; i; i = G[i].next) {
            int v = G[i].v;
            if (d[v] == d[u] + 1 && (f = dfs(v, min(Flow, G[i].cap - G[i].flow))) > 0) {
                G[i].flow += f; G[i ^ 1].flow -= f;
                flow += f; Flow -= f;
                if (!Flow) break;
            }
        }
        return flow;
    }

    int dinic() {
        int ans = 0;
        while (bfs()) {
            nowhead = head;
            ans += dfs(s, INF);
        }
        return ans;
    }
} M;

const int N = 205;

int r[N][N], d[N][N];
char c[N][N];
int n, m, tot, cnt, qaq;

inline int s(int x, int y) { return (x - 1) * m + y; }

int main() {
    scanf("%d%d", &n, &m);
    M = max_flow_t(n * m * 3); tot = n * m;
    for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cnt += (c[i][j] == '.');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            int opt = (c[i][j] == '.' || c[i][j + 1] == '.');
            qaq += opt;
            if (!opt) M.addedge(M.s, ++tot, 1), M.addedge(tot, s(i, j), 1), M.addedge(tot, s(i, j + 1), 1);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            int opt = (c[i][j] == '.' || c[i + 1][j] == '.');
            qaq += opt;
            if (!opt) M.addedge(++tot, M.t, 1), M.addedge(s(i, j), tot, 1), M.addedge(s(i + 1, j), tot, 1);
        }
    }
    qaq += M.dinic();
    printf("%d\n", n * m - (n * (m - 1) + (n - 1) * m - qaq) - cnt);
    return 0;
}