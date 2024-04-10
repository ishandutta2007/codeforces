#include <stdio.h>

int x[110010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int ans = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=a-1;i>=1;i--)
		{
			if(x[i+1]==0)
			{
				printf("-1\n");
				goto u;
			}
			while(x[i]>=x[i+1]) ans++, x[i]/=2;
		}
		printf("%d\n",ans);
		u:;
	}
}