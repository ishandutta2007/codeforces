#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
int n, m, q;
vector<int> g[N];
vector<int> dp[N][20];
int fa[N][20], dep[N];

vector<int> meg(vector<int> a, vector<int> b) {
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());
    if (a.size() > 10) a.resize(10);
    return a;
}

void dfs(int u, int p, int d) {
    fa[u][0] = p; dep[u] = d;
    for (int i = 1; i < 20; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        dp[u][i] = meg(dp[u][i - 1], dp[fa[u][i - 1]][i - 1]);
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
}

vector<int> lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    vector<int> ans;
    for (int i = 0; i < 20; i++) {
        if ((dep[u] - dep[v])&(1<<i)) {
            ans = meg(ans, dp[u][i]);
            u = fa[u][i];
        }
    }
    for (int i = 19; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            ans = meg(ans, dp[u][i]);
            ans = meg(ans, dp[v][i]);
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    if (u == v) {
        ans = meg(ans, dp[u][0]);
        return ans;
    }
    ans = meg(ans, dp[u][0]);
    ans = meg(ans, dp[v][0]);
    ans = meg(ans, dp[fa[u][0]][0]);
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    int u, v, k;
    for (int i = 1; i <= n - 1; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &u);
        if (dp[u][0].size() < 10)
            dp[u][0].push_back(i);
    }
    dfs(1, 1, 0);
    while (q--) {
        scanf("%d%d%d", &u, &v, &k);
        vector<int> ans = lca(u, v);
        k = min((int)ans.size(), k);
        printf("%d", k);
        for (int i = 0; i < k; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}