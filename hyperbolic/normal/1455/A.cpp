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
		printf("%d\n",strlen(x+1));
	}
}