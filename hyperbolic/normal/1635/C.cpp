#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		if(x[a]<0)
		{
			int control = 0;
			for(int i=1;i<a;i++) if(x[i]>x[i+1]) control = 1;
			if(control==1) printf("-1\n");
			else printf("0\n");
		}
		else
		{
			if(x[a-1]<=x[a])
			{
				printf("%d\n",a-2);
				for(int i=1;i<=a-2;i++) printf("%d %d %d\n",i,a-1,a);
			}
			else printf("-1\n");
		}
	}
}