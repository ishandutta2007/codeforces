#include <stdio.h>

int x[1010],y[1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	
	double min = 0, max = 1000000001;
	double ans = 1000000001;
	int count = 100;
	while(count--)
	{
		double h = (min+max)/2;
		
		double fuel = h;
		for(int i=1;i<a;i++)
		{
			fuel -= (fuel+b)/x[i];
			if(fuel<0) goto u;
			fuel -= (fuel+b)/y[i+1];
			if(fuel<0) goto u;
		}
		fuel -= (fuel+b)/x[a];
		if(fuel<0) goto u;
		fuel -= (fuel+b)/y[1];
		if(fuel<0) goto u;
		
		max = h;
		ans = h;
		continue;
		
		u:;
		min = h;
	}
	if(ans>=1000000001)
	{
		printf("-1");
		return 0;
	}
	printf("%.12lf",ans);
}