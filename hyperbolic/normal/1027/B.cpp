#include <stdio.h>

long long int x1,y1;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a%2==1)
	{
		x1 = (a+1)/2;
		y1 = (a-1)/2;
	}
	else x1 = y1 = (a/2);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		
		long long int sum = 0;
		if((c+d)%2==0)
		{
			if(c%2==1)
			{
				sum += (x1+y1)*(c-1)/2;
				sum += (d+1)/2;
			}
			else
			{
				sum += (x1+y1)*(c-2)/2;
				sum += x1;
				sum += d/2;
			}
		}
		else
		{
			sum += ((long long int)a*a+1)/2;
			if(c%2==1)
			{
				sum += (x1+y1)*(c-1)/2;
				sum += d/2;
			}
			else
			{
				sum += (x1+y1)*(c-2)/2;
				sum += y1;
				sum += (d+1)/2;
			}
		}
		printf("%lld\n",sum);
	}
}