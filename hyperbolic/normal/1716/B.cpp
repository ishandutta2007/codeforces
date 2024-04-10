#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",a);
		
		for(int i=1;i<=a;i++) x[i] = i;
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		printf("\n");
		for(int i=2;i<=a;i++)
		{
			int t = x[i-1];
			x[i-1] = x[i];
			x[i] = t;
			for(int j=1;j<=a;j++) printf("%d ",x[j]);
			printf("\n");
		}
	}
}