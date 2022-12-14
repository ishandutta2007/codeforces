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
		
		if(a==1)
		{
			if(x[1]==1) printf("0\n");
			else printf("1\n");
			continue;
		}
		
		int g = 0;
		for(int i=1;i<=a;i++) g = gcd(g,x[i]);
		if(g==1) printf("0\n");
		else
		{
			g = 0;
			for(int i=1;i<=a-2;i++) g = gcd(g,x[i]);
			if(gcd(gcd(g,x[a-1]),gcd(x[a],a))==1) printf("1\n");
			else if(gcd(gcd(g,x[a]),gcd(x[a-1],a-1))==1) printf("2\n");
			else printf("3\n");
		}
	}
}