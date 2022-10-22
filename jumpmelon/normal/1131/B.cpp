#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	void work()
	{
		int n, a0 = 0, b0 = 0, ans = 0;
		scanf("%d", &n);
		while (n--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			ans += max(0, min(a, b) - max(a0, b0) + 1);
			if (n && a == b)
				ans--;
			a0 = a;
			b0 = b;
		}
		printf("%d\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}