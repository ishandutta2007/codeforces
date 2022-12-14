#include <stdio.h>
#include <queue>
#include <vector>
#define MAX (long long int)2e10

struct str{
	int first;
	int second;
	long long int dist;
};
bool operator<(str a, str b)
{
	return a.dist>b.dist;
}
std::priority_queue<str> Q2;

std::vector< std::pair<int,int> > V[100010];
std::deque< std::pair<long long int, long long int> > V2;
long long int dist[100010],dist2[100010];
int check[100010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		V[d].push_back(std::make_pair(e,f));
		V[e].push_back(std::make_pair(d,f));
	}
	for(int i=1;i<=a;i++) dist[i] = MAX;
	dist[1] = 0;
	
	c++;
	while(c--)
	{
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++) Q2.push({i,i,dist[i]});
		while(!Q2.empty())
		{
			int k = Q2.top().first;
			int target = Q2.top().second;
			long long int d = Q2.top().dist;
			Q2.pop();
			if(check[k]) continue;
			check[k] = 1;
			dist[k] = dist[k]<d?dist[k]:d;
			for(int j=0;j<V[k].size();j++) Q2.push({V[k][j].first,target,d+V[k][j].second});
		}
		
		if(c==0) continue;
		
		V2.clear();
		V2.push_back(std::make_pair(-2*1,dist[1]+1*1));
		for(int i=1;i<=a;i++) dist2[i] = dist[i];
		for(int i=2;i<=a;i++)
		{
			while(V2.size()>=2)
			{
				std::pair<long long int, long long int> P1, P2;
				P1 = V2[0], P2 = V2[1];
				long long int val1 = P1.first * i + P1.second;
				long long int val2 = P2.first * i + P2.second;
				if(val1>=val2) V2.pop_front();
				else break;
			}
			long long int val2 = V2[0].first * i + V2[0].second + (long long int)i*i;
			dist2[i] = dist2[i]<val2?dist2[i]:val2;
			
			std::pair<long long int, long long int> val = std::make_pair(-2*i,dist[i]+(long long int)i*i);
			while(V2.size()>=2)
			{
				std::pair<long long int, long long int> P1, P2;
				P1 = V2[V2.size()-1], P2 = V2[V2.size()-2];
				long long int X1 = -(P1.second-P2.second) * (val.first - P2.first);
				long long int X2 = -(val.second-P2.second) * (P1.first - P2.first); // val.first < P1,P2.first
				if(X1>X2) V2.pop_back();
				else break;
			}
			V2.push_back(val);
		}
		
		V2.clear();
		V2.push_back(std::make_pair(-2*a,dist[a]+(long long int)a*a));
		for(int i=a-1;i>=1;i--)
		{
			while(V2.size()>=2)
			{
				std::pair<long long int, long long int> P1, P2;
				P1 = V2[0], P2 = V2[1];
				long long int val1 = P1.first * i + P1.second;
				long long int val2 = P2.first * i + P2.second;
				if(val1>=val2) V2.pop_front();
				else break;
			}
			long long int val2 = V2[0].first * i + V2[0].second + (long long int)i*i;
			dist2[i] = dist2[i]<val2?dist2[i]:val2;
			
			std::pair<long long int, long long int> val = std::make_pair(-2*i,dist[i]+(long long int)i*i);
			while(V2.size()>=2)
			{
				std::pair<long long int, long long int> P1, P2;
				P1 = V2[V2.size()-1], P2 = V2[V2.size()-2];
				long long int X1 = -(P1.second-P2.second) * (val.first - P2.first);
				long long int X2 = -(val.second-P2.second) * (P1.first - P2.first); // val.first > P1,P2.first
				if(X1<X2) V2.pop_back();
				else break;
			}
			V2.push_back(val);
		}
		
		for(int i=1;i<=a;i++) dist[i] = dist2[i];
	}
	
	for(int i=1;i<=a;i++) printf("%lld ",dist[i]);
}