#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD (int)1e9+7

std::pair<int,int> x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			x[i] = std::make_pair(b,i);
		}
		std::sort(x+1,x+a+1);
		
		long long int ans = 1;
		int L = x[1].second, R = x[1].second;
		for(int i=2;i<=a;i++)
		{
			if(L>x[i].second) L = x[i].second;
			else if(R<x[i].second) R = x[i].second;
			else
			{
				ans *= (R-L+1)-(i-1);
				ans %= MOD;
			}
		}
		printf("%lld\n",ans);
	}
}