#include <stdio.h>

char ans[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) ans[i][j] = '.';
		
		int count = 0;
		for(int i=1;i<=a&&count<b;i+=2) count++,ans[i][i] = 'R';
		
		if(count<b) printf("-1\n");
		else
		{
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=a;j++) printf("%c",ans[i][j]);
				printf("\n");
			}
		}
	}
}