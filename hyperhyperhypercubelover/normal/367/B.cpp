#include <cstdio>
#include <algorithm>

using namespace std;

int a[200002];
int b[200002];
int c[400004];
int d[400004];
int f[200002];

int main()
{
	int i, j, k, n, m, l, r = 0;
	scanf("%d%d%d", &n, &m, &l);
	for (i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		d[i] = a[i];
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", b + i);
		d[i + n] = b[i];
	}
	sort(d, d + n + m);
	for (i = 0; i < n; i++) a[i] = lower_bound(d, d + n + m, a[i]) - d;
	k = 0;
	for (i = 0; i < m; i++)
	{
		b[i] = lower_bound(d, d + n + m, b[i]) - d;
		if (!c[b[i]]) k++;
		c[b[i]]++;
	}
	for (i = 0; i < l; i++) if (i + (m - 1LL)*l < n)
	{
		for (j = 0; j < m; j++)
		{
			c[a[i + j*l]]--;
			if (!c[a[i + j*l]]) k--;
		}
		if (!k) f[r++] = i + 1;
		for (j = m; i + j*l < n; j++)
		{
			c[a[i + j*l]]--;
			if (!c[a[i + j*l]]) k--;
			if (!c[a[i + (j - m)*l]]) k++;
			c[a[i + (j - m)*l]]++;
			if (!k) f[r++] = i + (j - m + 1)*l + 1;
		}
		while (i + (j - m)*l < n)
		{
			if (!c[a[i + (j - m)*l]]) k++;
			c[a[i + (j - m)*l]]++;
			j++;
		}
	}
	printf("%d\n", r);
	sort(f, f + r);
	for (i = 0; i < r; i++) printf("%d ", f[i]);
}