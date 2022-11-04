#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
vector<vector<int>> g;
vector<int> a;
vector<bool> dp;
int sum;
bool ans;

int dfs(int v, int p)
{
	int am = 0;
	int all1 = a[v];
	for(auto u : g[v])
	{
		if(u == p) continue;
		all1 ^= dfs(u, v);
		am += dp[u];
	}
	if(am > 1 || am == 1 && all1 == 0)
	{
		ans = true;
	}
	if(am > 0 || all1 == sum)
	{
		dp[v] = true;
	}
	else
	{
		dp[v] = false;
	}
	return all1;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n >> k;
    	g.assign(n, vector<int>(0));
    	dp.resize(n);
    	a.resize(n);
    	sum = 0;
    	ans = false;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		sum ^= a[i];
    	}
    	for(int i = 0; i < n - 1; i++)
    	{
    		int v, u;
    		cin >> v >> u;
    		--v;
    		--u;
    		g[v].push_back(u);
    		g[u].push_back(v);
    	}
    	if(sum == 0)
    	{
			cout << "YES\n";
			continue;
    	}
    	if(k > 2)
    	{
    		dfs(0, -1);
    		if(ans)
    		{
    			cout << "YES\n";
    			continue;
    		}
    	}
    	cout << "NO\n";
    }
}