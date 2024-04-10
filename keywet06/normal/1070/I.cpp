#include <bits/stdc++.h>

using namespace std;

namespace Dinic {

const int INF = int(1e9) + int(1e8);

const int N = 2200;
const int M = 11000;

int V, E;
int fst[N], nxt[M], to[M], cap[M], dis[N], q[N], ptr[N];

void init() { memset(fst, -1, sizeof(fst)), V = E = 0; }
inline int add_node() { return V++; }
inline void add_edge(int u, int v, int c) {
    to[E] = v, cap[E] = c, nxt[E] = fst[u], fst[u] = E++;
    to[E] = u, cap[E] = 0, nxt[E] = fst[v], fst[v] = E++;
}
inline bool bfs(int S, int T, int n) {
    memset(dis, -1, sizeof(int) * n);
    int h = 0, t = 0;
    dis[S] = 0, q[t++] = S;
    while (h < t) {
        int u = q[h++];
        for (int e = fst[u]; ~e; e = nxt[e]) {
            if (cap[e] > 0 && dis[to[e]] == -1) {
                dis[to[e]] = dis[u] + 1, q[t++] = to[e];
                if (to[e] == T) return 1;
            }
        }
    }
    return (dis[T] != -1);
}
int dfs(int u, int T, int f) {
    if (u == T) return f;
    for (int &e = ptr[u]; ~e; e = nxt[e]) {
        if (cap[e] > 0 && dis[to[e]] > dis[u]) {
            int ret = dfs(to[e], T, min(f, cap[e]));
            if (ret > 0) {
                cap[e] -= ret, cap[e ^ 1] += ret;
                return ret;
            }
        }
    }
    return 0;
}
int max_flow(int S, int T, int n = V) {
    int ret = 0;
    while (bfs(S, T, n)) {
        memcpy(ptr, fst, sizeof(int) * n);
        for (int cur; (cur = dfs(S, T, INF)) > 0; ret += cur)
            ;
    }
    return ret;
}

}  // namespace Dinic

const int N = 660;

vector<int> adj[N], con[N];
int a[N], b[N], c[N];

int main() {
    ios::sync_with_stdio(0);
    int ncase;
    for (cin >> ncase; ncase--;) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 1; i <= m; ++i) {
            cin >> a[i] >> b[i];
            c[i] = 0;
            adj[a[i]].push_back(i);
            adj[b[i]].push_back(i);
        }
        auto print = [&]() {
            for (int i = 1; i <= m; ++i) cout << c[i] << ' ';
            cout << endl;
        };
        int okay = 1;
        for (int i = 1; i <= n; ++i) okay &= (adj[i].size() <= 2 * k);
        if (!okay) {
            print();
            continue;
        }
        Dinic::init();
        int tot = 0;
        for (int i = 1; i <= n; ++i)
            if (adj[i].size() > k) {
                Dinic::add_edge(0, i, 2 * (adj[i].size() - k));
                tot += 2 * (adj[i].size() - k);
                for (int j : adj[i]) Dinic::add_edge(i, n + j, 1);
            }
        for (int i = 1; i <= m; ++i) Dinic::add_edge(n + i, n + m + 1, 1);
        if (Dinic::max_flow(0, n + m + 1, n + m + 2) != tot) {
            print();
            continue;
        }
        for (int i = 1; i <= n; ++i) con[i].clear();
        for (int i = 0; i < Dinic::E; i += 2) {
            int u = Dinic::to[i ^ 1], v = Dinic::to[i], w = Dinic::cap[i ^ 1];
            if (w) {
                if (u == 0 || v == n + m + 1) continue;
                con[u].push_back(v - n);
            }
        }
        int cur = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < con[i].size(); j += 2) {
                c[con[i][j]] = c[con[i][j + 1]] = ++cur;
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (!c[i]) c[i] = ++cur;
        }
        print();
    }
    return 0;
}