#include <stdio.h>

int x[100010],min[100010],max[100010],ans[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=b;i++) ans[i] = i;
	
	int limit = a;
	for(int i=b;i>=1;i--)
	{
		if(ans[i]+x[i]-1<limit) ans[i] = limit-x[i]+1, limit = ans[i]-1;
		else break;
	}
	if(ans[1]!=1)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=b;i++)
	{
		if(ans[i]+x[i]-1>a)
		{
			printf("-1");
			return 0;
		}
	}
	for(int i=1;i<=b;i++) printf("%d ",ans[i]);
}