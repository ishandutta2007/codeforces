#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXN = 100000, INF = 0x3f3f3f3f;
	int n, k, A[MAXN + 1], Sum[MAXN + 1];

	bool exists_k()
	{
		for (int i = 1; i <= n; i++)
			if (A[i] == k)
				return 1;
		return 0;
	}

	bool judge()
	{
		if (!exists_k())
			return 0;
		if (n == 1)
			return 1;
		for (int i = 1; i < n; i++)
			if (A[i] >= k && A[i + 1] >= k)
				return 1;
		for (int i = 1; i + 2 <= n; i++)
			if (A[i] >= k && A[i + 2] >= k)
				return 1;
		return 0;
	}

	void work()
	{
		int kase;
		scanf("%d", &kase);
		while (kase--)
		{
			scanf("%d%d", &n, &k);
			for (int i = 1; i <= n; i++)
				scanf("%d", &A[i]);
			puts(judge() ? "yes" : "no");
		}
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}