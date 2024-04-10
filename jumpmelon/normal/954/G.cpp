#include <bits/stdc++.h>

using namespace std;

namespace program
{
	typedef long long big;

	const int MAXN = 500000;
	int n, r, A[MAXN + 10];
	big k, X[MAXN + 10];

	bool judge(big t)
	{
		big tot = 0, left = k;
		for(int i = 1; i <= n; i++)
			X[i] = A[i];
		for(int i = 1; i <= r; i++)
			tot += X[i];
		for(int i = 1; i <= n; i++)
		{
			if(i > r)
				tot -= X[i - r - 1];
			if(i + r <= n)
				tot += X[i + r];
			if(tot < t)
			{
				if(left < t - tot)
					return 0;
				left -= t - tot;
				X[min(n, i + r)] += t - tot;
				tot = t;
			}
		}
		return 1;
	}

	big find()
	{
		big a = 0, b = 0x3f3f3f3f3f3f3f3fLL;
		while(a < b)
		{
			big mid = (a + b + 1) >> 1;
			if(judge(mid))
				a = mid;
			else
				b = mid - 1;
		}
		return a;
	}

	void work()
	{
		scanf("%d%d%lld", &n, &r, &k);
		for(int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		printf("%lld\n", find());
	}
}

int main()
{
	program::work();
	return 0;
}