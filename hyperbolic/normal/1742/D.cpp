#include <stdio.h>

int x[200010],check[200010];

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=1000;i++) check[i] = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) check[x[i]] = i;
		
		int ans = -1;
		for(int i=1;i<=1000;i++)
		{
			for(int j=1;j<=1000;j++)
			{
				if(gcd(i,j)==1 && check[i]!=0 && check[j]!=0)
				{
					int val = check[i]+check[j];
					ans = ans>val?ans:val;
				}
			}
		}
		printf("%d\n",ans);
	}
}