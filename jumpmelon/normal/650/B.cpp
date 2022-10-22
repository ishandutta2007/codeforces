#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXN = 500000;
	int n, a, b, T, V[MAXN + 1];
	char S[MAXN + 1];

	int calc()
	{
		int ans = 0, cur = 0;
		for (int i = n - 1; i >= 0; i--)
			V[i] = V[i + 1] + a + (S[i] == 'w' ? b : 0) + 1;
		for (int i = 0, p = 0; i < n; i++)
		{
			cur += (S[i] == 'w' ? b : 0) + 1;
			if (cur + i * a <= T)
				ans = max(ans, i + 1);
			while (p < n && (p <= i || cur + 2 * i * a + V[p] > T))
				p++;
			if (cur + 2 * i * a + V[p] <= T)
				ans = max(ans, i + 1 + n - p);
		}
		return ans;
	}

	void work()
	{
		scanf("%d%d%d%d", &n, &a, &b, &T);
		scanf("%s", S);
		int ans = calc();
		reverse(S + 1, S + n);
		printf("%d\n", max(ans, calc()));
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}