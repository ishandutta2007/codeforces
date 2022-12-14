#include <stdio.h>

int x[110];
char y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) x[i] += 10;	
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			scanf("%s",y+1);
			for(int j=1;j<=b;j++)
			{
				if(y[j]=='D') x[i]++;
				else x[i]--;
			}
		}
		for(int i=1;i<=a;i++) printf("%d ",x[i]%10);
		printf("\n");
	}
}