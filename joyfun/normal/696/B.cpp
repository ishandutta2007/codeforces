#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;

int n;
vector<int> g[N];
int L[N], R[N], idx, sz[N];
int to[N];

void dfs(int u) {
    to[idx] = u;
    L[u] = ++idx;
    sz[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dfs(v);
        sz[u] += sz[v];
    }
    R[u] = idx;
}

double ans[N];

void add(int l, int r, double w) {
   // printf("%d %d %.12f\n", l, r, w);
    ans[l] += w;
    ans[r + 1] -= w;
}

double dep[N];
void dfs2(int u, double d) {
  //  add(L[u], L[u], d);
    dep[u] = d;
    int sum = 0;
    for (int i = 0; i < g[u].size(); i++) sum += sz[g[u][i]];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
       // printf("%d %d %.12f\n", v, sum - sz[v], 1.0 * (sum - sz[v]) / (g[u].size() - 1) +  1.0 * d + 1.0);
        if (g[u].size() - 1) add(L[v], R[v],  1.0 * (sum - sz[v]) / 2);
        //add(L[v], L[v], 1.0 * d + 1.0);
        dfs2(v, d + 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        g[p].push_back(i);
    }
    dfs(1);
    dfs2(1, 1.0);
    for (int i = 1; i <= n; i++)
        ans[i] += ans[i - 1];
    for (int i = 1; i <= n; i++) printf("%.12f ", ans[L[i]] + dep[i]);
    printf("\n");
    return 0;
}