#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const int MAXN = 200000, P = 998244353;
	int Deg[MAXN + 1], Fac[MAXN + 1];

	void work()
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			Deg[u]++;
			Deg[v]++;
		}
		Fac[0] = 1;
		for (int i = 1; i <= n; i++)
			Fac[i] = int((big)Fac[i - 1] * i % P);
		int ans = 1;
		for (int i = 1; i <= n; i++)
			ans = int((big)ans * Fac[Deg[i]] % P);
		printf("%d\n", int((big)ans * n % P));
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}