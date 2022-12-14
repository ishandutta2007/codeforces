#include <stdio.h>

char x[2010];
int y[2010][2010],count[2010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		for(int j=1;j<=b;j++) y[i][j] = x[j]-'0';
	}
	
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) count[j] += y[i][j];
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++) if((count[j]-y[i][j])==0) goto u;
		
		printf("YES");
		return 0;
		u:;
	}
	printf("NO");
}