#include <stdio.h>
#include <string.h>

char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int s = 0;
		scanf("%s",x+1);
		int a = strlen(x+1);
		if(x[a]=='A'||x[1]=='B')
		{
			printf("NO\n");
			goto u;
		}
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='A') s++;
			else s--;
			if(s<0)
			{
				printf("NO\n");
				goto u;
			}
		}
		if(s<0) printf("NO\n");
		else printf("YES\n");
		u:;
	}
}