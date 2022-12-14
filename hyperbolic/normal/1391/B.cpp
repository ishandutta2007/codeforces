#include <stdio.h>

char x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		int count = 0;
		for(int i=1;i<a;i++) if(x[i][b]=='R') count++;
		for(int j=1;j<b;j++) if(x[a][j]=='D') count++;
		printf("%d\n",count);
	}
}