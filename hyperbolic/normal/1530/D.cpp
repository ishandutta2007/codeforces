#include <stdio.h>

int x[200010],ans[200010],check[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a+1;i++) ans[i] = check[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++)
		{
			if(check[x[i]]==0)
			{
				ans[i] = x[i];
				check[x[i]] = 1;
			}
		}
		
		int p = 1;
		while(check[p]==1) p++;
		int control = 1;
		
		for(int i=1;i<=a;i++)
		{
			if(ans[i]==0)
			{
				if(control==1&&p<=i)
				{
					p = i+1;
					while(check[p]==1) p++;
					if(p==a+1)
					{
						control = 0;
						p = 1;
						while(check[p]==1) p++;
					}
				}
				ans[i] = p;
				check[p++] = 1;
				while(check[p]==1) p++;
				if(p==a+1)
				{
					control = 0;
					p = 1;
					while(check[p]==1) p++;
				}
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(ans[i]==i)
			{
				for(int j=1;j<=a;j++)
				{
					if(j==i) continue;
					if(j != ans[i] && ans[j] == x[i])
					{
						int temp = ans[i];
						ans[i] = ans[j];
						ans[j] = temp;
						goto u;
					}
				}
				
				for(int j=1;j<=a;j++)
				{
					if(j==i) continue;
					if(j != ans[i])
					{
						int temp = ans[i];
						ans[i] = ans[j];
						ans[j] = temp;
						goto u;
					}
				}
			}
		}
		u:;
		
		int count = 0;
		for(int i=1;i<=a;i++) if(ans[i]==x[i]) count++;
		printf("%d\n",count);
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}