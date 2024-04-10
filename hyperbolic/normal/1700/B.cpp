#include <stdio.h>

char x[100010];
int y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		if(x[1]!='9')
		{
			for(int i=1;i<=a;i++) printf("%c",'9'-(x[i]-'0'));
			printf("\n");
			continue;
		}
		
		for(int i=1;i<=a;i++) x[i] -= '0';
		for(int i=1;i<a;i++) y[i] = 1;
		y[a] = 1;
		for(int i=1;i<=a;i++) y[i] -= x[i];
		for(int i=a;i>=1;i--) if(y[i]<0) y[i]+=10, y[i-1]--;
		
		for(int i=1;i<=a;i++) printf("%d",y[i]);
		printf("\n");
	}
}