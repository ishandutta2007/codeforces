#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> g;
vector<int> dp;
bool cicle = false;
vector<int> c;

void dfs(int v)
{
	if(dp[v] != -1)
	{
		return;
	}
	dp[v] = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		dfs(u);
		if(u < v)
		{
			dp[v] = max(dp[v], dp[u] - 1);
		}
		else
		{
			dp[v] = max(dp[v], dp[u]);
		}
	}
	dp[v]++;
}

void dfs1(int v)
{
	c[v] = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(c[u] == 0)
		{
			cicle = true;
		}
		else if(c[u] == 1)
		{
			continue;
		}
		else
		{
			dfs1(u);
		}
	}
	c[v] = 1;
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
    	int n;
    	cin >> n;
    	g.assign(n, vector<int>(0));
    	dp.assign(n, -1);
    	for(int i = 0; i < n; i++)
    	{
    		int k;
    		cin >> k;
    		for(int j = 0; j < k; j++)
    		{
    			int a;
    			cin >> a;
    			--a;
    			g[i].push_back(a);
    		}
    	}
    	c.assign(n, -1);
    	cicle = false;
    	for(int i = 0; i < n; i++)
    	{
    		if(c[i] == -1)
    		{
    			dfs1(i);
    		}
    	}
    	if(cicle)
    	{
    		cout << "-1\n";
    		continue;
    	}
    	int res = 0;
    	for(int i = 0; i < n; i++)
    	{
    		if(dp[i] == -1)
    		{
    			dfs(i);
    		}
    		res = max(res, dp[i]);
    	}
    	cout << res << '\n';
    }
}