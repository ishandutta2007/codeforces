#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
const long long MOD = 998244353;
long long n;
vector<int> graph[550000];
long long dp[550000];
long long vis[550000];
long long fact[550000];

long long run_dp(int root)
{
    long long res = 1;
    long long suns = 0;
    vis[root] = 1;
    for (int i = 0; i < graph[root].size(); i++)
    {
        int u = graph[root][i];
        if (vis[u] == 0)
        {
            res = (res * run_dp(u)) % MOD;
            suns++;
        }
    }
    //cout << root << endl;
    if (root != 1)
        dp[root] = (res * fact[suns + 1]) % MOD;
    else
        dp[root] = (res * fact[suns] % MOD * n) % MOD;
    //cout << root << " " << dp[root] << " " << res << " " << fact[suns + 1] << endl;
    return dp[root];
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 500000; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    run_dp(1);
    cout << (dp[1]) % MOD;
}