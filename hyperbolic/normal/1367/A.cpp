#include <stdio.h>
#include <string.h>
char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i+=2) printf("%c",x[i]);
		printf("%c\n",x[a]);
	}
}