#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef double r32;

const int MaxN = 2005;

int n, nK;
int a[MaxN][MaxN];

int main()
{
	scanf("%d %d", &n, &nK);
	for (int u = 1; u <= n; ++u)
	{
		a[u][u] = -1;
		for (int v = u + 1; v <= n; ++v)
			scanf("%d", &a[u][v]), a[v][u] = a[u][v];
	}

	r32 res = 0;
	for (int u = 1; u <= n; ++u)
	{
		int d = n - count(a[u] + 1, a[u] + n + 1, -1);

		if (d >= nK)
		{
			r32 prob = (r32)nK / d;
			for (int k = 0; k < nK; ++k)
				prob *= (r32)(d - k) / (n - k);

			for (int v = 1; v <= n; ++v)
				if (a[u][v] != -1)
					res += prob * a[u][v];
		}
	}

	printf("%.0f\n", floor(res));

	return 0;
}