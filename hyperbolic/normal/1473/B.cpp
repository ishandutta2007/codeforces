#include <stdio.h>
#include <string.h>

char x[1010],y[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",x,y);
		int a = strlen(x);
		int b = strlen(y);
		for(int i=a;i<20*a;i++) x[i] = x[i%a];
		for(int i=b;i<20*b;i++) y[i] = y[i%b];
		for(int i=1;i<=400;i++)
		{
			if(i%a==0 && i%b==0)
			{
				for(int j=0;j<i;j++) if(x[j]!=y[j]) goto u;
				for(int j=0;j<i;j++) printf("%c",x[j]);
				printf("\n");
				goto v;
				
				u:;
			}
		}
		printf("-1\n");
		v:;
	}
}