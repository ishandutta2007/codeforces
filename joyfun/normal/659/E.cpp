#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
int n, m;
vector<int> g[N];

int nd, ed, vis[N];

bool dfs(int u) {
    vis[u] = 1;
    nd++;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        ed++;
        if (vis[v]) continue;
        dfs(v);
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        nd = ed = 0;
        dfs(i);
        if (ed / 2 == nd - 1) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}