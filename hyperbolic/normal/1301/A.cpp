#include <stdio.h>
#include <string.h>

char x[100010],y[100010],z[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s%s",x+1,y+1,z+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++)
		{
			if(x[i]==z[i] || y[i]==z[i]);
			else
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}