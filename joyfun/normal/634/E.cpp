#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;

int n, k, a[N];
vector<int> g[N];
int dp[N], tp[N];
int Mid;
int use[N];
bool vis[N];

void dfs(int u, int p) {
    vis[u] = true;
    tp[u] = 0;
    dp[u] = 0;
    if (a[u] < Mid) {
        tp[u] = 1;
        return;
    }
    int Max = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u);
        if (tp[v] == 1) {
            tp[u] = 1;
            Max = max(Max, dp[v]);
        } else dp[u] += dp[v];
    }
    dp[u] += Max + 1;
}

int tot;

void dfs2(int u, int p, int tpp, int dpp) {
    if (a[u] < Mid) return;
    int v1 = 0, v2 = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        if (tp[v]) {
            if (dp[v] >= dp[v1]) {
                v2 = v1;
                v1 = v;
            } else if (dp[v] >= dp[v2])
                v2 = v;
        }
    }
    if (tp[v1]) {
        if (tpp) tot = max(tot, max(dpp, dp[v1]) + dp[u] - dp[v1]);
        else tot = max(tot, dpp + dp[u]);
    } else tot = max(tot, dpp + dp[u]);
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        if (tp[v1] == 0) dfs2(v, u, tpp, dpp + dp[u] - dp[v]);
        else {
            if (v == v1) {
                if (tp[v2] == 0) dfs2(v, u, tpp, dpp + dp[u] - dp[v1]);
                else {
                    if (tpp) dfs2(v, u, tpp, max(dpp, dp[v2]) + dp[u] - dp[v1]);
                    else dfs2(v, u, 1, dpp + dp[u] - dp[v1] + dp[v2]);
                }
            } else {
                if (tp[v]) {
                    if (tpp) dfs2(v, u, tpp, max(dpp, dp[v1]) + dp[u] - dp[v1]);
                    else dfs2(v, u, 1, dpp + dp[u]);
                } else {
                    if (tpp) dfs2(v, u, tpp, max(dpp, dp[v1]) + dp[u] - dp[v1] - dp[v]);
                    else dfs2(v, u, 1, dpp + dp[u] - dp[v]);
                }
            }
        }
    }
}

int cal(int mid) {
    Mid = mid;
    int ans = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (a[i] < Mid) continue;
        if (vis[i]) continue;
        dfs(i, i);
        tot = 0;
        dfs2(i, i, 0, 0);
        ans = max(tot, ans);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int l = 1, r = 1000001;
    while (l < r) {
        int mid = (l + r)>>1;
        if (cal(mid) >= k) l = mid + 1;
        else r = mid;
    }
    printf("%d\n", l - 1);
    return 0;
}