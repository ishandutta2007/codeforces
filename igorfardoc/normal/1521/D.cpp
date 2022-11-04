#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<vector<int> > g, g1;
vector<pair<int, int> > dp;
vector<vector<int> > ans1, ans2;
set<pair<int, int> > deleted;
vector<pair<int, int> > deleted1;
vector<pair<int, int> > adding1;
vector<pair<int, int> > ends1;
vector<bool> used;

void dfs(int v, int p)
{
	vector<int> fir;
	vector<int> sec;
	vector<int> ver;
	for(int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(u == p)
		{
			continue;
		}
		dfs(u, v);
		fir.push_back(dp[u].first);
		sec.push_back(dp[u].second);
		ver.push_back(u);
	}
	if(fir.empty())
	{
		dp[v].first = 0;
		dp[v].second = 0;
		return;
	}
	int m = fir.size();
	vector<int> deltas(m);
	for(int i = 0; i < m; i++)
	{
		deltas[i] = fir[i] - sec[i];
	}
	if(m == 1)
	{
		if(1 + sec[0] < fir[0])
		{
			dp[v].first = dp[v].second = 1 + sec[0];
			ans1[v].push_back(ver[0]);
			ans2[v].push_back(ver[0]);
		}
		else
		{
			dp[v].first = dp[v].second = fir[0];
		}
		return;
	}
	int min1 = 1000000;
	int min2 = 1000000;
	int id1 = -1;
	int id2 = -1;
	int sum = 0;
	for(int i = 0; i < m; i++)
	{
		sum += sec[i];
		if(deltas[i] < min1)
		{
			id2 = id1;
			min2 = min1;
			min1 = deltas[i];
			id1 = i;
		}
		else if(deltas[i] < min2)
		{
			min2 = deltas[i];
			id2 = i;
		}
	}
	if(min1 == 0)
	{
		dp[v].first = sum + m - 1;
		for(int i = 0; i < m; i++)
		{
			if(i != id1)
			{
				ans1[v].push_back(ver[i]);
			}
		}
		if(min2 == 0)
		{
			dp[v].second = sum + m - 2;
			for(int i = 0; i < m; i++)
			{
				if(i != id1 && i != id2)
				{
					ans2[v].push_back(ver[i]);
				}
			}
		}
		else
		{
			dp[v].second = sum + m - 1;
			for(int i = 0; i < m; i++)
			{
				if(i != id1)
				{
					ans2[v].push_back(ver[i]);
				}
			}
		}
	}
	else
	{
		dp[v].first = sum + m;
		dp[v].second = sum + m;
		for(int i = 0; i < m; i++)
		{
			ans1[v].push_back(ver[i]);
			ans2[v].push_back(ver[i]);
		}
	}
}


void dfs2(int v, int p, int mod)
{
	set<int> del;
	if(mod == 2)
	{
		for(int i = 0; i < ans2[v].size(); i++)
		{
			del.insert(ans2[v][i]);
		}
	}
	else
	{
		for(int i = 0; i < ans1[v].size(); i++)
		{
			del.insert(ans1[v][i]);
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(u == p)
		{
			continue;
		}
		if(del.find(u) == del.end())
		{
			dfs2(u, v, 1);
		}
		else
		{
			dfs2(u, v, 2);
			deleted.insert({min(v, u), max(v, u)});
			deleted1.push_back({min(v, u), max(v, u)});
		}
	}
}
ostream & operator<<(ostream & out, pair<int, int> a)
{
	out << a.first << ' ' << a.second;
	return out;
}
void dfs3(int v, int p)
{
	used[v] = true;
	for(int i = 0; i < g1[v].size(); i++)
	{
		int u = g1[v][i];
		if(u == p)
		{
			continue;
		}
		dfs3(u, v);
	}
	if(g1[v].size() <= 1)
	{
		//cout << v << endl;
		if(ends1[ends1.size() - 1].first == -1)
		{
			ends1[ends1.size() - 1].first = v;
		}
		else
		{
			ends1[ends1.size() - 1].second = v;
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
    	cin >> n;
    	g.assign(n, vector<int>(0));
    	g1.assign(n, vector<int>(0));
    	ans1.assign(n, vector<int>(0));
    	ans2.assign(n, vector<int>(0));
    	dp.resize(n);
    	used.assign(n, false);
    	for(int i = 0; i < n - 1; i++)
    	{
    		int v, u;
    		cin >> v >> u;
    		--v;
    		--u;
    		g[v].push_back(u);
    		g[u].push_back(v);
    	}
    	dfs(0, -1);
    	cout << dp[0].second << '\n';
    	deleted.clear();
    	deleted1.clear();
    	dfs2(0, -1, 2);
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < g[i].size(); j++)
    		{
    			int u = g[i][j];
    			if(deleted.find({min(i, u), max(i, u)}) == deleted.end())
    			{
    				g1[i].push_back(u);
    				//cout << i << ' ' << u << endl;
    			}
    		}
    	}
    	ends1.clear();
    	for(int i = 0; i < n; i++)
    	{
    		if(!used[i])
    		{
    			ends1.push_back({-1, -1});
    			dfs3(i, -1);
    			if(ends1[ends1.size() - 1].second == -1)
    			{
    				ends1[ends1.size() - 1].second = ends1[ends1.size() - 1].first;
    			}
    			//cout << ends1[ends1.size() - 1] << endl;
    		}
    	}
    	for(int i = 0; i < dp[0].second; i++)
    	{
    		cout << deleted1[i].first + 1 << ' ' << deleted1[i].second + 1 << ' ' <<
    		ends1[i].second + 1 << ' ' << ends1[i + 1].first + 1 << '\n';
    	}
    }
}