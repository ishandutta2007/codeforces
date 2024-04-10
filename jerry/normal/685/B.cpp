#include <bits/stdc++.h>
using namespace std;

vector<int> ch[300005];
int par[300005];
int ans[300005];
int sz[300005];
int mx[300005];
int n, q;

int pre(int at)
{
	sz[at] = 1;
	mx[at] = 0;
	for (int u: ch[at])
	{
		sz[at] += pre(u);
		mx[at] = max(mx[at], sz[u]);
	}
	return sz[at];
}

void dfs(int at)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	for (int u: ch[at])
	{
		dfs(u);
		pq.emplace(sz[ans[u]], ans[u]);
	}
	if (ch[at].size() == 0) pq.emplace(1, at);
	while (!pq.empty())
	{
		auto u(pq.top()); pq.pop();
		if (mx[u.second]*2 <= sz[at] && (sz[at]-sz[u.second])*2 <= sz[at])
		{
			ans[at] = u.second;
			return;
		}
		pq.emplace(sz[par[u.second]], par[u.second]);
	}
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1;i < n;i++)
	{
		scanf("%d", par+i);
		par[i]--;
		ch[par[i]].push_back(i);
	}
	pre(0);
	dfs(0);
	while (q--)
	{
		int v; scanf("%d", &v);
		--v;
		printf("%d\n", ans[v]+1);
	}
	return 0;
}