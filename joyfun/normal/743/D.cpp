#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;
const long long INF = (1LL<<60);
int n;
long long a[N], Max[N];
vector<int> g[N];
long long ans;

void dfs(int u, int p) {
    Max[u] = -INF;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u);
        a[u] += a[v];
        if (Max[u] != -INF) ans = max(ans, Max[u] + Max[v]);
        Max[u] = max(Max[u], Max[v]);
    }
    Max[u] = max(Max[u], a[u]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d",&u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = -INF;
    dfs(1, 1);
    if (ans == -INF) printf("Impossible\n");
    else printf("%lld\n", ans);
    return 0;
}