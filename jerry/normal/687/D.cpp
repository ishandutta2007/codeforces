#include <bits/stdc++.h>
using namespace std;

namespace UF
{
	int par[2005], ran[2005];
	void init(int n)
	{
		for (int i = 0;i < n;i++) par[i] = i;
	}
	int getpar(int at)
	{
		return par[at]==at?at:par[at]=getpar(par[at]);
	}
	void merge(int a, int b)
	{
		a = getpar(a), b = getpar(b);
		if (a != b)
		{
			if (ran[a] < ran[b]) par[a] = b;
			else
			{
				par[b] = a;
				if (ran[a] == ran[b]) ran[a]++;
			}
		}
	}
};

struct edge
{
	int a, b, w, id;
	bool operator< (const edge& oth) const
	{
		return (w > oth.w);
	}
} e[500005];
int n, m, q;

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0;i < m;i++)
	{
		scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);
		e[i].a--, e[i].b--;
		e[i].id = i + 1;
	}
	sort(e, e+m);
	while (q--)
	{
		UF::init(n<<1);
		int l, r; scanf("%d%d", &l, &r);
		int ans = -1;
		for (int i = 0;i < m;i++) if (l <= e[i].id && e[i].id <= r)
		{
			if (UF::getpar(e[i].a<<1) == UF::getpar(e[i].b<<1))
			{
				ans = e[i].w;
				break;
			}
			UF::merge(e[i].a<<1, (e[i].b<<1)+1);
			UF::merge(e[i].b<<1, (e[i].a<<1)+1);
		}
		printf("%d\n", ans);
	}
	return 0;
}