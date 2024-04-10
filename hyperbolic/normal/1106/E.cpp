#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>

int a,b;
long long int MAX = 1;
long long int check[100010][210];
std::pair<int,int> next[100010];

long long int func(int s, int t)
{
	if(t>b) return MAX;
	if(s>a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	long long int s1 = func(next[s].first,t)+next[s].second;
	long long int s2 = func(s+1,t+1);
	return check[s][t] = s1<s2?s1:s2;
}

std::vector< std::pair<int,int> > V1[100010],V2[100010];
std::multiset< std::pair<int,int> > S;

int main()
{
	for(int i=1;i<=16;i++) MAX*=10;
	
	int c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) for(int j=0;j<=b;j++) check[i][j] = -1;
	
	for(int i=1;i<=c;i++)
	{
		int d,e,f,g;
		scanf("%d%d%d%d",&d,&e,&f,&g);
		V1[d].push_back(std::make_pair(g,f));
		V2[e+1].push_back(std::make_pair(g,f));
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V1[i].size();j++) S.insert(V1[i][j]);
		for(int j=0;j<V2[i].size();j++)
		{
			std::multiset< std::pair<int,int> > ::iterator it = S.find(V2[i][j]);
			S.erase(it);
		}
		if(S.empty()) next[i] = std::make_pair(i+1,0);
		else
		{
			std::multiset< std::pair<int,int> > ::iterator it = S.end();
			it--;
			next[i] = std::make_pair(it->second+1,it->first);
		}
	}
	
	printf("%lld",func(1,0));
}