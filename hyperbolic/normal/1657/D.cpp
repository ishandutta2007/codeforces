#include <stdio.h>
#include <vector>
#include <algorithm>

long long int x[1000010];
std::vector<long long int> V[1000010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back((long long int)d*e);
	}
	
	for(int i=1;i<=b;i++)
	{
		if(V[i].size()>0)
		{
			std::sort(V[i].begin(),V[i].end());
			long long int t = V[i].back();
			for(int j=i;j<=b;j+=i) x[j] = x[j]>t*(j/i)-1?x[j]:t*(j/i)-1;
		}
	}
	
	for(int i=1;i<=b;i++) x[i] = x[i]>x[i-1]?x[i]:x[i-1];
	
	int c;
	scanf("%d",&c);
	while(c--)
	{
		long long int d,e;
		scanf("%lld%lld",&d,&e);
		long long int t = d*e;
		int min = 1, max = b;
		int ans = b+1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h]>=t)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		if(ans>b) printf("-1 ");
		else printf("%d ",ans);
	}
}