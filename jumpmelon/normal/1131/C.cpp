#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXN = 100, INF = 0x3f3f3f3f;
	int A[MAXN], F[MAXN][MAXN], P[MAXN][MAXN], Pr[MAXN], R0[MAXN], R1[MAXN];

	inline void to_min(int &a, int &p, int b, int x)
	{
		if (b < a)
		{
			a = b;
			p = x;
		}
	}

	void work()
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		sort(A, A + n);
		for (int i = 2; i < n; i++)
			memset(F[i], INF, sizeof(int[i]));
		for (int i = 1; i < n - 1; i++)
			for (int a = 0; a < i; a++)
			{
				to_min(F[i + 1][a], P[i + 1][a], max(F[i][a], A[i] - A[i - 1]), -1);
				to_min(F[i + 1][i - 1], P[i + 1][i - 1], max(F[i][a], A[i] - A[a]), a);
			}
		int ans = INF, p = 0;
		for (int i = 0; i < n - 1; i++)
			to_min(ans, p, max(F[n - 1][i], A[n - 1] - A[i]), i);
		int pt = p;
		for (int i = n - 1; i > 1; i--)
		{
			if (~P[i][p])
				Pr[i - 1] = p = P[i][p];
			else
				Pr[i - 1] = i - 2;
		}
		int c0 = 0, c1 = 0;
		for (int i = n - 2; i; i = Pr[i])
			R0[c0++] = A[i];
		for (int i = pt; i; i = Pr[i])
			R1[c1++] = A[i];
		reverse(R0, R0 + c0);
		reverse(R1, R1 + c1);
		printf("%d ", A[0]);
		for (int i = 0; i < c0; i++)
			printf("%d ", R0[i]);
		printf("%d ", A[n - 1]);
		for (int i = c1 - 1; i >= 0; i--)
			printf("%d ", R1[i]);
		putchar('\n');
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}