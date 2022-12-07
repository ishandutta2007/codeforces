#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, m, k;
int ban[N];
vector<int> g[N];
int tot[N], du[N], cnt[N];

queue<int> Q;
int vis[N];

bool judge(double mid) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) cnt[i] = du[i];
    for (int i = 1; i <= n; i++) {
        if (ban[i]) vis[i] = 1;
        else if (du[i] * 1.0 / tot[i] < mid) {
            Q.push(i);
            vis[i] = 1;
        }
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (vis[v]) continue;
            cnt[v]--;
            if (cnt[v] * 1.0 / tot[v] < mid) {
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) return true;
    return false;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int u, v;
    for (int i = 0; i < k; i++) {
        scanf("%d", &u);
        ban[u] = 1;
    }
    while (m--) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        tot[u]++; tot[v]++;
        if (!ban[u]) du[v]++;
        if (!ban[v]) du[u]++;
    }
    double l = 0, r = 1;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        if (judge(mid)) l = mid;
        else r = mid;
    }
    judge(l);
    int ans = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) ans++;
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
        if (!vis[i]) printf("%d ", i);
    return 0;
}