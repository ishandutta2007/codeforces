#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace UF
{
	int par[200005], ran[200005];
	void init(int n)
	{
		for (int i = 0;i < n;i++) par[i] = i, ran[i] = 0;
	}
	int getpar(int at)
	{
		return par[at]==at?at:par[at]=getpar(par[at]);
	}
	bool merge(int a, int b)
	{
		a = getpar(a), b = getpar(b);
		if (a == b) return false;
		if (ran[a] < ran[b])
			par[a] = b;
		else
		{
			par[b] = a;
			if (ran[a] == ran[b]) ran[a]++;
		}
		return true;
	}
};

struct edge
{
	int a, b, id;
	ll d, r;
	bool operator< (const edge& oth) const
	{
		return (d < oth.d);
	}
} e[200005];


vector<pair<int, int> > ch[200005];
vector<pair<int, ll> > sol;
int par[20][200005];
int dst[20][200005];
int dep[200005];
ll S; int n, m;

void dfs(int at)
{
	for (auto u: ch[at]) if (u.first != par[0][at])
	{
		dep[u.first] = dep[at] + 1;
		par[0][u.first] = at;
		dst[0][u.first] = u.second;
		dfs(u.first);
	}
}

int qu(int a, int b)
{
	if (dep[a] > dep[b]) return qu(b, a);
	int ans = 0;
	for (int i = 19;i >= 0;i--) if (dep[b]-(1<<i) >= dep[a])
	{
		ans = max(ans, dst[i][b]);
		b = par[i][b];
	}
	if (a == b) return ans;
	for (int i = 19;i >= 0;i--) if (par[i][a] != par[i][b])
	{
		ans = max(ans, dst[i][a]); ans = max(ans, dst[i][b]);
		a = par[i][a]; b = par[i][b];
	}
	return max(ans, max(dst[0][a], dst[0][b]));
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < m;i++) scanf("%lld", &e[i].d);
	for (int i = 0;i < m;i++) scanf("%lld", &e[i].r);
	for (int i = 0;i < m;i++) scanf("%d%d", &e[i].a, &e[i].b), --e[i].a, --e[i].b, e[i].id = i+1;
	scanf("%lld", &S);
	UF::init(n);
	sort(e, e+m);
	ll tot = 0;
	for (int i = 0;i < m;i++) if (UF::merge(e[i].a, e[i].b))
	{
		ch[e[i].a].emplace_back(e[i].b, e[i].d);
		ch[e[i].b].emplace_back(e[i].a, e[i].d);
		tot += e[i].d;
	}
	par[0][0] = -1; dfs(0);
	for (int j = 1;j < 20;j++) for (int i = 0;i < n;i++) if ((par[j][i]=par[j-1][i]!=-1?par[j-1][par[j-1][i]]:-1) != -1) dst[j][i] = max(dst[j-1][i], dst[j-1][par[j-1][i]]);
	ll ans = 1ll << 62; int wh = -1;
	for (int i = 0;i < m;i++)
	{
		ll alt = tot - qu(e[i].a, e[i].b) + e[i].d - S/e[i].r;
		if (alt < ans)
		{
			ans = alt;
			wh = i;
		}
	}
	printf("%lld\n", ans);
	UF::init(n);
	UF::merge(e[wh].a, e[wh].b); sol.emplace_back(e[wh].id, e[wh].d-S/e[wh].r);
	for (int i = 0;i < m;i++) if (UF::merge(e[i].a, e[i].b))
		sol.emplace_back(e[i].id, e[i].d);
	for (auto u: sol) printf("%d %lld\n", u.first, u.second);
	return 0;
}