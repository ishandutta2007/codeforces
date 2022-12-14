#include <stdio.h>

int sum[100010];
int x[100010],count[100010];
int left[100010],right[100010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		sum[c]++, sum[d+1]--;
	}
	
	int C = 0;
	for(int i=1;i<=b;i++)
	{
		C += sum[i];
		count[i] = C;
	}
	
	int R = 1;
	for(int i=1;i<=b;i++)
	{
		int p = 0;
		int min = 1, max = R-1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h]<=count[i])
			{
				p = h;
				min = h+1;
			}
			else max = h-1;
		}
		left[i] = p+1;
		x[p+1] = count[i];
		if(p+1==R) R++;
	}
	
	R = 1;
	for(int i=b;i>=1;i--)
	{
		int p = 0;
		int min = 1, max = R-1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h]<=count[i])
			{
				p = h;
				min = h+1;
			}
			else max = h-1;
		}
		right[i] = p+1;
		x[p+1] = count[i];
		if(p+1==R) R++;
	}
	
	
	int ans = 0;
	for(int i=1;i<=b;i++)
	{
		int t = left[i]+right[i]-1;
		ans = ans>t?ans:t;
	}
	printf("%d",ans);
}