#include <bits/stdc++.h>
using namespace std;

namespace UF
{
	int par[500005], ran[500005];
	int n;
	void init(int N)
	{
		n = N;
		for (int i = 0;i < n;i++)
			par[i] = i;
	}
	int getpar(int a)
	{
		return a==par[a]?a:par[a]=getpar(par[a]);
	}
	bool merge(int a, int b)
	{
		a = getpar(a), b = getpar(b);
		if (a != b)
		{
			if (ran[a] < ran[b])
				par[a] = b;
			else
			{
				par[b] = a;
				if (ran[a] == ran[b])
					ran[a]++;
			}
			return true;
		} else
			return false;
	}
};

struct edge
{
	edge *nxt;
	int a, b;
	edge(int A, int B) : nxt(NULL), a(A), b(B) { }
};

struct edgelist
{
	edge *be, *en;
	edgelist() : be(NULL), en(NULL) { }
	void add(int a, int b)
	{
		edge *nx = new edge(a, b);
		nx->nxt = be;
		be = nx;
		if (en == NULL)
			en = be;
	}
	void append(edgelist& oth)
	{
		if (oth.be)
		{
			if (en)
			{
				en->nxt = oth.be;
				en = oth.en;
			} else
			{
				be = oth.be;
				en = oth.en;
			}
			oth.be = oth.en = NULL;
		}
	}
	void prepend(edgelist& oth)
	{
		if (oth.be)
		{
			if (en)
			{
				oth.en->nxt = be;
				be = oth.be;
			} else
			{
				be = oth.be;
				en = oth.en;
			}
			oth.be = oth.en = NULL;
		}
	}
	edge pop()
	{
		edge ret = *be;
		be = be->nxt;
		if (be == NULL) en = NULL;
		return ret;
	}
} wa[500005];

vector<pair<pair<int, int>, pair<int, int> > > ans;
vector<int> ch[500005];
bool todo[500005];
int deg[500005];
int par[500005];
int n;

void dfs(int at)
{
	for (int u: ch[at]) if (u != par[at])
	{
		par[u] = at;
		deg[at]++;
		dfs(u);
	}
}

int main()
{
	scanf("%d", &n); UF::init(n);
	for (int i = 1;i < n;i++)
	{
		int a, b; scanf("%d%d", &a, &b); --a, --b;
		ch[a].push_back(b);
		ch[b].push_back(a);
	}
	par[0] = -1; dfs(0);
	for (int i = 1;i < n;i++)
	{
		int a, b; scanf("%d%d", &a, &b); --a, --b;
		if (b != par[a])
			wa[a].add(a, b);
		else
			todo[a] = true;
		if (a != par[b])
			wa[b].add(b, a);
		else
			todo[b] = true;
	}
	for (int i = 0;i < n;i++) if (todo[i])
		wa[i].add(i, par[i]);
	queue<int> q;
	for (int i = 0;i < n;i++) if (deg[i] == 0)
		q.push(i);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		if (!u) break;
		while (par[ch[u].back()] == u) ch[u].pop_back();
		int me = u;
		u = UF::getpar(u);
		while (true)
		{
			edge v = wa[u].pop();
			int oth = UF::getpar(v.b);
			if (UF::merge(v.a, v.b))
			{
				if (v.a != me || v.b != par[me])
					ans.push_back({{me, par[me]}, {v.a, v.b}});
				if (oth == UF::getpar(v.a))
					wa[oth].append(wa[u]);
				else
					wa[u].prepend(wa[oth]);
				break;
			}
		}
		if (!--deg[par[me]])
			q.push(par[me]);
	}
	printf("%d\n", ans.size());
	for (auto u: ans) printf("%d %d %d %d\n", u.first.first+1, u.first.second+1, u.second.first+1, u.second.second+1);
	return 0;
}