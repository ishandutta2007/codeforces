#include <stdio.h>

int check[150010],x[150010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int ans = -1;
		for(int i=a;i>=1;i--)
		{
			if(check[x[i]]>0)
			{
				int t = (i-1) + (a-check[x[i]]) + 1;
				ans = ans>t?ans:t;
			}
			check[x[i]] = i;
		}
		printf("%d\n",ans);
		
		for(int i=1;i<=a;i++) check[x[i]] = 0;
	}
}