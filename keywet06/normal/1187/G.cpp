#include <bits/stdc++.h>

using namespace std;

const int V = 6e3, E = 6e5;
const int INF = 1e9;

class Edge {
   public:
    int to;
    int f;
    int c;
    int next;
};

bool vis[V];

int n, m, k, c, d, Cno, Ced;
int head[V], dis[V], from[V], h[V];

pair<int, int> e[55];

Edge edge[E * 2];

void insert(int u, int v, int f, int c) {
    edge[Ced] = {v, f, c, head[u]};
    head[u] = Ced++;
    edge[Ced] = {u, -f, 0, head[v]};
    head[v] = Ced++;
}

bool dijkstra(int s, int t) {
    for (int i = 1; i <= Cno; ++i) {
        dis[i] = INF;
        vis[i] = false;
        from[i] = -1;
    }
    dis[s] = 0;
    while (true) {
        int u = 0, d = INF;
        for (int i = 1; i <= Cno; ++i) {
            if (!vis[i] && dis[i] < d) {
                u = i;
                d = dis[i];
            }
        }
        if (u == 0) {
            break;
        }
        vis[u] = true;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            if (!vis[edge[i].to] && edge[i].c > 0 &&
                dis[edge[i].to] + h[edge[i].to] >= dis[u] + h[u] + edge[i].f) {
                dis[edge[i].to] = dis[u] + h[u] + edge[i].f - h[edge[i].to];
                from[edge[i].to] = i;
            }
        }
    }
    for (int i = 1; i <= Cno; ++i) {
        h[i] = min(h[i] + dis[i], INF);
    }
    return dis[t] != INF;
}

int MCMF(int s, int t) {
    int cost = 0;
    while (dijkstra(s, t)) {
        int mn = INF;
        for (int u = t; u != s; u = edge[from[u] ^ 1].to) {
            mn = min(mn, edge[from[u]].c);
        }
        cost += mn * h[t];
        for (int u = t; u != s; u = edge[from[u] ^ 1].to) {
            edge[from[u]].c -= mn;
            edge[from[u] ^ 1].c += mn;
        }
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(head, -1, sizeof(head));
    cin >> n >> m >> k >> c >> d;
    int s = n * (n + k) + 1;
    int t = s + 1;
    Cno = t;
    for (int i = 1; i <= k; ++i) {
        int a;
        cin >> a;
        insert(s, a, 0, 1);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].first >> e[i].second;
    }
    int ss = clock();
    for (int tim = 0; tim <= n + k - 2; ++tim) {
        for (int i = 1; i <= n; ++i) {
            insert(tim * n + i, (tim + 1) * n + i, c, k);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= k; ++j) {
                insert(tim * n + e[i].first, (tim + 1) * n + e[i].second,
                           d * (j * 2 - 1) + c, 1);
                insert(tim * n + e[i].second, (tim + 1) * n + e[i].first,
                           d * (j * 2 - 1) + c, 1);
            }
        }
        insert((tim + 1) * n + 1, t, 0, k);
    }
    cout << MCMF(s, t) << endl;
    return 0;
}