#include <bits/stdc++.h>
using namespace std;

long long n, x[200005], p[200005], lo, at;

int main()
{
	lo = 2147483647;
	scanf("%lld", &n);
	for (long long i = 0;i < n;i++)
	{
		scanf("%lld", x+i);
		lo = min(lo, x[i]);
	}
	for (long long i = n-1;i >= 0;i--) if (x[i] == lo)
		p[at=i] = i;
	for (long long i = n-1;i >= 0;i--)
		if (x[i] != lo)
			p[i] = at;
		else
			at = i;
	long long ans = 0;
	for (long long i = 0;i < n;i++)
	{
		long long alt = lo*n+(p[i]-i+n)%n;
		if (alt > ans) ans = alt;
	}
	printf("%lld\n", ans);
	return 0;
}