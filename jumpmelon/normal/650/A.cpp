#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;
	typedef pair<int, int> pa;

	map<int, int> CX, CY;
	map<pa, int> CP;

	void work()
	{
		int n;
		big ans = 0;
		scanf("%d", &n);
		while (n--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			ans += (CX[x]++) + (CY[y]++) - (CP[pa(x, y)]++);
		}
		printf("%lld\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}