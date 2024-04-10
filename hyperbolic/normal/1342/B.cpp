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
		for(int i=2;i<=a;i++) if(x[i]!=x[1]) goto u;
		
		printf("%s\n",x+1);
		continue;
		u:;
		
		for(int i=1;i<=a;i++) printf("01");
		printf("\n");
	}
}