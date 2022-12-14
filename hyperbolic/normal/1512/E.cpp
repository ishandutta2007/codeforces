#include <stdio.h>

int ans[510],check[510];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int l = (c-b+1);
		int S = l*(l+1)/2;
		if(d<S)
		{
			printf("-1\n");
			continue;
		}
		if(S+(a-l)*l<d)
		{
			printf("-1\n");
			continue;
		}
		
		for(int i=1;i<=a;i++) ans[i] = check[i] = 0;
		int t = (d-S)/l;
		int t2 = d - S - t*l;
		
		for(int i=b;i<=c;i++) ans[i] = i-(b-1) + t;
		for(int i=c;i>=c-t2+1;i--) ans[i]++;
		for(int i=b;i<=c;i++) check[ans[i]] = 1;
		
		int p = 1;
		for(int i=1;i<=a;i++)
		{
			if(ans[i]==0)
			{
				while(check[p]==1) p++;
				ans[i] = p;
				check[p] = 1;
			}
		}
		
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
		
	}
}