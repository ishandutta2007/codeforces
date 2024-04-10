#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	void work()
	{
		int n, d, e;
		scanf("%d%d%d", &n, &d, &e);
		e *= 5;
		int ans = n;
		for (int i = 0; i <= n; i += e)
			ans = min(ans, (n - i) % d);
		printf("%d\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}