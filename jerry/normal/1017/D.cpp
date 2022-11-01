#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > qu[5005];
pair<int, int> ord[5005];
int ans[500005];
int occ[5005];
int w[5005];
int n, m, q;

int rd()
{
	char buf[20]; scanf("%s", buf);
	int x = 0;
	for (int i = 0;i < n;i++) if (buf[i] == '1') x |= (1<<i);
	return x;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0;i < n;i++) scanf("%d", w+i);
	for (int i = 0;i < m;i++) occ[rd()]++;
	for (int i = 0;i < q;i++)
	{
		int x = rd(), y; scanf("%d", &y);
		qu[x].emplace_back(y, i);
	}
	for (int i = 0;i < (1<<n);i++)
	{
		ord[i].second = i;
		for (int j = 0;j < n;j++) if (i&(1<<j)) ord[i].first += w[j];
	}
	sort(ord, ord+(1<<n));
	for (int i = 0;i < (1<<n);i++)
	{
		sort(qu[i].begin(), qu[i].end());
		int tot = 0, at = 0;
		for (auto u: qu[i])
		{
			while (at < (1<<n) && ord[at].first <= u.first)
			{
				tot += occ[ord[at].second^i^((1<<n)-1)];
				at++;
			}
			ans[u.second] = tot;
		}
	}
	for (int i = 0;i < q;i++) printf("%d\n", ans[i]);
	return 0;
}