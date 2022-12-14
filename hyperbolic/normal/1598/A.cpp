#include <stdio.h>

char x[3][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s%s",x[1]+1,x[2]+1);
		if(x[1][1]=='1'||x[2][a]=='1') printf("NO\n");
		else
		{
			for(int i=2;i<a;i++)
			{
				if(x[1][i]=='1'&&x[2][i]=='1')
				{
					printf("NO\n");
					goto u;
				}
			}
			printf("YES\n");
			u:;
		}
	}
}