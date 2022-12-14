#include <stdio.h>
#include <string.h>
#include <algorithm>

char x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		std::sort(x+1,x+a+1);
		for(int i=1;i<=a;i++)
		{
			if(x[i]!=x[1])
			{
				for(int j=1;j<=a;j++) printf("%c",x[j]);
				printf("\n");
				goto u;
			}
		}
		printf("-1\n");
		u:;
	}
}