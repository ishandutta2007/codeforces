#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 100005;
int n;
vector<pair<int, int> > g[N];
int cost[N], sz[N];
long long dp[N];

struct ST {
    int a, b;
    ST() {}
    ST(int a, int b) : a(a), b(b) {}
    bool operator < (const ST& c) const {
        return 1LL * a * c.b < 1LL * b * c.a;
    }
} tmp[N];

void dfs(int u, int p) {
    sz[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        cost[u] += cost[v] + 2 * w;
    }
    int tot = 0, tn = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if (v == p) continue;
        dp[u] += dp[v] + 1LL * sz[v] * w;
        tmp[tn++] = ST(sz[v], cost[v] + 2 * w);
    }
    sort(tmp, tmp + tn);
    for (int i = 0; i < tn; i++) {
        dp[u] += 1LL * tmp[i].b * tot;
        tot += tmp[i].a;
    }
}

int main() {
    scanf("%d", &n);
    int u, v, w;
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    dfs(1, 1);
    printf("%.12f\n", dp[1] * 1.0 / (n - 1));
    return 0;
}