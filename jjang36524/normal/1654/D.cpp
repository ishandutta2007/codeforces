#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, pair<int, int>>>link[200100];
int pa[200100];
int ri[200100];
vector<pair<int, int>>mi[200100];
#define MOD 998244353
int mu(int n, int m = MOD - 2)
{
	if (m == 0)
		return 1;
	if (m % 2)
		return mu(n, m - 1) * n % MOD;
	int a = mu(n, m / 2);
	return a * a % MOD;
}
int re[200100];
void dfs(int n, int p)
{
	int i;
	for (i = 0; i < link[n].size(); i++)
	{
		if (link[n][i].first == p)
			continue;
		int j;
		for (j = 0; j < mi[link[n][i].second.first].size(); j++)
		{
			pa[mi[link[n][i].second.first][j].first] += mi[link[n][i].second.first][j].second;
		}
		for (j = 0; j < mi[link[n][i].second.second].size(); j++)
		{
			pa[mi[link[n][i].second.second][j].first] -= mi[link[n][i].second.second][j].second;
		}
		for (j = 0; j < mi[link[n][i].second.first].size(); j++)
		{
			ri[mi[link[n][i].second.first][j].first] = max(ri[mi[link[n][i].second.first][j].first], pa[mi[link[n][i].second.first][j].first]);
			
		}
		for (j = 0; j < mi[link[n][i].second.second].size(); j++)
		{
			ri[mi[link[n][i].second.second][j].first] = max(ri[mi[link[n][i].second.second][j].first], pa[mi[link[n][i].second.second][j].first]);
		}
		dfs(link[n][i].first, n);
		for (j = 0; j < mi[link[n][i].second.first].size(); j++)
		{
			pa[mi[link[n][i].second.first][j].first] -= mi[link[n][i].second.first][j].second;
		}
		for (j = 0; j < mi[link[n][i].second.second].size(); j++)
		{
			pa[mi[link[n][i].second.second][j].first] += mi[link[n][i].second.second][j].second;
		}

	}
}
int ans = 0;
void dfs2(int n, int p,int v)
{
	ans += v;
	int i;
	for (i = 0; i < link[n].size(); i++)
	{
		if (link[n][i].first == p)
			continue;
		int j;
		for (j = 0; j < mi[link[n][i].second.first].size(); j++)
		{
			int k;
			for (k = 0; k < mi[link[n][i].second.first][j].second; k++)
			{
				v *= re[mi[link[n][i].second.first][j].first];
				v %= MOD;
			}
				
		}
		for (j = 0; j < mi[link[n][i].second.second].size(); j++)
		{
			int k;
			for (k = 0; k < mi[link[n][i].second.second][j].second; k++)
			{
				v *= mi[link[n][i].second.second][j].first;
				v %= MOD;
			}
		}
		dfs2(link[n][i].first, n,v);
		for (j = 0; j < mi[link[n][i].second.first].size(); j++)
		{
			int k;
			for (k = 0; k < mi[link[n][i].second.first][j].second; k++)
			{
				v *= mi[link[n][i].second.first][j].first;
				v %= MOD;
			}
		}
		for (j = 0; j < mi[link[n][i].second.second].size(); j++)
		{
			int k;
			for (k = 0; k < mi[link[n][i].second.second][j].second; k++)
			{
				v *= re[mi[link[n][i].second.second][j].first];
				v %= MOD;
			}
		}
	}
}
signed main()
{
	int T;
	cin >> T;
	int i;
	for (i = 2; i <= 200000; i++)
	{
		int v = i;
		int j;
		for (j = 2; j * j <= i; j++)
		{
			int p = 0;
			while (v % j == 0)
			{
				v /= j;
				p++;
			}
			if (p)
				mi[i].push_back({ j,p });
		}
		if (v>1)
			mi[i].push_back({ v,1 });
		re[i] = mu(i);
	}
	while (T--)
	{
		ans = 0;
		int N;
		cin >> N;
		int i;
		for (i = 1; i <= N; i++)
		{
			pa[i] = 0;
			ri[i] = 0;
			link[i].clear();
		}
		for (i = 1; i < N; i++)
		{
			int a, b,c,d;
			cin >> a >> b >> c >> d;
			link[a].push_back({ b,{c,d} });
			link[b].push_back( {a,{d,c}} );
		}
		dfs(1, 0);
		int vv = 1;
		for (i = 1; i <= N; i++)
		{
			vv *= mu(i, ri[i]);
			vv %= MOD;
		}
		dfs2(1, 0, vv);
		cout << ans % MOD << '\n';
	}
}