#include <stdio.h>

int x[100010];
int count[100010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int min1 = 1, max1 = 1000000000;
	int ans1 = 1000000001;
	while(min1<=max1)
	{
		int h = (min1+max1)/2;
		int sum = 0;
		for(int i=1;i<=a;i++) count[i] = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]<=h) count[1]++;
			else if(x[i]>=h+a)
			{
				min1 = h+1;
				goto u;
			}
			else count[x[i]-h+1]++;
		}
		
		sum = 0;
		for(int i=1;i<=a;i++)
		{
			sum += count[i];
			if(sum<i)
			{
				min1 = h+1;
				goto u;
			}
		}
		ans1 = h;
		max1 = h-1;
		u:;
	}
	
	int min2 = ans1, max2 = 1000000000;
	int ans2 = ans1-1;
	while(min2<=max2)
	{
		int h = (min2+max2)/2;
		int sum = 0;
		for(int i=1;i<=a;i++) count[i] = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]<=h) count[1]++;
			else count[x[i]-h+1]++;
		}
		
		for(int i=1;i<=a;i++)
		{
			sum += count[i];
			if((sum-i+1)>=b)
			{
				max2 = h-1;
				goto v;
			}
		}
		ans2 = h;
		min2 = h+1;
		v:;
	}
	
	printf("%d\n",ans2-ans1+1);
	for(int i=ans1;i<=ans2;i++) printf("%d ",i);
}