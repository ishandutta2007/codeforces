#include <stdio.h>

int x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++)
		{
			int s = -1, t = -1;
			for(int j=1;j<i;j++) if(x[j]<x[i]) s = j;
			for(int j=i+1;j<=a;j++) if(x[j]<x[i]) t = j;
			if(s!=-1 && t!=-1)
			{
				printf("YES\n");
				printf("%d %d %d\n",s,i,t);
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}