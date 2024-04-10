#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		long long int ans = 0;
		for(int j=0;j<=30;j++)
		{
			for(int i=1;i<=a;i++)
			{
				if((x[i]>>j)%2==0)
				{
					goto u;
				}
			}
			ans += (1<<j);
			u:;
		}
		printf("%lld\n",ans);
	}
}