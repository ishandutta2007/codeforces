#include <stdio.h>

int count[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int j=0;j<=30;j++) count[j] = 0;
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			for(int j=0;j<=30;j++)
			{
				count[j] += b%2;
				b/=2;
			}
		}
		
		int ans = 0;
		for(int j=30;j>=0;j--)
		{
			if(b>=(a-count[j]))
			{
				ans += (1<<j);
				b -= (a-count[j]);
			}
		}
		printf("%d\n",ans);
	}
}