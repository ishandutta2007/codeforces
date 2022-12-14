#include <stdio.h>
#include <vector>

std::pair<long long int, long long int> P[100010];
int check[100010],a;
std::vector<int> V;
int func(int s, int t)
{
	for(int i=1;i<=a;i++) check[i] = 0;
	V.clear();
	
	std::pair<long long int,long long int> P1 = std::make_pair(P[t].first-P[s].first,P[t].second-P[s].second);
	for(int i=1;i<=a;i++)
	{
		std::pair<long long int,long long int> S = std::make_pair(P[i].first-P[s].first,P[i].second-P[s].second);
		if(P1.first*S.second==P1.second*S.first) check[i] = 1;
	}
	for(int i=1;i<=a;i++) if(check[i]==0) V.push_back(i);
	if(V.size()<=1) return 1;
	
	std::pair<long long int,long long int> P2 = std::make_pair(P[V[1]].first-P[V[0]].first,P[V[1]].second-P[V[0]].second);
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			std::pair<long long int,long long int> S = std::make_pair(P[i].first-P[V[0]].first,P[i].second-P[V[0]].second);
			if(P2.first*S.second!=P2.second*S.first) return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d",&a);
	if(a<=2)
	{
		printf("YES");
		return 0;
	}
	for(int i=1;i<=a;i++) scanf("%lld%lld",&P[i].first,&P[i].second);
	
	if(func(1,2))
	{
		printf("YES");
		return 0;
	}
	if(func(2,3))
	{
		printf("YES");
		return 0;
	}
	if(func(1,3))
	{
		printf("YES");
		return 0;
	}
	printf("NO");
}