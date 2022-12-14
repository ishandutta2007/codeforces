#include <stdio.h>

int x[110],ans[110],check[110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	for(int i=1;i<b;i++)
	{
		int C = x[i+1]-x[i];
		if(C<=0) C+=a;
		if(ans[x[i]]!=0 && ans[x[i]]!=C)
		{
			printf("-1");
			return 0;
		}
		ans[x[i]] = C;
	}
	
	for(int i=1;i<=a;i++)
	{
		if(ans[i]==0) continue;
		for(int j=i+1;j<=a;j++)
		{
			if(ans[i]==ans[j])
			{
				printf("-1");
				return 0;
			}
		}
	}
	for(int i=1;i<=a;i++) check[ans[i]] = 1;
	int C = 1;
	for(int i=1;i<=a;i++)
	{
		if(ans[i]==0)
		{
			while(check[C]==1) C++;
			ans[i] = C;
			check[C] = 1;
		}
	}
	
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}