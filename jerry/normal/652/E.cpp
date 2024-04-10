#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int to, id; bool has;
	edge(int T, int I, bool H) : to(T), id(I), has(H) { }
};

vector<pair<int, bool> > cch[300005];
vector<edge> ch[300005];
int idx[300005], low[300005], cc[300005];
bool has[300005], bdg[300005];
int n, m, a, b;

int dfs(int at, int par=-1)
{
	static int fr = 0;
	if (!idx[at])
	{
		idx[at] = low[at] = ++fr;
		for (auto& z: ch[at])
		{
			int u = z.to;
			if (u != par)
			{
				low[at] = min(low[at], dfs(u, at));
				if (low[u] > idx[at])
					bdg[z.id] = true;
			}
		}
	}
	return low[at];
}

void dfs2(int at, int ccid)
{
	cc[at] = ccid;
	for (auto& z: ch[at])
	{
		int u = z.to;
		if (bdg[z.id])
		{
			if (cc[u])
			{
				cch[cc[at]].emplace_back(cc[u], z.has);
				cch[cc[u]].emplace_back(cc[at], z.has);
			}
		} else
		{
			if (!cc[u])
				dfs2(u, ccid);
			if (z.has)
				has[ccid] = true;
		}
	}
}

void dfs3(int at, bool suc=false, int par=-1)
{
	suc = suc || has[at];
	if (at == cc[b])
	{
		if (suc) printf("YES\n");
		else printf("NO\n");
		exit(0);
	}
	for (auto& z: cch[at])
	{
		int u = z.first;
		if (u != par)
			dfs3(u, suc||z.second, at);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < m;i++)
	{
		int c;
		scanf("%d%d%d", &a, &b, &c); --a, --b;
		ch[a].emplace_back(b, i, c);
		ch[b].emplace_back(a, i, c);
	}
	scanf("%d%d", &a, &b); --a, --b;
	int ccid = 0;

	dfs(0);
	for (int i = 0;i < n;i++) if (!cc[i]) dfs2(i, ++ccid);
	dfs3(cc[a]);
	return 0;
}