#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		long long int g1 = 0, g2 = 0;
		for(int i=1;i<=a;i+=2) g1 = gcd(g1,x[i]);
		for(int i=2;i<=a;i+=2) g2 = gcd(g2,x[i]);
		
		int control1 = 0, control2 = 0;
		for(int i=2;i<=a;i+=2) if(x[i]%g1==0) control1 = 1;
		for(int i=1;i<=a;i+=2) if(x[i]%g2==0) control2 = 1;
		if(control1==0) printf("%lld\n",g1);
		else if(control2==0) printf("%lld\n",g2);
		else printf("0\n");
	}
}