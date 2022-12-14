#include <stdio.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		if(x[1]+x[2]+x[3]==x[4]+x[5]+x[6]) printf("YES\n");
		else printf("NO\n");
	}
}