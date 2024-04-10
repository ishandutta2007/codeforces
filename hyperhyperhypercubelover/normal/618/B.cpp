#include <cstdio>
#include <algorithm>

using namespace std;

int a[55];

int main()
{
	int i, j, k, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) for (j = 0; j < n; j++)
	{
		scanf("%d", &k);
		a[i] = max(a[i], k);
		a[j] = max(a[j], k);
	}
	for (i = 0; i < n; i++) if (a[i] == n - 1) break;
	a[i] = n;
	for (i = 0; i < n; i++) printf("%d ", a[i]);
}