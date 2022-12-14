#include <stdio.h>
#include <string.h>

char x[10010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) printf("%c",x[i]);
		for(int i=a;i>=1;i--) printf("%c",x[i]);
		printf("\n");
	}
}