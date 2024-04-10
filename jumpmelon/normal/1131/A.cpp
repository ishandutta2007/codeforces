#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	void work()
	{
		int w1, h1, w2, h2;
		scanf("%d%d%d%d", &w1, &h1, &w2, &h2);
		printf("%d\n", (w1 + h1 + 2) * 2 + h2 * 2);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}