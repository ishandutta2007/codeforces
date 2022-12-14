#include <stdio.h>
#include <vector>
long long int MAX = 1;
std::pair<long long int,long long int> P[100010];
int main()
{
	for(int i=1;i<=15;i++) MAX*=10;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			long long int b,c;
			scanf("%lld%lld",&b,&c);
			P[i] = std::make_pair(b,c);
		}
		
		P[0].first = 0;
		P[a+1].first = MAX;
		int ans = 0;
		long long int p = 0, target = P[1].second;
		for(int i=2;i<=a+1;i++)
		{
			long long int q;
			if(p<target)
			{
				if(p+P[i].first-P[i-1].first<target) q = p+P[i].first-P[i-1].first;
				else q = target;
			}
			else
			{
				if(p-P[i].first+P[i-1].first>target) q = p-P[i].first+P[i-1].first;
				else q = target;
			}
			
			if(p<= P[i-1].second && P[i-1].second <= q) ans++;
			else if(q<=P[i-1].second && P[i-1].second<=p) ans++;
			p = q;
			if(p==target) target = P[i].second;
		}
		printf("%d\n",ans);
	}
}