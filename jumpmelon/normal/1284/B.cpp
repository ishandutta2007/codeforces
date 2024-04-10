#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const int MAXN = 100000;
	int S[MAXN], A[MAXN], B[MAXN];

	void work()
	{
		int n, m = 0, c = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int l;
			scanf("%d", &l);
			for (int j = 0; j < l; j++)
				scanf("%d", &S[j]);
			bool flag = 1;
			for (int j = 1; j < l; j++)
				if (S[j - 1] < S[j])
					flag = 0;
			if (flag)
			{
				A[m] = S[0];
				B[m] = S[l - 1];
				m++;
			}
			else
				c++;
		}
		big ans = (big)c * c + 2LL * c * m;
		sort(B, B + m);
		for (int i = 0; i < m; i++)
			ans += lower_bound(B, B + m, A[i]) - B;
		printf("%lld\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}