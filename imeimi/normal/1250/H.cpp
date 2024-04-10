#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> edge[100001];

int dp[100001][2], pr[100001];
void dfs(int x, int p) {
    dp[x][0] = 0;
    dp[x][1] = 1;
    int mn = 1e8;
    for (int i : edge[x]) {
        if (i == p) continue;
        dfs(i, x);
        int val = min(dp[i][0], dp[i][1]);
        if (dp[i][1] - val < mn) mn = dp[i][1] - val, pr[x] = i;
        dp[x][0] += val;
        dp[x][1] += val;
    }
    dp[x][0] += mn;
}

vector<int> lst[100001];
int g[100001];
void dfs2(int x, int p, int j) {
    if (j) lst[g[x] = g[p]].push_back(x);
    else lst[g[x] = x].push_back(x);
    for (int i : edge[x]) {
        if (i == p) continue;
        if (j) {
            dfs2(i, x, dp[i][0] > dp[i][1]);
        }
        else {
            dfs2(i, x, i == pr[x] || dp[i][0] > dp[i][1]);
        }
    }
}

int ans[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; ++i) {
        int sz = lst[i].size();
        if (!sz) continue;
        for (int j = 0; j < sz; ++j) {
            ans[lst[i][j]] = lst[i][(j + 1) % sz];
        }
    }
    printf("%d\n", dp[1][0] * 2);
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", ans[i], "\n "[i < n]);
    }
    return 0;
}