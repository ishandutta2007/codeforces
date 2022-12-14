#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		if(a==0)
		{
			printf("Y 0.00000 0.00000\n");
			continue;
		}
		if(a<4)
		{
			printf("N\n");
			continue;
		}
		
		double min = 2;
		double max = 12345;
		int count = 100;
		while(count--)
		{
			double h = (min+max)/2;
			if(h/(h-1) + h <=a) min = h;
			else max = h;
		}
		
		printf("Y %.12lf %.12lf\n",min,a-min);
	}
}