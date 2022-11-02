#include <bits/stdc++.h>

using int64 = long long;

const int N = 60005;
const int M = 100005;

const int64 INF = 1e9;

struct edge {
    int to, rev, flow;
};

int n, m, S, T, cur[N], dis[N], out[N], in[N], tot;
int s[M], a[M], ours[M], X[M], Y[M], id[M];

std::vector<edge> g[N];

void Add(int x, int y, int z) {
    g[x].push_back({y, (int)g[y].size(), z});
    g[y].push_back({x, (int)g[x].size() - 1, 0});
}

void add(int x, int y, int z, int w) { Add(x, y, w - z), out[x] += z, in[y] += z; }

bool bfs(int s, int t) {
    memset(dis, -1, sizeof(dis));
    std::queue<int> q;
    q.push(s), dis[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (edge i : g[x]) {
            if (!i.flow) continue;
            int y = i.to;
            if (dis[y] == -1) dis[y] = dis[x] + 1, q.push(y);
        }
    }
    return dis[t] != -1;
}

int64 dfs(int x, int t, int64 fl) {
    if (x == t || !fl) return fl;
    int64 ret = 0;
    for (int &i = cur[x]; i < g[x].size(); ++i) {
        int y = g[x][i].to;
        if (!g[x][i].flow || dis[y] != dis[x] + 1) continue;
        int64 w = dfs(y, t, std::min(fl, (int64)g[x][i].flow));
        g[x][i].flow -= w, g[y][g[x][i].rev].flow += w, ret += w, fl -= w;
        if (!fl) return ret;
    }
    return ret;
}

int64 Dinic(int s, int t) {
    int64 ans = 0;
    while (bfs(s, t)) memset(cur, 0, sizeof(cur)), ans += dfs(s, t, INF);
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> s[i];
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1, x, y; i <= m; ++i) std::cin >> x >> y, X[i] = x, Y[i] = y, --ours[x], ++ours[y];
    tot = n, S = ++tot, T = ++tot;
    Add(T, S, INF);
    for (int i = 1; i <= n; ++i) {
        if (!s[i] && (Add(S, i, INF), Add(i, T, INF), true)) continue;
        if (abs(ours[i] - a[i]) % 2) return std::cout << "NO" << '\n', 0;
        if (a[i] >= ours[i]) {
            add(S, i, abs(a[i] - ours[i]) / 2, abs(a[i] - ours[i]) / 2);
        } else {
            add(i, T, abs(a[i] - ours[i]) / 2, abs(a[i] - ours[i]) / 2);
        }
    }
    for (int i = 1; i <= m; ++i) Add(X[i], Y[i], 1), id[i] = g[X[i]].size() - 1;
    int tS = tot + 1, tT = tot + 2, sum = 0;
    for (int i = 1; i <= tot; ++i) {
        out[i] > in[i] ? Add(i, tT, out[i] - in[i]), sum += out[i] - in[i] : (Add(tS, i, in[i] - out[i]), 0);
    }
    if (Dinic(tS, tT) != sum) return std::cout << "NO" << '\n', 0;
    std::cout << "YES" << '\n';
    for (int i = 1; i <= m; ++i) {
        if (g[X[i]][id[i]].flow) {
            std::cout << X[i] << ' ' << Y[i] << '\n';
        } else {
            std::cout << Y[i] << ' ' << X[i] << '\n';
        }
    }
    return 0;
}