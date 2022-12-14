#include <stdio.h>
#include <string.h>

char x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		scanf("%s",y+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i+=2)
		{
			if(x[i]==y[1])
			{
				printf("YES\n");
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}