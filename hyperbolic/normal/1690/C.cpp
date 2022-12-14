#include <stdio.h>

int x[200010],y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		int prev = 0;
		for(int i=1;i<=a;i++)
		{
			if(prev<=x[i]) printf("%d ",y[i]-x[i]);
			else printf("%d ",y[i]-prev);
			prev = y[i];
		}
		printf("\n");
	}
}