#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
int n, m, col[N];
vector<int> g[N];

bool dfs(int u, int c) {
    if (col[u] != -1) return col[u] == c;
    col[u] = c;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!dfs(v, !col[u])) return false;
    }
    return true;
}

vector<int> ans[2];
int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(col, -1, sizeof(col));
    for (int i = 1; i <= n; i++) {
        if (col[i] != -1) continue;
        if (!dfs(i, 0)) {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[col[i]].push_back(i);
    }
    for (int j = 0; j < 2; j++) {
        printf("%d\n", ans[j].size());
        for (int i = 0; i < ans[j].size(); i++) printf("%d ", ans[j][i]); printf("\n");
    }
    return 0;
}