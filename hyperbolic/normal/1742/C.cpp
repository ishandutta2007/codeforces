#include <stdio.h>

char x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=8;i++) scanf("%s",x[i]+1);
		
		for(int i=1;i<=8;i++)
		{
			int C = 1;
			for(int j=1;j<=8;j++) if(x[i][j]=='B') C = 0;
			if(C)
			{
				printf("R\n");
				goto u;
			}
		}
		printf("B\n");
		u:;
	}
}