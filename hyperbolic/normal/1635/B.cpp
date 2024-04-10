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
		for(int i=1;i<=a+3;i++) check[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int ans = 0;
		for(int i=2;i<a;i++) if(x[i]>x[i-1] && x[i]>x[i+1]) check[i] = 1;
		
		for(int i=2;i<=a;i++)
		{
			if(check[i]==1)
			{
				if(check[i+2]==1)
				{
					ans++;
					x[i+1] = (x[i]>x[i+2]?x[i]:x[i+2]);
					check[i] = check[i+2] = 0;
				}
			}
		}
		
		for(int i=2;i<a;i++)
		{
			if(check[i]==1)
			{
				ans++;
				x[i] = (x[i-1]>x[i+1]?x[i-1]:x[i+1]);
			}
		}
		
		printf("%d\n",ans);
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		printf("\n");
	}
}