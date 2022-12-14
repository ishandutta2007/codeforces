#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 200005;

int n, sv;
vector<int> adj[MaxN];

int fa[MaxN];
int dep[MaxN][2];

int dfs(const int &u)
{
	dep[u][1] = dep[u][0];
	for (int v : adj[u])
		if (v != fa[u])
		{
			fa[v] = u;
			dep[v][0] = dep[u][0] + 1;
			dep[u][1] = max(dep[u][1], dfs(v));
		}
	return dep[u][1];
}

int main()
{
	cin >> n >> sv;
	for (int i = 1; i < n; ++i)
	{
		int u = getint(), v = getint();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	int res = 0;
	for (int v = sv; v; v = fa[v])
	{
		if (dep[sv][0] - dep[v][0] >= dep[v][0])
			break;
		res = max(res, dep[v][1]);
	}

	cout << res * 2 << endl;

	return 0;
}