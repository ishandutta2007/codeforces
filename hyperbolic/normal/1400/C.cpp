#include <stdio.h>
#include <string.h>

char x[100010],y[100010],z[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		int b;
		scanf("%d",&b);
		
		for(int i=1;i<=a;i++) y[i]='1';
		for(int i=1;i<=a;i++) z[i]='0';
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='0')
			{
				if(i-b>=1) y[i-b] = '0';
				if(i+b<=a) y[i+b] = '0';
			}
		}
		for(int i=1;i<=a-b;i++) if(y[i]=='1') z[i+b] = '1';
		for(int i=b+1;i<=a;i++) if(y[i]=='1') z[i-b] = '1';
		for(int i=1;i<=a;i++)
		{
			if(x[i]!=z[i])
			{
				printf("-1\n");
				goto u;
			}
		}
		
		for(int i=1;i<=a;i++) printf("%c",y[i]);
		printf("\n");
		
		u:;
	}
}