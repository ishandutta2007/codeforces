#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];

int main()
{
	long long r = 0;
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) scanf("%*d%d", a + i);
	sort(a, a + m);
	for (i = 1;; i++)
	{
		if (i & 1) j = i * (i - 1) / 2 + 1;
		else j = i * i / 2;
		if (j > n) break;
	}
	for (j = 1; j < i && j <= m; j++) r += a[m - j];
	printf("%I64d", r);
}