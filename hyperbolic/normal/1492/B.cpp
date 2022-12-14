#include <stdio.h>

int x[100010],prev[100010],max[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		max[1] = x[1];
		prev[1] = 1;
		for(int i=2;i<=a;i++)
		{
			if(x[i]>max[i-1])
			{
				max[i] = x[i];
				prev[i] = i;
			}
			else
			{
				max[i] = max[i-1];
				prev[i] = prev[i-1];
			}
		}
		int p = a;
		while(p>=1)
		{
			int t = prev[p];
			for(int i=t;i<=p;i++) printf("%d ",x[i]);
			p = t-1;
		}
		printf("\n");
	}
}