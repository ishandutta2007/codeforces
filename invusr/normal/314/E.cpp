#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef unsigned u32;

const int MaxN = 100005;

int n;
char s[MaxN];

u32 f_pool[MaxN], *f = f_pool;
u32 g_pool[MaxN], *g = g_pool;

inline u32 solve()
{
	if (n & 1)
		return 0;

	f[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		swap(f, g);

		int up = min(i, n - i);
		if (s[i] != '?')
		{
			f[0] = 0;
			for (int j = 1; j <= up; ++j)
				f[j] = g[j - 1];
		}
		else
		{
			f[0] = g[1];
			for (int j = 1; j <= up; ++j)
				f[j] = g[j + 1] + g[j - 1] * 25u;
		}
	}

	return f[0];
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);

	printf("%u\n", n & 1 ? 0 : solve());

	return 0;
}