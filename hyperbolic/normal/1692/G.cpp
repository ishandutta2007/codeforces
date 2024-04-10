#include <stdio.h>

int x[200010],check[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<a;i++) if(x[i]>=2*x[i+1]) check[i] = 1;
		for(int i=1;i<a;i++) check[i] += check[i-1];
		
		int ans = 0;
		for(int i=1;i<=a-b;i++)
		{
			if(check[i+b-1] - check[i-1]==0)
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}