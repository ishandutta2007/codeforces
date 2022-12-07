#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 400005;

int n;
vector<int> g[N];
int sz[N];

void dfs(int u, int p) {
    sz[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p)continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int c;

void dfs2(int u, int p) {
    int Max = n - sz[u];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs2(v, u);
        Max = max(Max, sz[v]);
    }
    if (Max <= n / 2) c = u;
}

int Max[2], Maxv[2];
int f[N];

void go(int u, int p, int sum) {
   // printf("%d %d\n", sum, u);
    if (sum > n / 2) f[u] = 0;
    int tot = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p)continue;
        tot += sz[v];
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p)continue;
        if (u == p) {
            int sb;
            for (int j = 0; j < 2; j++) {
                if (Maxv[j] != v) {
                    sb = Max[j];
                    break;
                }
            }
            if (tot - sz[v] + 1 <= n / 2) go(v, u, 0);
            else go(v, u, sum + tot - sz[v] - sb + 1);
        } else go(v, u, sum + tot - sz[v] + 1);
    }
}

int main() {
    scanf("%d", &n);
    int u, v;
    for (int i = 2; i <= n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    dfs2(1, 1);
    dfs(c, c);
    for (int i = 0; i < g[c].size(); i++) {
        int v = g[c][i];
        if (sz[v] > Max[0]) {
            Max[1] = Max[0];
            Maxv[1] = Maxv[0];
            Max[0] = sz[v];
            Maxv[0] = v;
        } else if (sz[v] > Max[1]) {
            Max[1] = sz[v];
            Maxv[1] = v;
        }
    }
   // printf("%d %d\n", Maxv[0], Maxv[1]);
    for (int i = 1; i <= n; i++) f[i]= 1;
    go(c, c, 0);
    for(int i = 1; i <= n; i++) printf("%d ", f[i]); printf("\n");
    return 0;
}