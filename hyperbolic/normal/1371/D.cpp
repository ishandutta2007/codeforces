#include <stdio.h>

int x[310][310];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) x[i][j] = 0;
		int count = 0;
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(count==b) goto u;
				x[j][(j+i-1-1)%a+1] = 1;
				count++;
			}
		}
		u:;
		
		if(b%a==0) printf("0\n");
		else printf("2\n");
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++) printf("%d",x[i][j]);
			printf("\n");
		}
	}
}