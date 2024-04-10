#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,a;
	scanf("%lld%lld%lld",&n,&m,&a);
	long long l=(n+a-1)/a;
	long long r=(m+a-1)/a;
	printf("%lld\n",l*r);
	return 0;
}