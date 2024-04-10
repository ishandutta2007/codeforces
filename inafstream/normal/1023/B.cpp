#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
	scanf("%lld%lld",&n,&m);
	if (n*2-1<m)
	{
		puts("0");
		return 0;
	}
	long long r=min(m-1,n);
	long long l=m-r;
	printf("%lld\n",(r-l+1)/2);
	return 0;
}