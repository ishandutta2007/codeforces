#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=3;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=3;i++)
		{
			int max = 0;
			for(int j=1;j<=3;j++)
			{
				if(i==j) continue;
				max = max>x[j]?max:x[j];
			}
			max++;
			if(x[i]>=max) printf("0 ");
			else printf("%d ",max-x[i]);
		}
		printf("\n");
	}
}