#include <stdio.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='U') printf("D");
			else if(x[i]=='D') printf("U");
			else printf("%c",x[i]);
		}
		printf("\n");
	}
}