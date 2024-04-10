#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	big divfloor(big a, big b)
	{
		big k = a / b;
		if (k * b > a)
			k--;
		return k;
	}

	big divceil(big a, big b)
	{
		big k = a / b;
		if (k * b < a)
			k++;
		return k;
	}

	void work()
	{
		big n, i_l, i_r, i_k;
		scanf("%lld%lld%lld%lld", &n, &i_l, &i_r, &i_k);
		big d = i_l <= i_r ? i_r - i_l + 1 : i_r + n - i_l + 1;
		big s = i_k - d, v = n - d + 1, ans = -1;
		if (n <= 1000000)
		{
			for (big r = 0; r <= n; r++)
			{
				big a = max(0LL, r - v), b = min(d, r);
				big mink = max(0LL, divceil(s - b, n + r));
				big maxk = divfloor(s - a, n + r);
				if (mink <= maxk)
					ans = max(ans, r);
			}
		}
		else
		{
			for (big k = 0; k * n <= s; k++)
			{
				big t = s - k * n;
				big minr = 0, maxr = n;
				if (k)
					maxr = min(maxr, divfloor(t, k));
				maxr = min(maxr, divfloor(t + v, k + 1));
				if (k)
					minr = max(minr, divceil(t - d, k));
				else if (t > d)
					continue;
				minr = max(minr, divceil(t, k + 1));
				if (minr <= maxr)
					ans = max(ans, maxr);
			}
		}
		printf("%lld\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}