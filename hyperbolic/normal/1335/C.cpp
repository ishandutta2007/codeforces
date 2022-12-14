#include <stdio.h>

int x[200010],check[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++) check[x[i]]++;
		
		int s = 0;
		for(int i=1;i<=a;i++) if(check[i]>0) s++;
		
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(check[i]>0)
			{
				int s1 = s<check[i]-1?s:check[i]-1;
				int s2 = s-1<check[i]?s-1:check[i];
				ans = ans>s1?ans:s1;
				ans = ans>s2?ans:s2;
			}
		}
		printf("%d\n",ans);
	}
}