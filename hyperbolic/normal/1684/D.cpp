#include <stdio.h>
#include <algorithm>
#include <vector>

int x[200010];
std::pair<int,int> P[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		long long int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		long long int ans = sum;
		
		for(int i=1;i<=a;i++) x[i] += i;
		for(int i=1;i<=a;i++) P[i] = std::make_pair(x[i],i);
		std::sort(P+1,P+a+1);
		
		for(int i=a;i>=a-b+1;i--)
		{
			int t = P[i].second;
			sum -= (x[t] - i);
			ans = ans<sum?ans:sum;
		}
		printf("%lld\n",ans);
	}
}