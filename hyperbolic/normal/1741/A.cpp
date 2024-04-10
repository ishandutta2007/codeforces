#include <stdio.h>
#include <string.h>

char x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",x+1,y+1);
		int a = strlen(x+1), b = strlen(y+1);
		
		int s = a, t = b;
		if(x[a]=='S') s*=-1;
		if(x[a]=='M') s*=0;
		if(y[b]=='S') t*=-1;
		if(y[b]=='M') t*=0;
		if(s<t) printf("<");
		else if(s>t) printf(">");
		else printf("=");
		printf("\n");
	}
}