#include <stdio.h>
long long int MAX = 1;

long long int x[300010],y[300010],z[300010];
long long int S[300010],S2[300010],S3[300010];
int main()
{
	for(int i=1;i<=15;i++) MAX*=10;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	long long int min = 1, max = MAX;
	long long int ans = 0;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		
		long long int sum = 0;
		for(int i=a;i>=1;i--)
		{
			if(sum + (x[i]/2) <=h)
			{
				sum += (x[i]/2);
				y[i] = x[i]%2;
				z[i] = x[i]/2;
			}
			else
			{
				y[i] = x[i] - 2*(h-sum);
				z[i] = (h-sum);
				sum = h;
			}
		}
		
		if(sum<h)
		{
			max = h-1;
			continue;
		}
		for(int i=1;i<=a;i++) S2[i] = S2[i-1] + y[i];
		for(int i=1;i<=a;i++) S3[i] = S3[i-1] + z[i];
		for(int i=1;i<=a;i++)
		{
			if(S3[i]>S2[i])
			{
				max = h-1;
				goto u;
			}
		}
		ans = h;
		min = h+1;
		u:;
	}
	printf("%lld",ans);
}