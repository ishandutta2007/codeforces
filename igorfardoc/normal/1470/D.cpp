#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int> > g;
vector<int> res;
vector<bool> used;
vector<bool> ok1;


void dfs(int v)
{
	used[v] = true;
	if(!ok1[v])
	{
		res.push_back(v);
		ok1[v] = true;
		for(int i = 0; i < g[v].size(); i++)
		{
			int u = g[v][i];
			ok1[u] = true;
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(!used[u])
		{
			dfs(u);
		}
	}
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
    	int n, m;
    	cin >> n >> m;
    	g.clear();
    	g.resize(n);
    	for(int i = 0; i < m; i++)
    	{
    		int v, u;
    		cin >> v >> u;
    		v--;
    		u--;
			g[v].push_back(u);
			g[u].push_back(v);
    	}
    	used.assign(n, false);
    	ok1.assign(n, false);
    	res.clear();
    	dfs(0);
    	bool ok = true;
    	for(int i = 0; i < n; i++)
    	{
    		if(!ok1[i])
    		{
    			cout << "NO\n";
    			ok = false;
    			break;
    		}
    	}
    	if(!ok)
    	{
    		continue;
    	}
    	cout << "YES\n";
    	cout << res.size() << '\n';
    	for(int i = 0; i < res.size(); i++)
    	{
    		cout << res[i] + 1 << ' ';
    	}
    	cout << '\n';
    }
}