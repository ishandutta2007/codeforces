#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXN = 1000000;
	bool Vis[MAXN + 1];
	int P[MAXN + 1], L[MAXN + 1], C[MAXN + 1];
	bitset<MAXN + 1> F, Tmp;

	void work()
	{
		int n, k, m = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &P[i]);
		for (int i = 1; i <= n; i++)
			if (!Vis[i])
			{
				int &d = L[++m];
				for (int j = i; !Vis[j]; Vis[j] = 1, j = P[j])
					d++;
				C[d]++;
			}
		F.set(0);
		for (int i = 1; i <= n; i++)
		{
			int t = 1;
			while (t <= C[i])
			{
				F |= F << (t * i);
				C[i] -= t;
				t <<= 1;
			}
			if (C[i])
				F |= F << (C[i] * i);
		}
		printf("%d ", F.test(k) ? k : k + 1);
		int ans = 0, t = 0;
		for (int i = 1; i <= m; i++)
		{
			int v = min(L[i] >> 1, k);
			ans += v << 1;
			k -= v;
			if ((v << 1) < L[i])
				t++;
		}
		printf("%d\n", ans + min(t, k));
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}