#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ans;
vector<vector<int>> g, gr, g1;
vector<bool> used;
vector<int> order, component;
vector<vector<int>> components;
vector<bool> has;
vector<int> sorted;
vector<bool> can_go;
int n, m, k;

void dfs1(int v)
{
	used[v] = true;
	for(int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(!used[u])
		{
			dfs1(u);
		}
	}
	order.push_back(v);
}

void dfs2(int v)
{
	components[components.size() - 1].push_back(v);
	component[v] = components.size() - 1;
	used[v] = true;
	for(int i = 0; i < gr[v].size(); i++)
	{
		int u = gr[v][i];
		if(!used[u])
		{
			dfs2(u);
		}
	}
}

void dfs3(int v)
{
	used[v] = true;
	for(int i = 0; i < g1[v].size(); i++)
	{
		int u = g1[v][i];
		if(!used[u])
		{
			dfs3(u);
		}
	}
	sorted.push_back(v);
}
void dfs4(int v)
{
	used[v] = true;
	can_go[v] = true;
	for(int i = 0; i < g1[v].size(); i++)
	{
		int u = g1[v][i];
		if(!used[u])
		{
			dfs4(u);
		}
	}
}

void dfs(int v, int value)
{
	used[v] = true;
	if(ans[components[v][0]] == 0)
	{
		for(int i = 0; i < components[v].size(); i++)
		{
			ans[components[v][i]] = value;
		}
	}
	for(int i = 0; i < g1[v].size(); i++)
	{
		int u = g1[v][i];
		if(!used[u])
		{
			dfs(u, value);
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
    	cin >> n >> m;
    	ans.assign(n, 0);
    	g.assign(n, vector<int>(0));
    	gr.assign(n, vector<int>(0));
    	has.assign(n, false);
    	for(int i = 0; i < m; i++)
    	{
    		int v, u;
    		cin >> v >> u;
    		--v;
    		--u;
    		if(v == u)
    		{
    			has[v] = true;
    		}
    		g[v].push_back(u);
    		gr[u].push_back(v);
    	}
    	used.assign(n, false);
    	order.clear();
    	component.resize(n);
    	for(int i = 0; i < n; i++)
    	{
    		if(!used[i])
    		{
    			dfs1(i);
    		}
    	}
    	used.assign(n, false);
    	components.clear();
    	for(int i = 0; i < n; i++)
    	{	
    		if(!used[order[n - i - 1]])
    		{
    			components.push_back({});
    			dfs2(order[n - i - 1]);
    		}
    	}
    	k = components.size();
    	/*cout << endl;
    	for(int i = 0; i < k; i++)
    	{
    		for(int j = 0; j < components[i].size(); j++)
    		{
    			cout << components[i][j] << ' ';
    		}
    		cout << endl;
    	}
    	cout << endl;*/
    	g1.assign(k, vector<int>(0));
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < g[i].size(); j++)
    		{
    			g1[component[i]].push_back(component[g[i][j]]);
    		}
    	}
    	sorted.clear();
    	used.assign(k, false);
    	for(int i = 0; i < k; i++)
    	{	
    		if(!used[i])
    		{
    			dfs3(i);
    		}
    	}
    	//cout << 1 << endl;
    	reverse(sorted.begin(), sorted.end());
    	can_go.assign(k, false);
    	used.assign(k, false);
    	dfs4(component[0]);
    	used.assign(k, false);
    	for(int i = 0; i < k; i++)
    	{
    		if(!used[i] && can_go[i] && (components[i].size() > 1 || has[components[i][0]]))
    		{
    			dfs(i, -1);
    		}
    	}
    	//cout << 2 << endl;
    	vector<int> dp(k, 0);
    	for(int _ = 0; _ < k; _++)
    	{
    		int i = sorted[_];
    		if(component[0] == i)
    		{
    			dp[i] = 1;
    		}
    		if(dp[i] == 0)
    		{
    			continue;
    		}
    		if(dp[i] >= 2)
    		{
    			for(int j = 0; j < components[i].size(); j++)
    			{
    				if(ans[components[i][j]] == 0)
    				{
    					ans[components[i][j]] = 2;
    				}
    			}
    		}
    		for(int j = 0; j < g1[i].size(); j++)
    		{
    			int u = g1[i][j];
    			if(dp[u] < 2)
    			{
    				dp[u] += dp[i];
    			}
    		}
    	}
    	//cout << 3 << endl;
    	for(int i = 0; i < k; i++)
    	{
    		for(int j = 0; j < components[i].size(); j++)
    		{
    			if(can_go[i] && ans[components[i][j]] == 0)
    			{
    				ans[components[i][j]] = 1;
    			}
    		}
    	}
    	//cout << 4 << endl;
    	for(int i = 0; i < n; i++)
    	{
    		cout << ans[i] << ' ';
    	}
    	cout << '\n';
    }
}