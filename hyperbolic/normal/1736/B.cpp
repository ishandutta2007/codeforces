#include <stdio.h>

int gcd(int s, int t)
{
	return s?gcd(t%s,s):t;
}
int lcm(int s, int t)
{
	return (s*t)/gcd(s,t);
}

int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		y[1] = x[1], y[a+1] = x[a];
		for(int i=2;i<=a;i++) y[i] = lcm(x[i-1],x[i]);
		
		for(int i=1;i<=a;i++)
		{
			if(gcd(y[i],y[i+1])!=x[i])
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}