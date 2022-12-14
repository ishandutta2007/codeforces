#include <stdio.h>
#include <string.h>

char x[10010],y[10010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		e %= (d-c+1);
		for(int j=c;j<=d;j++)
		{
			if(j-e<c) y[j] = x[j-e + (d-c+1)];
			else y[j] = x[j-e];
		}
		for(int j=c;j<=d;j++) x[j] = y[j];
	}
	
	for(int i=1;i<=a;i++) printf("%c",x[i]);
}