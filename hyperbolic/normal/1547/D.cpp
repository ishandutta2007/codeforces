#include <stdio.h>

int x[200010],y[200010],z[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		y[1] = 0;
		z[1] = x[1];
		for(int i=2;i<=a;i++)
		{
			int b = (x[i]&z[i-1]);
			y[i] = (z[i-1]^b);
			z[i] = (x[i]^y[i]);
		}
		
		for(int i=1;i<=a;i++) printf("%d ",y[i]);
		printf("\n");
	}
}