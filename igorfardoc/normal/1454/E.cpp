#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<vector<int> > g;
vector<int> circle;
int start;
vector<bool> used;
long long ans;

bool dfs1(int v, int p)
{
	used[v] = true;
	circle.push_back(v);
	for(int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(u != p)
		{
			if(!used[u])
			{
				bool ok = dfs1(u, v);
				if(ok)
				{
					return true;
				}
			}
			else
			{
				for(int j = 0; j < circle.size(); j++)
				{
					if(circle[j] == u)
					{
						start = j;
						break;
					}
				}
				return true;
			}
		}
	}
	circle.pop_back();
	return false;
}

int dfs2(int v, int p1, int p2)
{
	int ans = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(u != p1 && u != p2)
		{
			ans += dfs2(u, v, -1);
		}
	}
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	cin >> n;
    	ans = 0;
    	g.clear();
    	g.resize(n);
    	circle.resize(0);
    	used.assign(n, false);
    	for(int i = 0; i < n; i++)
    	{
    		int a, b;
    		cin >> a >> b;
    		--a;
    		--b;
    		g[a].push_back(b);
    		g[b].push_back(a);
    	}
    	dfs1(0, -1);
    	vector<int> circle1(circle.size() - start);
    	for(int i = start; i < circle.size(); i++)
    	{
    		circle1[i - start] = circle[i];
    	}
    	circle = circle1;
    	vector<int> res(circle.size(), 0);
    	int sum = 0;
    	for(int i = 0; i < res.size(); i++)
    	{
    		res[i] = dfs2(circle[i], circle[(i + 1) % circle.size()], circle[(i - 1 + (int)circle.size()) % circle.size()]);
    		ans += ((long long)res[i] * (res[i] - 1)) / 2;
    		ans += ((long long)sum * res[i] * 2);
    		sum += res[i];
    	}
    	cout << ans << endl;
    }
}