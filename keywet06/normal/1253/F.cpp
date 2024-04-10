#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 1e5, M = 3e5;
const int64 INF = 1e18;

int n, m, k, q;
int u[M], v[M], s[M], fa[N];
int parent[N][16], dep[N];

int64 dis[N], w[M];
int64 mx[N][16];

vector<pair<int, int64>> e[N];

int find(int x) {
    while (fa[x] >= 0 && fa[fa[x]] >= 0) x = fa[x] = fa[fa[x]];
    return fa[x] >= 0 ? fa[x] : x;
}

void dfs(int u) {
    for (int i = 1; (1 << i) <= dep[u]; ++i) {
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[parent[u][i - 1]][i - 1]);
    }
    for (auto ed : e[u]) {
        int v;
        int64 w;
        tie(v, w) = ed;
        if (v == parent[u][0]) continue;
        parent[v][0] = u;
        dep[v] = dep[u] + 1;
        mx[v][0] = w;
        dfs(v);
    }
}

int64 query(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int64 result = 0;
    for (int i = 15; i >= 0; --i) {
        if (dep[u] - (1 << i) >= dep[v]) {
            result = max(result, mx[u][i]);
            u = parent[u][i];
        }
    }
    if (u == v) return result;
    for (int i = 15; i >= 0; --i) {
        if ((1 << i) <= dep[u] && parent[u][i] != parent[v][i]) {
            result = max(result, max(mx[u][i], mx[v][i]));
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    result = max(result, max(mx[u][0], mx[v][0]));
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> q;
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> w[i], --u[i], --v[i];
        e[u[i]].emplace_back(v[i], w[i]);
        e[v[i]].emplace_back(u[i], w[i]);
    }
    priority_queue<pair<int64, int>> h;
    fill(dis + k, dis + n, INF);
    for (int i = 0; i < k; ++i) {
        s[i] = i;
        h.emplace(0, i);
    }
    while (!h.empty()) {
        int u;
        int64 d;
        tie(d, u) = h.top();
        d = -d;
        h.pop();
        if (d != dis[u]) continue;
        for (auto ed : e[u]) {
            int v;
            int64 w;
            tie(v, w) = ed;
            if (dis[v] > d + w) {
                dis[v] = d + w;
                s[v] = s[u];
                h.emplace(-dis[v], v);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        w[i] += dis[u[i]] + dis[v[i]];
        u[i] = s[u[i]];
        v[i] = s[v[i]];
    }
    iota(s, s + m, 0);
    sort(s, s + m, [&](int i, int j) { return w[i] < w[j]; });
    for (int i = 0; i < n; ++i) e[i].clear();
    memset(fa, -1, n * sizeof(int));
    for (int i = 0; i < m; ++i) {
        int x = find(u[s[i]]);
        int y = find(v[s[i]]);
        if (x == y) continue;
        if (fa[x] > fa[y]) swap(x, y);
        fa[x] += fa[y];
        fa[y] = x;
        e[u[s[i]]].emplace_back(v[s[i]], w[s[i]]);
        e[v[s[i]]].emplace_back(u[s[i]], w[s[i]]);
    }
    dfs(0);
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << query(--u, --v) << "\n";
    }
    return 0;
}