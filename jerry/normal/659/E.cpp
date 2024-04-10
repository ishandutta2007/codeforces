#include <bits/stdc++.h>
using namespace std;

namespace UF
{
	int n, par[100005], ran[100005], cyc[100005];
	void init(int _n)
	{
		n = _n;
		for (int i = 0;i < n;i++) par[i] = i;
	}
	int getpar(int i)
	{
		return par[i]==i?par[i]:par[i]=getpar(par[i]);
	}
	void merge(int a, int b)
	{
		a = getpar(a), b = getpar(b);
		if (a == b) cyc[a] = 1;
		else
		{
			if (ran[a] < ran[b])
			{
				par[a] = b;
				cyc[b] |= cyc[a];
			} else
			{
				par[b] = a;
				cyc[a] |= cyc[b];
				if (ran[a] == ran[b])
					ran[a]++;
			}
		}
	}
};

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	UF::init(n);
	for (int i = 0;i < m;i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		--a, --b;
		UF::merge(a, b);
	}
	int ans = 0;
	for (int i = 0;i < n;i++) if (UF::getpar(i) == i && UF::cyc[i] == 0)
		ans++;
	printf("%d\n", ans);
	return 0;
}