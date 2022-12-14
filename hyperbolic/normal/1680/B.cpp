#include <stdio.h>

char x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int sum = 0;
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='R') sum++;
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]!='R') continue;
				int sum2 = 0;
				for(int k=i;k<=a;k++)
				{
					for(int l=j;l<=b;l++)
					{
						if(x[k][l]=='R') sum2++;
					}
				}
				if(sum2==sum)
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