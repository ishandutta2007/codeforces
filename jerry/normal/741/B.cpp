#include <bits/stdc++.h>
using namespace std;

namespace UF
{
	int par[1005], ran[1005];
	void init(int n)
	{
		for (int i = 0;i < n;i++) par[i] = i, ran[i] = 0;
	}
	int getpar(int a)
	{
		return par[a]==a?a:(par[a]=getpar(par[a]));
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

int totw[1005], totb[1005];
vector<int> contain[1005];
int w[1005], b[1005];
int dp[1005];
int n, m, W;

int main()
{
	scanf("%d%d%d", &n, &m, &W); UF::init(n);
	for (int i = 0;i < n;i++) scanf("%d", w+i);
	for (int i = 0;i < n;i++) scanf("%d", b+i);
	while (m--)
	{
		int x, y; scanf("%d%d", &x, &y);
		UF::merge(--x, --y);
	}
	for (int i = 0;i < n;i++)
	{
		contain[UF::getpar(i)].push_back(i);
		totw[UF::getpar(i)] += w[i];
		totb[UF::getpar(i)] += b[i];
	}
	for (int i = 0;i < n;i++) if (UF::par[i] == i) for (int j = W;j >= 0;j--)
	{
		if (j+totw[i] <= W) dp[j+totw[i]] = max(dp[j+totw[i]], dp[j]+totb[i]);
		for (int u: contain[i]) if (j+w[u] <= W) dp[j+w[u]] = max(dp[j+w[u]], dp[j]+b[u]);
	}
	int ans = 0;
	for (int i = 0;i <= W;i++) ans = max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}