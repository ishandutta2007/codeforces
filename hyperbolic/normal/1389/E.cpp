#include <stdio.h>

long long int gcd(long long int a,long long int b)
{
	return a?gcd(b%a,a):b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long int d = gcd(b-1,c);
		long long int S = c/d;
		
		long long int ans = 0;
		
		long long int L = a<b?a:b;
		long long int k = (L-1)/S;
		ans += k*(L-k*S);
		long long int start = L-k*S+1;
		long long int u = (L-start+1)/S;
		ans += (2*k-u-1)*u*S/2;
		ans += (L-start-u*S+1)*(u-1);
		printf("%lld\n",ans);
	}
}