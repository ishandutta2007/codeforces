#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > V[300010];
long long int ans = 0;
int x[300010];
long long int func(int k, int prev)
{
	long long int max = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		long long int t = func(V[k][i].first,k);
		ans = ans>max+t-V[k][i].second+x[k]?ans:max+t-V[k][i].second+x[k];
		max = max>t-V[k][i].second?max:t-V[k][i].second;
	}
	ans = ans>max+x[k]?ans:max+x[k];
	return max+x[k];
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		V[b].push_back({c,d});
		V[c].push_back({b,d});
	}
	func(1,0);
	printf("%lld",ans);
}