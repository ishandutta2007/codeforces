#include <stdio.h>
#include <string.h>
char x[110][110];
int l[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x[i]+1);
		l[i] = strlen(x[i]+1);
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<i;j++)
		{
			int C = 0;
			if(l[i]!=l[j]) C = 1;
			else
			{
				for(int k=1;k<=l[i];k++)
				{
					if(x[i][k]!=x[j][k])
					{
						C = 1;
						break;
					}
				}
			}
			if(C==0)
			{
				printf("YES\n");
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}