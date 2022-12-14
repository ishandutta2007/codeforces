#include <stdio.h>
#include <algorithm>
#include <set>

struct str{
	long long int first;
	long long int second;
	int index;
}P2[200010];
bool cmp(str a, str b)
{
	return a.second<b.second;
}
std::pair<long long int, long long int> P[200010],x[200010];
std::set< std::pair<long long int, long long int> > S;
int ans[200010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		long long int c,d;
		scanf("%lld%lld",&c,&d);
		P[i]=std::make_pair(c,d);
	}
	for(int i=1;i<a;i++) P2[i] = {P[i+1].first-P[i].second,P[i+1].second-P[i].first,i};
	for(int i=1;i<=b;i++)
	{
		long long int c;
		scanf("%lld",&c);
		x[i] = std::make_pair(c,i);
	}
	std::sort(P2+1,P2+a,cmp);
	std::sort(x+1,x+b+1);
	int pivot = 1;
	for(int i=1;i<a;i++)
	{
		while(pivot<=b && x[pivot].first<=P2[i].second) S.insert(x[pivot++]);
		std::set< std::pair<long long int, long long int> > ::iterator it;
		it = S.lower_bound(std::make_pair(P2[i].first,0));
		if(it==S.end())
		{
			printf("No");
			return 0;
		}
		ans[P2[i].index] = (it->second);
		S.erase(it);
	}
	printf("Yes\n");
	for(int i=1;i<a;i++) printf("%d ",ans[i]);
}