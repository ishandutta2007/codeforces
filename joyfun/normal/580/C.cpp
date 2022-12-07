#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;

int vis[N];
int ans;
vector<int> g[N];
int n, m;

void dfs(int u, int p, int cnt) {
    if (cnt > m) return;
    int flag = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        flag = 1;
        if (vis[v]) dfs(v, u, cnt + 1);
        else dfs(v, u, 0);
    }
    if (!flag) ans++;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &vis[i]);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1, vis[1]);
    printf("%d\n", ans);
    return 0;
}