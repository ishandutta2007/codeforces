#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>

using namespace std;

typedef long long int64;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define ms(a,x)

const int lim = 1000000000;
const int N = 100005;

#define find FIND

vector<int> edge[N];
bool visit[N], find[N];
pair<int, int> f[N];
int g[N];

void up(pair<int, int> &a, int b)
{
	if (b >= a.first)
	{
		a.second = a.first;
		a.first = b;
	}
	else
		a.second = max(a.second, b);
}

void dfs(int a)
{
	visit[a] = true;
	f[a] = mp(-lim, -lim);
	g[a] = -lim;
	for (int i = 0; i < sz(edge[a]); ++i)
	{
		int j = edge[a][i];
		if (visit[j]) continue;
		dfs(j);
		up(f[a], f[j].first + 1);
	}
	if (find[a])
		up(f[a], 0);
}

void DFS(int a)
{
	visit[a] = true;
	for (int i = 0; i < sz(edge[a]); ++i)
	{
		int j = edge[a][i];
		if (visit[j]) continue;
		g[j] = max(g[j], g[a] + 1);
		if (f[a].first == f[j].first + 1)
			g[j] = max(g[j], f[a].second + 1);
		else
			g[j] = max(g[j], f[a].first + 1);
		DFS(j);
	}
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
//		freopen("a.out","w",stdout);
	#endif
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	while (m--)
	{
		int x;
		scanf("%d", &x);
		find[x] = true;
	}
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].pb(y);
		edge[y].pb(x);
	}
	dfs(1);
	memset(visit, 0, sizeof visit);
	DFS(1);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (f[i].first <= d && g[i] <= d) ++ans;
	printf("%d\n", ans);
	return 0;
}