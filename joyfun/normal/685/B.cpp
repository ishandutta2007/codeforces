#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 300005;
int n, q, fa[N], sz[N], c[N];
vector<int> g[N];

void dfs(int u) {
    sz[u] = 1;
    c[u] = u;
    int Max = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dfs(v);
        sz[u] += sz[v];
        if (sz[v] > Max) {
            Max = sz[v];
            c[u] = c[v];
        }
    }
    while ((sz[u] - sz[c[u]]) * 2 >= sz[u]) c[u] = fa[c[u]];
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &fa[i]);
        g[fa[i]].push_back(i);
    }
    dfs(1);
    int x;
    while (q--) {
        scanf("%d", &x);
        printf("%d\n", c[x]);
    }
    return 0;
}