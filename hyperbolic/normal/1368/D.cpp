#include <stdio.h>

int x[200010];
int count[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<=19;j++)
		{
			count[j] += x[i]%2;
			x[i]/=2;
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int S = 0;
		for(int j=0;j<=19;j++)
		{
			if(count[j]>=1)
			{
				S += (1<<j);
				count[j]--;
			}
		}
		ans += S*S;
	}
	printf("%lld",ans);
}