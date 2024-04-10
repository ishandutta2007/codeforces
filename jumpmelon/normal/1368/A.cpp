#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	void work()
	{
		int kase;
		scanf("%d", &kase);
		while (kase--)
		{
			big a, b, n;
			int ans = 0;
			scanf("%lld%lld%lld", &a, &b, &n);
			while (a <= n && b <= n)
			{
				if (a < b)
					a += b;
				else
					b += a;
				ans++;
			}
			printf("%d\n", ans);
		}
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}