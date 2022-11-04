#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<vector<int> > g, gr;
int ans = 0;
vector<int> component, order, comp;
vector<bool> used;

void dfs1(int v)
{
	used[v] = true;
	for(int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		//cout << v << ' ' << u << endl;
		if(!used[u])
		{
			dfs1(u);
		}
	}
	order.push_back(v);
}

void dfs2(int v, int here)
{
	used[v] = true;
	component.push_back(v);
	comp[v] = here;
	for(int i = 0; i < gr[v].size(); i++)
	{
		int u = gr[v][i];
		if(!used[u])
		{
			dfs2(u, here);
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
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> s[i];
    }
    int now = 0;
    vector<vector<int> > a(n, vector<int>(m, -1));
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < m; j++)
    	{
    		if(s[i][j] == '#')
    		{
    			a[i][j] = now++;
    		}
    	}
    }
    g.resize(now);
    gr.resize(now);
    vector<vector<int> > dp(n, vector<int>(m, -1));
    for(int i = n - 1; i >= 0; i--)
    {
    	for(int j = 0; j < m; j++)
    	{
    		if(s[i][j] == '#')
    		{
    			dp[i][j] = a[i][j];
    			continue;
    		}
    		if(i == n - 1)
    		{
    			continue;
    		}
    		dp[i][j] = dp[i + 1][j];
    	}
    }
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < m; j++)
    	{
    		if(s[i][j] != '#')
    		{
    			continue;
    		}
    		if(i != n - 1 && dp[i + 1][j] != -1)
    		{
    			g[a[i][j]].push_back(dp[i + 1][j]);
    			gr[dp[i + 1][j]].push_back(a[i][j]);
    		}
    		if(i != 0 && a[i - 1][j] != -1)
    		{
    			g[a[i][j]].push_back(a[i - 1][j]);
    			gr[a[i - 1][j]].push_back(a[i][j]);
    		}
    		if(j != 0 && dp[i][j - 1] != -1)
    		{
    			g[a[i][j]].push_back(dp[i][j - 1]);
    			gr[dp[i][j - 1]].push_back(a[i][j]);
    		}
    		if(j != m - 1 && dp[i][j + 1] != -1)
    		{
    			g[a[i][j]].push_back(dp[i][j + 1]);
    			gr[dp[i][j + 1]].push_back(a[i][j]);
    		}
    	}
    }
    used.assign(now, false);
    for(int i = 0; i < now; i++)
    {
    	if(!used[i])
    	{
    		dfs1(i);
    	}
    }
    comp.resize(now);
    used.assign(now, false);
    int here = 0;
    for(int i = now - 1; i >= 0; i--)
    {
    	int v = order[i];
    	if(!used[v])
    	{
    		component.clear();
    		dfs2(v, here++);
    	}
    }
    used.assign(here, false);
    for(int i = 0; i < now; i++)
    {
    	//cout << i << ' ' << comp[i] << endl;
    	for(int j = 0; j < g[i].size(); j++)
    	{
    		if(comp[g[i][j]] != comp[i])
    		{
    			used[comp[g[i][j]]] = true;
    		}
    	}
    }
    for(int i = 0; i < here; i++)
    {
    	ans += !used[i];
    }
    cout << ans;
}