#include <bits/stdc++.h>
using namespace std;

int a[200005], b, n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) scanf("%d", a+i);
	sort(a, a+n);
	while (m--)
	{
		scanf("%d", &b);
		printf("%d ", upper_bound(a, a+n, b)-a);
	}
	printf("\n"); return 0;
}