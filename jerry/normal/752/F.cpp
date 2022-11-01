#include <bits/stdc++.h>
using namespace std;

vector<int> have[200005];
vector<int> ch[200005];
int par[200005];
int sz[200005];
bool am[200005];
int n, k;

int dfs(int at)
{
	for (int u: ch[at]) if (u != par[at])
	{
		par[u] = at;
		sz[at] += dfs(u);
	}
	return sz[at];
}

void prepare(int at, int belong)
{
	if (am[at]) have[belong].push_back(at), am[at] = false;
	for (int u: ch[at]) if (u != par[at]) prepare(u, belong);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1;i < n;i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		--a, --b;
		ch[a].push_back(b);
		ch[b].push_back(a);
	}
	for (int i = 0;i < 2*k;i++)
	{
		int a; scanf("%d", &a);
		--a;
		am[a] = true;
		sz[a]++;
	}
	par[0] = -1; dfs(0);
	for (int i = 0;i < n;i++)
	{
		bool ok = (2*k-sz[i]) <= k;
		for (int u: ch[i]) if (u != par[i] && sz[u] > k) ok = false;
		if (!ok) continue;
		printf("1\n%d\n", i+1);
		for (int u: ch[i]) if (u != par[i]) prepare(u, u);
		for (int j = 0;j < n;j++) if (am[j] && j != i) have[n].push_back(j);
		if (am[i]) for (int j = 0;j <= n;j++) if (have[j].size() < k)
		{
			have[j].push_back(i);
			break;
		}
		priority_queue<pair<unsigned, int> > pq;
		for (int j = 0;j <= n;j++) if (have[j].size())
			pq.push(make_pair(have[j].size(), j));
		while (!pq.empty())
		{
			auto u = pq.top(); pq.pop();
			auto v = pq.top(); pq.pop();
			printf("%d %d %d\n", have[u.second].back()+1, have[v.second].back()+1, i+1);
			have[u.second].pop_back();
			have[v.second].pop_back();
			if (u.first != 1) pq.push(make_pair(u.first-1, u.second));
			if (v.first != 1) pq.push(make_pair(v.first-1, v.second));
		}
		return 0;
	}
	return 0;
}