#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll a[10000005], hv, k;
int n, x;

int main()
{
	scanf("%d%lld", &n, &k);
	for (int i = 0;i < n;i++) { scanf("%d", &x); ++a[x]; }
	for (int i = 10000004;i > 0;i--)
	{
		if (i*2 < 10000005) a[i] += a[i*2];
		if (i*2+1 < 10000005) a[i] += a[i*2+1];
		hv += a[i];
		if (i*2 < 10000005) a[i] += a[i*2];
		if (i*2-1 < 10000005) a[i] += a[i*2-1];
		if (hv >= k)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}