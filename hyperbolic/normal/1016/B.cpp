#include <stdio.h>

char x[1010],y[1010];
int ans[1010],sum[1010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	scanf("%s%s",x+1,y+1);
	for(int i=1;i<=a-b+1;i++)
	{
		for(int j=1;j<=b;j++) if(x[i+j-1]!=y[j]) goto u;
		ans[i] = 1;
		u:;
	}
	for(int i=1;i<=a-b+1;i++) sum[i] = sum[i-1]+ans[i];
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		e -= (b-1);
		if(e<d) printf("0\n");
		else printf("%d\n",sum[e]-sum[d-1]);
	}
}