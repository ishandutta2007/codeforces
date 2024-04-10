#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const int MAXN = 200000, M = 20;
	int C[M], A[MAXN];

	void work()
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			for (int j = 0; j < M; j++)
				if (x >> j & 1)
					C[j]++;
		}
		for (int i = 0; i < M; i++)
			for (int j = 0; j < C[i]; j++)
				A[j] |= 1 << i;
		big ans = 0;
		for (int i = 0; i < n; i++)
			ans += (big)A[i] * A[i];
		printf("%lld\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}