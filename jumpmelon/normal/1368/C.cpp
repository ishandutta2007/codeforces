#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	void work()
	{
		int n, d = 0, f = 0;
		scanf("%d", &n);
		printf("%d\n", 8 + n * 7);
		printf("%d %d\n", 0, 0);
		printf("%d %d\n", 0, 1);
		printf("%d %d\n", 0, 2);
		printf("%d %d\n", 1, 0);
		printf("%d %d\n", 1, 2);
		printf("%d %d\n", 2, 0);
		printf("%d %d\n", 2, 1);
		printf("%d %d\n", 2, 2);
		for (int i = 0; i < n; i++)
		{
			f ^= 1;
			printf("%d %d\n", 2, d + 3);
			printf("%d %d\n", 2, d + 4);
			if (f)
			{
				printf("%d %d\n", 3, d + 2);
				printf("%d %d\n", 3, d + 4);
				printf("%d %d\n", 4, d + 2);
				printf("%d %d\n", 4, d + 3);
				printf("%d %d\n", 4, d + 4);
			}
			else
			{
				printf("%d %d\n", 1, d + 2);
				printf("%d %d\n", 1, d + 4);
				printf("%d %d\n", 0, d + 2);
				printf("%d %d\n", 0, d + 3);
				printf("%d %d\n", 0, d + 4);
			}
			d += 2;
		}
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}