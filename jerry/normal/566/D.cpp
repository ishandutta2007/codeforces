#include <bits/stdc++.h>
using namespace std;

vector<int> gr[200005];
int par[200005];
set<int> bar;
int n, q;

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 0;i < n;i++)
	{
		gr[i].push_back(i);
		par[i] = i;
		if (i)
			bar.insert(i-1);
	}
	while (q--)
	{
		int typ, x, y; scanf("%d%d%d", &typ, &x, &y);
		--x, --y;
		if (typ == 1)
		{
			x = par[x], y = par[y];
			if (x == y) continue;
			if (gr[x].size() > gr[y].size()) swap(x, y);
			for (int u: gr[x])
			{
				par[u] = y;
				gr[y].push_back(u);
				if (u && par[u-1] == par[u])
					bar.erase(u-1);
				if (u < n-1 && par[u] == par[u+1])
					bar.erase(u);
			}
			gr[x].clear();
		} else if (typ == 2)
		{
			for (auto it = bar.lower_bound(x);it != bar.end() && (*it) < y;it = bar.erase(it))
			{
				int a = par[*it], b = par[(*it)+1];
				if (gr[a].size() > gr[b].size()) swap(a, b);
				for (int u: gr[a])
				{
					par[u] = b;
					gr[b].push_back(u);
					if (u && par[u-1] == par[u] && u-1 != *it)
						bar.erase(u-1);
					if (u < n-1 && par[u] == par[u+1] && u != *it)
						bar.erase(u);
				}
				gr[a].clear();
			}
		} else
		{
			if (par[x] == par[y]) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}