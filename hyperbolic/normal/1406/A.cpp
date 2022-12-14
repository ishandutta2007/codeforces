#include <stdio.h>

int x[110],count[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=100;i++) count[i] = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) count[x[i]]++;
		
		int ans = 0;
		for(int i=0;i<=100;i++)
		{
			if(count[i]>=1) count[i]--;
			else
			{
				ans += i;
				break;
			}
		}
		for(int i=0;i<=100;i++)
		{
			if(count[i]>=1) count[i]--;
			else
			{
				ans += i;
				break;
			}
		}
		printf("%d\n",ans);
	}
}