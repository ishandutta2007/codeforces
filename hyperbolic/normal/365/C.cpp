#include <stdio.h>
#include <string.h>

long long int count[100010];
char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int b = strlen(x+1);
	for(int i=1;i<=b;i++)
	{
		int sum = 0;
		for(int j=i;j<=b;j++)
		{
			sum += (x[j]-'0');
			count[sum]++;
		}
	}
	if(a==0)
	{
		long long int sum = b*(b+1)/2;
		printf("%lld",2*sum*count[0]-count[0]*count[0]);
		return 0;
	}
	
	long long int ans = 0;
	for(int i=1;i<=b;i++)
	{
		int sum = 0;
		for(int j=i;j<=b;j++)
		{
			sum += (x[j]-'0');
			if(sum==0) continue;
			if(a%sum==0)
			{
				if((a/sum)<=9*b) ans += count[a/sum];
			}
		}
	}
	printf("%lld",ans);
}