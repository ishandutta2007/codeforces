#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

int n;
vector<int> graph[50000];
int ans = 0;
int v[5000], u[5000];

int sz[3400][5000];
int par[5000];
int go[3400][3400];

void dfs(int v, int st)
{
    sz[st][v] = 1;
    for (auto u : graph[v])
    {
        if (sz[st][u] == 0)
        {
            dfs(u, st);
            go[u][st] = v;
            sz[st][v] += sz[st][u];
        }
    }
}

int dp[3400][3400];

int G(int v1, int v2)
{
    if (v1 == v2) return 0;
    if (dp[v1][v2] != 0) return dp[v1][v2];
    dp[v1][v2] = max(G(go[v1][v2], v2), G(v1, go[v2][v1])) + sz[v1][v2] * sz[v2][v1];
}

signed main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i] >> u[i];
        v[i]--, u[i]--;
        graph[v[i]].push_back(u[i]);
        graph[u[i]].push_back(v[i]);
    }
    for (int i = 0; i < n; i++) dfs(i, i);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                dp[i][j] = max(G(go[i][j], j), G(i, go[j][i])) + sz[i][j] * sz[j][i];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}