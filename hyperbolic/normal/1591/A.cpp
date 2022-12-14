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
		int prev = 0;
		int ans = 1;
		
		if(x[1]==1) prev = 1, ans++;
		for(int i=2;i<=a;i++)
		{
			if(x[i]==0)
			{
				if(prev==0)
				{
					printf("-1\n");
					goto u;
				}
				else prev = 0;
			}
			else
			{
				if(prev==0) prev = 1, ans++;
				else prev = 1, ans+=5;
			}
		}
		printf("%d\n",ans);
		u:;
	}
}