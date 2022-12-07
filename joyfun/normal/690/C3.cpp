#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;
int n, p[N], dep[N], fa[N][20];
vector<int> g[N];

void dfs(int u, int p, int d) {
    dep[u] = d; fa[u][0] = p;
    for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 0; i < 20; i++)
        if ((dep[u] - dep[v])&(1<<i)) u = fa[u][i];
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int dist(int u, int v) {
    int rt = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[rt];
}

int a, b;

void add(int u) {
    int ab = dist(a, b), au = dist(a, u), bu = dist(b, u);
    if (ab > au && ab > bu) return;
    if (au > bu) b = u;
    else a = u;
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p[i]);
        g[p[i]].push_back(i);
    }
    dfs(1, 1, 1);
    a = 1, b = 2; printf("%d", dist(a, b));
    for (int i = 3; i <= n; i++) {
        add(i);
        printf(" %d", dist(a, b));
    }
    printf("\n");
    return 0;
}