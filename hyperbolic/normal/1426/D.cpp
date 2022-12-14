#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 12345678
bool cmp(std::pair<int,int> a, std::pair<int,int> b)
{
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}
std::vector< std::pair<int,int> > V;
long long int x[200010];
std::map<long long int,int> check;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) x[i] += x[i-1];
	for(int i=0;i<=a;i++)
	{
		if(check[x[i]]>0) V.push_back(std::make_pair(check[x[i]],i));
		check[x[i]] = i+1;
	}
	std::sort(V.begin(),V.end(),cmp);
	
	int ans = 0;
	int min = MAX;
	for(int i=0;i<V.size();i++)
	{
		if(V[i].first>=min)
		{
			ans++;
			min = MAX;
		}
		min = min<V[i].second?min:V[i].second;
	}
	if(min!=MAX) ans++;
	printf("%d",ans);
}