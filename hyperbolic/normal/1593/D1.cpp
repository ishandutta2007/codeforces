#include <stdio.h>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int min = x[1];
		for(int i=2;i<=a;i++) min = min<x[i]?min:x[i];
		
		int g = 0;
		for(int i=1;i<=a;i++) g = gcd(x[i]-min,g);
		if(g==0) printf("-1\n");
		else printf("%d\n",g);
	}
}