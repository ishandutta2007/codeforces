#include <stdio.h>

int x[500010],check[500010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++)
		{
			if(check[x[i]]==1)
			{
				printf("YES\n");
				goto u;
			}
			check[x[i]]++;
		}
		
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				int p = i;
				check[i] = 1;
				while(x[p]!=i)
				{
					ans++;
					p = x[p];
					check[p] = 1;
				}
			}
		}
		if(ans%2==0) printf("YES\n");
		else printf("NO\n");
		u:;
	}
}