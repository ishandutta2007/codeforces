#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const int MAXN = 200000;
	int t, A[MAXN + 2], P[MAXN + 2];
	big Sum[MAXN + 2];

	inline bool check(int i, int j, int k)
	{
		if (i > k)
			swap(i, k);
		return (Sum[k] - Sum[j]) * (j - i) > (Sum[j] - Sum[i]) * (k - j);
	}

	inline big y(int i, int j) { return (big)A[i] * (j - i) + Sum[i] - Sum[j]; }

	void insert(int i)
	{
		while (t >= 2 && !check(P[t - 1], P[t], i))
			t--;
		P[++t] = i;
	}

	big find(int i)
	{
		int a = 1, b = t;
		while (a < b)
		{
			int mid = (a + b) >> 1;
			if (y(i, P[mid]) <= y(i, P[mid + 1]))
				a = mid + 1;
			else
				b = mid;
		}
		return y(i, P[a]);
	}

	void work()
	{
		int n;
		big st = 0, ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &A[i]);
			st += (big)i * A[i];
		}
		for (int i = 1; i <= n; i++)
			Sum[i + 1] = Sum[i] + A[i];
		t = 0;
		for (int i = 1; i <= n; i++)
		{
			insert(i);
			ans = max(ans, find(i));
		}
		for (int i = 1; i <= n; i++)
			Sum[i] = Sum[i - 1] + A[i];
		t = 0;
		for (int i = n; i >= 1; i--)
		{
			insert(i);
			ans = max(ans, find(i));
		}
		printf("%lld\n", st + ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}