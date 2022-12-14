#include <stdio.h>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int g = x[1];
		for(int i=1;i<=a;i++) g = gcd(x[i],g);
		printf("%d\n",x[a]/g);
	}
}