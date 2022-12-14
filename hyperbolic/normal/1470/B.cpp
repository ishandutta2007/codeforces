#include <stdio.h>

int count[1000010];
int check[1000010];
int x[300010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int j=1;j<=a;j++) for(int i=1000;i>=1;i--) if(x[j]%(i*i)==0) x[j]/=(i*i);
		
		int sum = 0;
		int max0 = 0, max1 = 0;
		for(int i=1;i<=a;i++) count[x[i]]++;
		for(int i=1;i<=a;i++)
		{
			max0 = max0>count[x[i]]?max0:count[x[i]];
			if(x[i]==1)
			{
				if(check[x[i]]==0)
				{
					check[x[i]] = 1;
					sum += count[x[i]];
				}
			}
			else if(count[x[i]]%2==1) max1 = max1>count[x[i]]?max1:count[x[i]];
			else if(check[x[i]]==0)
			{
				check[x[i]] = 1;
				sum += count[x[i]];
			}
		}
		max1 = max1>sum?max1:sum;
		int b;
		scanf("%d",&b);
		for(int i=1;i<=b;i++)
		{
			long long int c;
			scanf("%lld",&c);
			if(c==0) printf("%d\n",max0);
			else printf("%d\n",max1);
		}
		
		for(int i=1;i<=a;i++) count[x[i]]--;
		for(int i=1;i<=a;i++) check[x[i]] = 0;
	}
}