#include <stdio.h>

int x[100010],last[100010],check[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) last[x[i]] = i;
		for(int i=1;i<=a;i++) check[i] = 0;
		
		int limit = -1;
		for(int i=a-1;i>=1;i--)
		{
			if(x[i]>x[i+1])
			{
				limit = i;
				break;
			}
		}
		if(limit==-1)
		{
			printf("0\n");
			continue;
		}
		
		for(int i=1;i<=limit;i++)
		{
			if(check[x[i]]) continue;
			check[x[i]] = 1;
			limit = limit>last[x[i]]?limit:last[x[i]];
		}
		int ans = 0;
		for(int i=1;i<=a;i++) ans += check[i];
		printf("%d\n",ans);
	}
}