#include <bits/stdc++.h>
using namespace std;

namespace UF
{
	vector<int> hv[300005];
	set<int> home;
	int par[300005];
	int n;
	void init(int N)
	{
		n = N;
		for (int i = 1;i < n;i++)
			par[i] = i, home.insert(i), hv[i].push_back(i);
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
			if (hv[a].size() < hv[b].size())
			{
				par[a] = b;
				for (int u: hv[a]) hv[b].push_back(u);
				hv[a].clear();
				home.erase(a);
			} else
			{
				par[b] = a;
				for (int u: hv[b]) hv[a].push_back(u);
				hv[b].clear();
				home.erase(b);
			}
		}
	}
};

vector<int> no[300005];
int n, m, k;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	UF::init(n);
	for (int i = 0;i < m;i++)
	{
		int a, b; scanf("%d%d", &a, &b); --a, --b;
		no[a].push_back(b);
		no[b].push_back(a);
	}
	for (int i = 0;i < n;i++) sort(no[i].begin(), no[i].end());
	for (int i = 1;i < n;i++)
	{
		for (auto it = UF::home.begin();it != UF::home.end();)
		{
			if (*it >= i) break;
			bool inc = true;
			for (auto v: UF::hv[*it])
			{
				auto it3 = lower_bound(no[i].begin(), no[i].end(), v);
				if (it3 == no[i].end() || *it3 != v)
				{
					auto it2 = it; it2++;
					UF::merge(i, *it);
					it = it2;
					inc = false;
					break;
				}
			}
			if (inc) it++;
		}
	}
	int need = 0;
	set<int> slvd;
	int req = UF::home.size();
	for (int i = 1;i < n;i++)
	{
		if (UF::getpar(0) != UF::getpar(i))
		{
			auto it = lower_bound(no[0].begin(), no[0].end(), i);
			if (it == no[0].end() || *it != i)
			{
				need++;
				slvd.insert(UF::getpar(i));
				UF::merge(0, i);
			}
		}
	}
	if (need <= k && slvd.size() == req)
	{
		if (no[0].size()+k < n) printf("possible\n");
		else printf("impossible\n");
	} else
		printf("impossible\n");
	return 0;
}