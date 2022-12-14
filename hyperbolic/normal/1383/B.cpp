#include <stdio.h>

int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int j=30;j>=0;j--)
		{
			int count = 0;
			for(int i=1;i<=a;i++) y[i] = (x[i]/(1<<j))%2;
			for(int i=1;i<=a;i++) if(y[i]==1) count++;
			if(count%2==1)
			{
				if(count%4==3 && (a-count)%2==0) printf("LOSE\n");
				else printf("WIN\n");
				goto u;
			}
		}
		printf("DRAW\n");
		u:;
	}
}