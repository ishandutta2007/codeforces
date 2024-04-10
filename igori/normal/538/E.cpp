#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[500000];
int sz[500000], bl[500000], p[500000];
int dp[4][500000];
void dfssz(int v)
{
    bl[v] = 1;
    sz[v] = (v != 1 && graph[v].size() == 1);
    for (auto u : graph[v]) if (bl[u] == 0) dfssz(u), sz[v] += sz[u], p[u] = v;
}
int Solve(int v, int Case)
{
    if (v != 1 && graph[v].size() == 1) return dp[Case][v] = 1;
    if (dp[Case][v] != 0) return dp[Case][v];
    if (Case == 0)
    {
        int ans = sz[v] - 1;
        for (auto u : graph[v])
        {
            if (p[u] == v)
            {
                ans = min(ans, sz[u] - Solve(u, 3 - Case));
            }
        }
        ans = sz[v] - ans;
        return dp[Case][v] = ans;
    }
    if (Case == 3)
    {
        int ans = 1;
        for (auto u : graph[v])
        {
            if (p[u] == v)
            {
                ans += Solve(u, 3 - Case) - 1;
            }
        }
        return dp[Case][v] = ans;
    }
    if (Case == 2)
    {
        int ans = 1e9;
        for (auto u : graph[v])
        {
            if (p[u] == v)
            {
                ans = min(ans, Solve(u, 3 - Case));
            }
        }
        return dp[Case][v] = ans;
    }
    if (Case == 1)
    {
        int ans = sz[v];
        for (auto u : graph[v])
        {
            if (p[u] == v)
            {
                ans -= sz[u] - Solve(u, 3 - Case);
            }
        }
        return dp[Case][v] = ans;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if (n == 1) {cout << "1 1"; return 0;}
    for (int i = 0; i < n - 1; i++)
    {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u); graph[u].push_back(v);
    }
    for (int i = 2; i <= n; i++) if (graph[i].size() == 1) m++;
    dfssz(1);
    cout << Solve(1, 0) << " " << Solve(1, 1) << endl;
    //for (int Case = 0; Case < 4; Case++) { for (int i = 1; i <= n; i++) cout << dp[Case][i] << " "; cout << endl; }
}