#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const char S[] = "codeforces";

	void work()
	{
		big k;
		scanf("%lld", &k);
		for (int x = 1; x < 40; x++)
			for (int c = 0; c <= 10; c++)
			{
				big t = 1;
				for (int i = 0; i < c; i++)
					t *= x + 1;
				for (int i = c; i < 10; i++)
					t *= x;
				if (t >= k)
				{
					for (int i = 0; i < c; i++)
						for (int j = 0; j < x + 1; j++)
							putchar(S[i]);
					for (int i = c; i < 10; i++)
						for (int j = 0; j < x; j++)
							putchar(S[i]);
					putchar('\n');
					return;
				}
			}
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}