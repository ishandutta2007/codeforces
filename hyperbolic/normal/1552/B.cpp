#include <stdio.h>

struct str{
	int v[6];
}x[50010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b,c,d,e,f;
			scanf("%d%d%d%d%d",&x[i].v[1],&x[i].v[2],&x[i].v[3],&x[i].v[4],&x[i].v[5]);
		}
		
		int ans = 1;
		for(int i=2;i<=a;i++)
		{
			int count = 0;
			for(int j=1;j<=5;j++) if(x[ans].v[j]<x[i].v[j]) count++;
			if(count<=2) ans = i;
		}
		
		for(int i=1;i<=a;i++)
		{
			if(ans==i) continue;
			
			int count = 0;
			for(int j=1;j<=5;j++) if(x[ans].v[j]<x[i].v[j]) count++;
			if(count<=2)
			{
				printf("-1\n");
				goto u;
			}
		}
		printf("%d\n",ans);
		u:;
	}
}