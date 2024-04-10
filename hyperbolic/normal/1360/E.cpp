#include <stdio.h>


char x[110][110];
int s1[110][110],s2[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(x[i][j]=='1')
				{
					if(i==a || j==a) continue;
					if(x[i][j+1]=='1' || x[i+1][j]=='1') continue;
					printf("NO\n");
					goto u;
				}
			}
		}
		
		printf("YES\n");
		u:;
	}
}