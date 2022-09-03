#include <cstdio>
#include <algorithm>

using namespace std;

int a[2002];
int c[5005];
long long d[10001];

int main()
{
	long long r = 0;
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	for (i = 1; i < n; i++) for (j = 0; j < i; j++) c[a[i] - a[j]]++;
	for (i = 0; i < 5000; i++) for (j = 0; j < 5000; j++) d[i + j] += (long long)c[i] * c[j];
	for (i = 1; i < 5000; i++)
	{
		d[i] += d[i - 1];
		r += d[i - 1] * c[i];
	}
	printf("%.12f", 8.*r / n / n / n / (n - 1) / (n - 1) / (n - 1));
}