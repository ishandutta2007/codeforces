#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 100005;
int n, m;
vector<int> g[N];

ll sz[N], dp[N], sum[N];
int dep[N], fa[N][20];

void dfs1(int u, int p) {
    fa[u][0] = p; dep[u] = dep[p] + 1;
    for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs1(v, u);
        dp[u] += dp[v];
        sz[u] += sz[v];
    }
    dp[u] += sz[u];
    sz[u]++;
}

void dfs2(int u, int p, ll tot) {
    sum[u] = tot + dp[u];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs2(v, u, tot + dp[u] - dp[v] - sz[v] + n - sz[v]);
    }
}

int lca(int u, int v) {
    int d = dep[u] - dep[v];
    for (int i = 0; i < 20; i++)
        if (d&(1<<i)) u = fa[u][i];
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (fa[u][i] == fa[v][i])
            continue;
        u = fa[u][i];
        v = fa[v][i];
    }
    return fa[u][0];
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1, 0);
    while (m--) {
        scanf("%d%d", &u, &v);
        if (dep[u] < dep[v]) swap(u, v);
        int rt = lca(u, v);
        ll sum1, sum2, sz1, sz2;
        ll len = dep[u] + dep[v] - 2 * dep[rt] + 1;
        if (rt == v) {
            rt = u;
            for (int i = 0; i < 20; i++) {
                if ((dep[u] - dep[v] - 1)&(1<<i))
                    rt = fa[rt][i];
            }
            sum1 = dp[u]; sum2 = sum[v] - dp[rt] - sz[rt];
            sz1 = sz[u]; sz2 = n - sz[rt];
        } else {
            sum1 = dp[u]; sum2 = dp[v];
            sz1 = sz[u]; sz2 = sz[v];
        }
        printf("%.12f\n", (sum1 * sz2 + sum2 * sz1 + len * sz1 * sz2) * 1.0 / (sz1 * sz2));
    }
    return 0;
}