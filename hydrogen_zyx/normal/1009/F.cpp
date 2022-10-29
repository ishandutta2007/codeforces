#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
vector<int> g[N], dp[N];
int son[N], len[N], ans[N];
int depth[N];

void dfs1(int u, int fa, int deep) {
    len[u] = 1;
    depth[u] = deep;
    for (auto x:g[u]) {
        if (x == fa) continue;
        dfs1(x, u, deep + 1);
        if (len[x] > len[son[u]]) son[u] = x;
        len[u] = max(len[x] + 1, len[u]);
    }
}

void dfs2(int u, int fa) {
    if (son[u]) {
        dfs2(son[u], u);
        swap(dp[son[u]], dp[u]);
        if (ans[son[u]] == depth[son[u]]) ans[u] = depth[u];
        else ans[u] = ans[son[u]];
        dp[u].push_back(1);
        for (auto x:g[u]) {
            if (x == fa || x == son[u]) continue;
            dfs2(x, u);
            for (int i = 0; i < dp[x].size(); i++) {
                int dep = depth[x] + len[x] - i - 1;
                dp[u][depth[u] + len[u] - dep - 1] += dp[x][i];
                if (dp[u][depth[u] + len[u] - dep - 1] > dp[u][depth[u] + len[u] - ans[u] - 1]) ans[u] = dep;
                else if (dp[u][depth[u] + len[u] - dep - 1] == dp[u][depth[u] + len[u] - ans[u] - 1] &&
                         ans[u] > dep)
                    ans[u] = dep;
            }
        }
    } else {
        dp[u].push_back(1);
        ans[u] = depth[u];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1, 1, 1);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] - depth[i] << endl;
    }
}