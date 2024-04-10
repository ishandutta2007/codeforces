#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int limit = a+1;
		for(int i=a;i>=1;i--)
		{
			if(x[i]!=i)
			{
				limit = i;
				break;
			}
		}
		
		double ans = 1;
		for(int i=1;i<=b;i++)
		{
			int c;
			double d;
			scanf("%d%lf",&c,&d);
			if(c>=limit) ans *= (1-d);
		}
		if(limit==a+1) printf("1.000000\n");
		else printf("%.12lf\n",1-ans);
	}
}