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
		if(a==1)
		{
			printf("NO\n");
			continue;
		}
		x[a+1] = 0;
		
		int start = 1;
		for(int i=2;i<=a+1;i++)
		{
			if(x[i]!=x[i-1])
			{
				int end = i-1;
				if(end-start+1==1)
				{
					printf("NO\n");
					goto u;
				}
				start = i;
			}
		}
		printf("YES\n");
		u:;
	}
}