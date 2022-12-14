#include <stdio.h>
#include <string.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		if(a%2==1)
		{
			printf("NO\n");
			continue;
		}
		
		for(int i=1;i<=a/2;i++)
		{
			if(x[i]!=x[a/2+i])
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}