#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a, b;
vector<bool> used;
vector<vector<int> > g;

void dfs(int v, int p)
{
	used[v] = true;
	for(int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(u == p || used[u])
		{
			continue;
		}
		dfs(u, v);
	}
}

const int mod = 1000000007;

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
    	a.assign(n, 0);
    	b.assign(n, 0);
    	used.assign(n, false);
    	g.assign(n, vector<int>(0));
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	for(int i = 0; i < n; i++)
    	{
    		cin >> b[i];
    	}
    	for(int i = 0; i < n; i++)
    	{
    		g[a[i] - 1].push_back(b[i] - 1);
    	}
    	int ans = 1;
    	for(int i = 0; i < n; i++)
    	{
    		if(!used[i])
    		{
    			dfs(i, -1);
    			ans = ((ll)ans * 2) % mod;
    		}
    	}
    	cout << ans << '\n';
    }
}