#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<int> graph[500000];
int vis[500000];
long long n, k;
const long long mod = 1e9 + 7;

long long inq(long long n, long long k)
{
    if (k == 0) return 1;
    long long l = inq(n, k / 2);
    if (k % 2)
        return l * l % mod * n % mod;
    return l * l % mod;
}
long long cnt = 0;
void dfs(int v)
{
    if (vis[v])
        return;
    cnt++;
    vis[v] = 1;
    for (int j = 0; j < graph[v].size(); j++)
    {
        dfs(graph[v][j]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        if (w == 1) continue;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    long long ans = inq(n, k);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
            ans = (ans + mod - inq(cnt, k)) % mod;
            cnt = 0;
        }
    }
    cout << ans;
}