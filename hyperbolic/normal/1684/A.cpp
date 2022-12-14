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
		if(a==1) printf("%c",x[1]);
		else if(a==2) printf("%c",x[2]);
		else
		{
			char min = x[1];
			for(int i=1;i<=a;i++) min = min<x[i]?min:x[i];
			printf("%c",min);
		}
		printf("\n");
	}
}