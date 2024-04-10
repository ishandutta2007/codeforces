#include <stdio.h>
#include <vector>
#include <queue>

#define MAX (long long int)1e18

int x[1000010];
std::vector<long long int> query;
std::priority_queue<int, std::vector<int>, std::greater<int> > Q;

int main()
{
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	long long int sum = 0;
	for(int i=1;i<=a;i++) sum += x[i];
	if(sum==0)
	{
		printf("0");
		return 0;
	}
	
	for(int i=2;i<=1000000;i++)
	{
		if(sum%i==0)
		{
			query.push_back(i);
			while(sum%i==0) sum/=i;
		}
	}
	if(sum>1) query.push_back(sum);
	
	long long int ans = MAX;
	for(int i=0;i<query.size();i++)
	{
		long long int t = query[i];
		
		long long int S = 0, S2 = 0;
		for(int j=1;j<=a;j++)
		{
			S += x[j]%t;
			if(S>=t) S -= t;
			S2 += (S<t-S?S:t-S);
		}
		ans = ans<S2?ans:S2;
	}
	if(ans==MAX) printf("-1");
	else printf("%lld",ans);
}