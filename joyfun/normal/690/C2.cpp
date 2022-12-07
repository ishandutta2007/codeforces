#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;

int n, m;
vector<int> g[N];
int vis[N], d[N];
queue<int> Q;

int bfs(int u) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) d[i] = INF;
    d[u] = 0;
    Q.push(u);
    vis[u] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (vis[v]) continue;
            vis[v] = 1;
            d[v] = d[u] + 1;
            Q.push(v);
        }
    }
    int ans = -1, ansv;
    for (int i = 1; i <= n; i++) {
        if (d[i] != INF) {
            if (d[i] > ans) {
                ans = d[i];
                ansv = i;
            }
        }
    }
    return ansv;
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int s = bfs(i);
            ans = max(ans, d[bfs(s)]);
        }
    }
    printf("%d\n", ans);
    return 0;
}