#include <stdio.h>
int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}
long long int lcm(int a, int b)
{
	return a/gcd(a,b) * (long long int)b;
}
int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	int f,g,h;
	f = a/b;
	g = a/c;
	h = a/lcm(b,c);
	long long int s = 0;
	s += (long long int)d * (f-h);
	s += (long long int)e * (g-h);
	if(d>e) s+= (long long int) d * h;
	else s+= (long long int)e*h;
	printf("%I64d",s);
}