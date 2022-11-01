#include <bits/stdc++.h>
using namespace std;

int k[100005];
int gcd[50][50];
int n, m;

int slv(vector<pair<int, int> >& loc)
{
	int ans = 0;
	int i = 0, j = 0;
	map<int, int> cond, freq;
	while (true)
	{
		if (i == loc.size()) break;
		for (;j < loc.size() && loc[j].first-loc[i].first == j-i;j++)
		{
			while (i <= j)
			{
				bool ok = true;
				for (auto u: cond) if (abs(u.second-loc[j].second)%gcd[u.first][k[loc[j].first]])
				{
					ok = false;
					break;
				}
				if (ok)
					break;
				if (!--freq[k[loc[i].first]]) cond.erase(k[loc[i].first]);
				i++;
			}
			freq[k[loc[j].first]]++;
			cond[k[loc[j].first]] = loc[j].second;
			ans = max(ans, j-i+1);
		}
		if (!--freq[k[loc[i].first]]) cond.erase(k[loc[i].first]);
		if (i++ == j) j++;
	}
	return ans;
}

int main()
{
	for (int i = 1;i <= 40;i++) for (int j = 1;j <= 40;j++) gcd[i][j] = __gcd(i, j);
	scanf("%d%d", &n, &m);
	vector<vector<pair<int, int> > > loc;
	loc.resize(m+1);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", k+i);
		for (int j = 0;j < k[i];j++)
		{
			int x; scanf("%d", &x);
			loc[x].emplace_back(i, j);
		}
	}
	for (int v = 1;v <= m;v++)
		printf("%d\n", slv(loc[v]));
	return 0;
}