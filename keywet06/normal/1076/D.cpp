#include <bits/stdc++.h>

using int64 = long long;

using Pi5 = std::pair<int64, int64>;
using Pi4 = std::pair<int, int>;

const int N = 3e5 + 7;
const int M = 1e9 + 7;
const int64 INF = 1e18 + 9LL;

bool vis[N];

int n, m, k;

int64 dist[N];

Pi4 p[N];

std::vector<int> res;

std::vector<Pi4> T[N];

std::vector<std::pair<Pi4, int> > G[N];

void Dijkstra(int s) {
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    dist[s] = 0;
    std::priority_queue<Pi5> Q;
    Q.push({0, s});
    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        if (p[u].first > 0) T[p[u].first].push_back({u, p[u].second});
        for (auto v : G[u])
            if (dist[v.first.first] > dist[u] + v.first.second) {
                dist[v.first.first] = dist[u] + v.first.second;
                p[v.first.first] = {u, v.second};
                Q.push({-dist[v.first.first], v.first.first});
            }
    }
}

void dfs(int u) {
    for (auto v : T[u]) {
        if ((int)res.size() < k) res.push_back(v.second);
        dfs(v.first);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        G[u].push_back({{v, c}, i});
        G[v].push_back({{u, c}, i});
    }
    Dijkstra(1);
    dfs(1);
    printf("%d\n", (int)res.size());
    for (int v : res) printf("%d ", v);
    printf("\n");
    return 0;
}