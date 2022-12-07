#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
int n, m;
vector<int> g[N];
int vis[N], dep[N];
int an;

void dfs(int u, int d) {
    dep[u] = d;
    for (int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        dfs(v, d + 1);
    }
}

int a[N], ans[N];

bool cmp(int a, int b) {
    return dep[a] > dep[b];
}

int bid[N];
vector<pair<int, int> > f[N];
int cnt[N];

void dfs2(int u, int c) {
    c += bid[u];
    for (int i = 0; i < f[u].size(); i++) {
        cnt[f[u][i].first] += f[u][i].second * c;
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dfs2(v, c);
    }
}

bool judge() {
    for (int i = 1; i <= n; i++) {
        f[a[i]].push_back(make_pair(i, -1));
        f[i].push_back(make_pair(i, 1));
    }
    for (int i = 1; i <= an; i++) bid[ans[i]] = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs2(i, 0);
    }
    for (int i = 1; i <= n; i++) if (cnt[i]) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        vis[v] = 1;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i, 1);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ans[i] = a[i];
    }
    sort(ans + 1, ans + 1 + n);
    an = unique(ans + 1, ans + 1 + n) - ans - 1;
    sort(ans + 1, ans + 1 + an, cmp);
    if (!judge()) printf("-1\n");
    else {
        printf("%d\n", an);
        for (int i = 1; i <= an; i++) printf("%d\n", ans[i]);
    }
    return 0;
}