#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXN = 200000;
	int A[MAXN + 1], B[MAXN + 1], Pos[MAXN + 1];

	void work()
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &B[i]);
			Pos[B[i]] = i;
		}
		bool fl = 1;
		for (int i = 1; i <= B[n]; i++)
			if (B[n - B[n] + i] != i)
			{
				fl = 0;
				break;
			}
		if (fl)
		{
			for (int i = 1; i <= n; i++)
				if (i > B[n] && Pos[i] >= i - B[n])
				{
					fl = 0;
					break;
				}
			if (fl)
				return void(printf("%d\n", n - B[n]));
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, Pos[i] - i + 1);
		printf("%d\n", ans + n);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}