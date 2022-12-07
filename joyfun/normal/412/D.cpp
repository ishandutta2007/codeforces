#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

const int N = 30005;

int n, m, ans[N], ansn, vis[N], i;
vector<int> g[N];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dfs(v);
    }
    ans[ansn++] = u;
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    for (i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i);
    }
    for (i = 0; i < ansn - 1; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
    return 0;
}