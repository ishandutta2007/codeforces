//#include "stdafx.h"
#include<iostream>
#include <fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cmath>
#include <unordered_map>


#define mp make_pair
#define pii pair<unsigned ll,unsigned ll>
#define  ll long long
#define ld long double
using namespace std;
const ll M = 1E9 + 7;
const ll NMAX = 5000011;
const ll inf = 1E9;
vector<int> g[30];
pii d[NMAX];
int ed = 0;
int n;
int cnt = 0;
int r=0;
void gen(int i)
{
	if (i > n)
	{
		d[ed] = mp(cnt,r);
		ed++;
		return;
	}
	r = r << 1;
	gen(i + 1);
	r |= 1;
	cnt++;
	gen(i + 1);
	cnt--;
	r = r >> 1;
	return;
}
int used[30];
int dfs(int v,int r)
{
	used[v] = 1;
	int res = 0;
	for (int u : g[v])
	{
		if (!used[u] && ((r >> (u - 1)) & 1))
		{
			res += dfs(u,r);
		}
	}
	return res + 1;
}
bool sv(int r,int k)
{
	for (int i = 1; i <= n; i++)
		used[i] = 0;
	for(int i=0;i<n;i++)
		if ((r >> i) & 1)
		{
			if (dfs(i + 1, r) == k)
			{
				return true;
			}
			else
				return false;
		}
	return true;
}
int main()
{
	cin >> n;
	int m;
	cin >> m;
	if (n*(n - 1) / 2 == m)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	gen(1);
	sort(d, d + ed);
	for (int i=1;i<ed;i++)
	{
		int r = d[i].second;
		if (!sv(r, d[i].first))
			continue;
		for (int v = 1; v <= n; v++)
		{
			if ((r >> (v - 1)) & 1)
				continue;
			for (int u : g[v])
			{
				if ((r >> (u - 1)) & 1)
					goto a;
			}
			goto b;

		a:
			;
		}
		cout << d[i].first << endl;
		for (int i = 1; i <= n; i++)
		{
			if (((r >> (i - 1)) & 1))
				cout << i << ' ';
		}
		return 0;
	b:
		;
	}
	return 0;
};