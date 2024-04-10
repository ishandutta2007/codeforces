#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace UF
{
	struct edge
	{
		int a, b; ll w;
		edge(int A, int B, ll W) : a(A), b(B), w(W) { }
		bool operator< (const edge& oth) const { return (w < oth.w); }
	};
	int par[200005], ran[200005];
	multiset<edge> edg;
	void add_edge(int a, int b, ll w) { edg.emplace(a, b, w); }
	int getpar(int a) { return par[a]==a?a:par[a]=getpar(par[a]); }
	void proc(int n, vector<edge>& use)
	{
		for (int i = 0;i < n;i++) par[i] = i, ran[i] = 1;
		while (!edg.empty())
		{
			auto u(*edg.begin()); edg.erase(edg.begin());
			int a = getpar(u.a), b = getpar(u.b);
			if (a == b) continue;
			if (ran[a] < ran[b]) par[a] = b;
			else
			{
				par[b] = a;
				if (ran[a] == ran[b]) ran[a]++;
			}
			use.push_back(u);
		}
	}
};

namespace LCA
{
	vector<pair<int, ll> > ch[200005];
	int dep[200005];
	ll w[20][200005];
	int par[20][200005];
	int n;
	void dfs(int at)
	{
		for (auto u: ch[at]) if (u.first != par[0][at])
		{
			dep[u.first] = dep[at] + 1;
			w[0][u.first] = u.second;
			par[0][u.first] = at;
			dfs(u.first);
		}
	}
	void init(int N)
	{
		n = N;
		for (int j = 0;j < 20;j++) for (int i = 0;i < n;i++)
			par[j][i] = -1, w[j][i] = 0;
		dep[0] = 0; dfs(0);
		for (int j = 1;j < 20;j++) for (int i = 0;i < n;i++) if (par[j-1][i] != -1)
		{
			par[j][i] = par[j-1][par[j-1][i]];
			w[j][i] = max(w[j-1][i], w[j-1][par[j-1][i]]);
		}
	}
	ll qu(int a, int b)
	{
		if (dep[a] > dep[b]) return qu(b, a);
		ll ret = 0;
		for (int i = 19;i >= 0;i--) if (dep[b]-(1<<i) >= dep[a])
		{
			ret = max(ret, w[i][b]);
			b = par[i][b];
		}
		if (a == b) return ret;
		for (int i = 19;i >= 0;i--) if (par[i][a] != par[i][b])
		{
			ret = max(ret, max(w[i][a], w[i][b]));
			a = par[i][a];
			b = par[i][b];
		}
		return max(ret, max(w[0][a], w[0][b]));
	}
};

vector<UF::edge> all, use;
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < m;i++)
	{
		int a, b; ll w;
		scanf("%d%d%lld", &a, &b, &w); --a, --b;
		all.emplace_back(a, b, w);
		UF::add_edge(a, b, w);
	}
	UF::proc(n, use); ll ans = 0;
	for (auto u: use)
	{
		LCA::ch[u.a].emplace_back(u.b, u.w);
		LCA::ch[u.b].emplace_back(u.a, u.w);
		ans += u.w;
	}
	LCA::init(n);
	for (auto u: all)
		printf("%lld\n", ans+u.w-LCA::qu(u.a, u.b));
	return 0;
}