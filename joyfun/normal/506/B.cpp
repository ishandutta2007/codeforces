#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 100005;

int n, m, du[N], vis[N], have[N], hn;
vector<int> g[N], g2[N];

void dfs(int u) {
    have[hn++] = u;
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (vis[v]) continue;
        dfs(v); 
    }
}

bool find() {
    queue<int> Q;
    for (int i = 0; i < hn; i++)
        if (!du[have[i]]) Q.push(have[i]);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        int sz = g2[u].size();
        for (int i = 0; i < sz; i++) {
            int v = g2[u][i];
            du[v]--;
            if (!du[v]) Q.push(v);
        }
    }
    for (int i = 0; i < hn; i++)
        if (du[have[i]]) return true;
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        du[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
        g2[u].push_back(v);
    }
    int ans = n;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            hn = 0;
            dfs(i);
            if (!find()) ans--;
        }
    }
    printf("%d\n", ans);
    return 0;
}