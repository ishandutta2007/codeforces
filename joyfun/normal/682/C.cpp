#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, a[N];
vector<pair<int, int> > g[N];
int dis[N];

void dfs(int u, int w) {
    dis[u] = w;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        int val = g[u][i].second;
        dfs(v, max(0, w + val));
    }
}

int ans = 0;

void dfs2(int u) {
    if (dis[u] > a[u]) return;
    ans++;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        dfs2(v);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int p, w;
    for (int i = 2; i <= n; i++) {
        scanf("%d%d", &p, &w);
        g[p].push_back(make_pair(i, w));
    }
    dfs(1, 0);
    dfs2(1);
    printf("%d\n", n - ans);
    return 0;
}