#include <cstdio>

const int p = 1000000007;

int c[333][333];
int d[333][333];
int e[333][333];

int f(int x, int y)
{
	return y & 1 ? (long long)f(x, y ^ 1)*x%p : y ? f((long long)x*x%p, y >> 1) : 1;
}

int main()
{
	int i, j, k, n, m, l;
	scanf("%d%d%d", &n, &m, &l);
	if (n > m)
	{
		puts("0");
		return 0;
	}
	c[0][0] = 1;
	for (i = 1; i <= m; i++)
	{
		for (j = 0; j <= n; j++) for (k = 0; k <= j; k++)
		{
			if (i != l) d[j][k] = c[j][k];
			else d[j][k] = 0;
			if (j) d[j][k] = (d[j][k] + c[j - 1][k]) % p;
		}
		for (j = 0; j <= n; j++) for (k = 0; k <= j; k++)
		{
			e[j][k] = d[j][k];
			if (k) e[j][k] = (e[j][k] + d[j][k - 1]) % p;
		}
		for (j = 0; j <= n; j++) for (k = 0; k <= j; k++) c[j][k] = e[j][k];
	}
	i = c[n][n];
	for (j = 1; j <= n; j++) i = (long long)i * j % p;
	printf("%d", i);
}