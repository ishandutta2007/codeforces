#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
long long int lcm(long long int a, long long int b)
{
	return (a/gcd(a,b))*b;
}

int x[1000010],y[1000010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++) y[i] = gcd(x[i],b);
	
	long long int s = gcd(y[1],b);
	for(int i=2;i<=a;i++)
	{
		s = lcm(s,y[i]);
		s = gcd(s,b);
	}
	
	printf("%s",s==b?"Yes":"No");
}