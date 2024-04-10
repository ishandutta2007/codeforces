#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<a;i++)
		{
			if(x[i] <= b)
			{
				x[a] += (x[i]);
				b -= (x[i]);
				x[i] = 0;
			}
			else
			{
				x[a] += b;
				x[i] -= b;
				b = 0;
			}
		}
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		printf("\n");
	}
}