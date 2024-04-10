#include <bits/stdc++.h>
using namespace std;

long long n, m;

long long foo(long long v)
{
	long long complete = 0;
	if (n%2 == 0) complete = (m-v)*(m-v-1)/2;
	else complete = (m-v)*(m-v+1)/2;
	long long limit = v+m;
	return min(complete, limit)+v+m;
}

void slv()
{
	scanf("%lld", &n); m = n/2;
	if (n < 6) printf("%lld\n", n-1);
	else
	{
		long long x = 0;
		if (n%2 == 0) x = (long long)(m+0.5-0.5*sqrt(16*m+1));
		else x = (long long)(m+1.5-0.5*sqrt(16*m+9));
		printf("%lld\n", max(foo(x), foo(x+1)));
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--) slv();
	return 0;
}