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
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		int max = x[1]-y[1];
		for(int i=1;i<=a;i++) max = max>x[i]-y[i]?max:x[i]-y[i];
		if(max<0) printf("NO\n");
		else
		{
			for(int i=1;i<=a;i++) x[i] -= max;
			for(int i=1;i<=a;i++) if(x[i]<0) x[i] = 0;
			for(int i=1;i<=a;i++)
			{
				if(x[i]!=y[i])
				{
					printf("NO\n");
					goto u;
				}
			}
			printf("YES\n");
			u:;
		}
	}
}