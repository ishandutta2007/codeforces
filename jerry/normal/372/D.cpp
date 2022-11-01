#include <bits/stdc++.h>
using namespace std;

vector<int> ch[100005];
int par[20][100005];
int pre[100005];
int dep[100005];
int who[100005];
int n, k, ans;
set<int> hv;
int sz;

int lca(int a, int b)
{
	if (dep[a] > dep[b]) return lca(b, a);
	for (int i = 19;i >= 0;i--) if (dep[b]-(1<<i) >= dep[a]) b = par[i][b];
	if (a == b) return a;
	for (int i = 19;i >= 0;i--) if (par[i][a] != par[i][b]) a = par[i][a], b = par[i][b];
	return par[0][a];
}

void dfs(int at)
{
	static int _;
	who[_] = at;
	pre[at] = _++;
	for (int u: ch[at]) if (u != par[0][at])
	{
		par[0][u] = at;
		dep[u] = dep[at]+1;
		dfs(u);
	}
}

void add(int at)
{
	if (hv.empty()) sz++;
	else
	{
		auto it = hv.lower_bound(pre[at]);
		if (it == hv.begin())
		{
			int A = who[*it], l = lca(at, A), super = lca(A, who[*hv.rbegin()]);
			sz += max(0, dep[super]-dep[l])+dep[at]-dep[l];
		} else if (it == hv.end())
		{
			it--;
			int B = who[*it], l = lca(at, B), super = lca(who[*hv.begin()], B);
			sz += max(0, dep[super]-dep[l])+dep[at]-dep[l];
		} else
		{
			int B = *it;
			int A = *--it;
			int dA = dep[lca(who[A], at)], dB = dep[lca(at, who[B])];
			sz += dep[at]-max(dA, dB);
		}
	}
	hv.insert(pre[at]);
}

void rem(int at)
{
	auto it = hv.lower_bound(pre[at]);
	if (it == hv.begin())
	{
		auto it2 = it; it2++;
		int A = who[*it2], l = lca(at, A), super = lca(A, who[*hv.rbegin()]);
		sz -= max(0, dep[super]-dep[l])+dep[at]-dep[l];
	} else if (it == --hv.end())
	{
		auto it2 = it; it2--;
		int B = who[*it2], l = lca(at, B), super = lca(who[*hv.begin()], B);
		sz -= max(0, dep[super]-dep[l])+dep[at]-dep[l];
	} else
	{
		auto it2 = it; it2--; int A = *it2;
		it2 = it; it2++; int B = *it2;
		int dA = dep[lca(who[A], at)], dB = dep[lca(at, who[B])];
		sz -= dep[at]-max(dA, dB);
	}
	hv.erase(pre[at]);
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
	par[0][0] = -1; dfs(0);
	for (int j = 1;j < 20;j++) for (int i = 0;i < n;i++) par[j][i]=par[j-1][i]!=-1?par[j-1][par[j-1][i]]:-1;
	int ptr = 0;
	for (int i = 0;i < n;i++)
	{
		add(i);
		while (sz > k) rem(ptr++);
		ans = max(ans, i-ptr+1);
	}
	printf("%d\n", ans);
	return 0;
}