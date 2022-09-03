#include <cstdio>

int a[111111];
int b[111111];

long long d(int i, int j)
{
	return (long long)(a[i] - a[j])*(a[i] - a[j]) + (long long)(b[i] - b[j])*(b[i] - b[j]);
}

long long f(int i, int j, int k)
{
	return (long long)a[i] * b[j] - (long long)a[j] * b[i] + (long long)a[j] * b[k] - (long long)a[k] * b[j] + (long long)a[k] * b[i] - (long long)a[i] * b[k];
}

int main()
{
	int i, j, k, l, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d%d", a + i, b + i);
	i = 0;
	k = 1;
	for (j = 2; j < n; j++) if (d(i, j) < d(i, k)) k = j;
	for (l = 1; l < n; l++) if (i != l && k != l && f(i, k, l)) break;
	for (j = 1; j < n; j++) if (i != j && k != j && f(i, j, k) && d(i, j) < d(i, l)) l = j;
	printf("%d %d %d", i + 1, k + 1, l + 1);
}