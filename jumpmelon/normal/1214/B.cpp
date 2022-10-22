#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	void work()
	{
		int b, g, n;
		scanf("%d%d%d", &b, &g, &n);
		if (b > n)
			b = n;
		if (g > n)
			g = n;
		printf("%d\n", b + g - n + 1);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}