#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const int MAXN = 250000;
	int Fac[MAXN + 1];

	void work()
	{
		int n, m;
		scanf("%d%d", &n, &m);
		Fac[0] = 1;
		for (int i = 1; i <= n; i++)
			Fac[i] = int((big)Fac[i - 1] * i % m);
		int ans = 0;
		for (int l = 1; l <= n; l++)
			ans = int((ans + big(n - l + 1) * (n - l + 1) % m * Fac[l] % m * Fac[n - l]) % m);
		printf("%d\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}