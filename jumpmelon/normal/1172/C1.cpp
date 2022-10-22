#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const int MAXN = 200000, MAXM = 3000, P = 998244353;
	int A[MAXN + 1], W[MAXN + 1], F[MAXM + 1][MAXM + 1];

	int inv(int x) { return x == 1 ? 1 : int(big(P - P / x) * inv(P % x) % P); }

	void work()
	{
		int n, m, s = 0, s0 = 0, s1 = 0, v0 = 0, v1 = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &W[i]);
			s += W[i];
			(A[i] ? s1 : s0) += W[i];
		}
		F[0][0] = 1;
		for (int i = 0; i < m; i++)
			for (int j = 0; j <= i; j++)
				if (F[i][j])
				{
					int iv = int((big)F[i][j] * inv(s + j - (i - j)) % P);
					F[i + 1][j] = int((F[i + 1][j] + big(s0 - (i - j)) * iv) % P);
					F[i + 1][j + 1] = int((F[i + 1][j + 1] + big(s1 + j) * iv) % P);
				}
		for (int i = 0, v = 1; i <= m && i <= s0; i++)
		{
			if (i)
				v = int((big)v * (1 + P - inv(s0 - i + 1)) % P);
			v0 = int((v0 + (big)F[m][m - i] * v) % P);
		}
		for (int i = 0, v = 1; i <= m; i++)
		{
			if (i)
				v = int((big)v * (1 + inv(s1 + i - 1)) % P);
			v1 = int((v1 + (big)F[m][i] * v) % P);
		}
		for (int i = 1; i <= n; i++)
			printf("%d\n", int((big)W[i] * (A[i] ? v1 : v0) % P));
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}