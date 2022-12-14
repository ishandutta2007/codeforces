#include <stdio.h>

char x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		y[1] = '1';
		for(int i=2;i<=a;i++)
		{
			if(x[i-1]+y[i-1]==x[i]+'1') y[i] = '0';
			else y[i] = '1';
		}
		for(int i=1;i<=a;i++) printf("%c",y[i]);
		printf("\n");
	}
}