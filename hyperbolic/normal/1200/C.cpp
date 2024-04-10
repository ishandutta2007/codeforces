#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
int main()
{
	long long int a,b;
	int c;
	scanf("%lld%lld%d",&a,&b,&c);
	long long int d = a/gcd(a,b);
	long long int e = b/gcd(a,b);
	for(int i=1;i<=c;i++)
	{
		int x0,x1;
		long long int y0,y1;
		scanf("%d%lld%d%lld",&x0,&y0,&x1,&y1);
		
		long long int f,g;
		if(x0==1) f = (y0-1)/d;
		else f = (y0-1)/e;
		if(x1==1) g = (y1-1)/d;
		else g = (y1-1)/e;
		if(f==g) printf("YES\n");
		else printf("NO\n");
	}
}