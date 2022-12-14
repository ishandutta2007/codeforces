#include <stdio.h>

int x[1010][10];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) for(int j=1;j<=5;j++) scanf("%d",&x[i][j]);
		
		for(int j=1;j<=5;j++)
		{
			for(int k=j+1;k<=5;k++)
			{
				int C1 = 0, C2 = 0, C3 = 0;
				for(int i=1;i<=a;i++)
				{
					if(x[i][j]==1&&x[i][k]==0) C1++;
					if(x[i][j]==0&&x[i][k]==1) C2++;
					if(x[i][j]==1&&x[i][k]==1) C3++;
				}
				
				if(C1<=a/2 && C2<=a/2 && C1+C2+C3==a)
				{
					printf("YES\n");
					goto u;
				}
			}
		}
		printf("NO\n");
		u:;
	}
}