#include <stdio.h>
#include <queue>
int dist[1010][1010];
int check[1010],temp[1010];
struct str{
	int first;
	int second;
};
bool operator<(str a, str b)
{
	return a.second>b.second;
}
std::priority_queue<str> Q;
std::vector< std::pair<int,int> > V[1010];

int a;
void func(int k)
{
	for(int i=1;i<=a;i++) check[i] = 0;
	for(int i=1;i<=a;i++) temp[i] = 123456789;
	Q.push({k,1});
	while(!Q.empty())
	{
		int k = Q.top().first;
		int t = Q.top().second;
		Q.pop();
		if(check[k]) continue;
		temp[k] = t;
		check[k] = 1;
		
		for(int i=0;i<V[k].size();i++)
		{
			if(temp[V[k][i].first]>temp[k]+V[k][i].second)
			{
				Q.push({V[k][i].first,temp[k]+V[k][i].second});
			}
		}
	}
	for(int i=1;i<=a;i++) dist[k][i] = temp[i]-1;
	
}

int min(int a, int b, int c)
{
	int m = a;
	m = m<b?m:b;
	m = m<c?m:c;
	return m;
}

std::pair<int,int> edge[1010],P[1010];

int main()
{
	int b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		V[d].push_back(std::make_pair(e,f));
		V[e].push_back(std::make_pair(d,f));
		edge[i] = std::make_pair(d,e);
	}
	for(int i=1;i<=a;i++) func(i);
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		P[i]=std::make_pair(d,e);
	}
	long long int ans = 1;
	for(int i=1;i<=16;i++) ans*=10;
	
	for(int i=1;i<=b;i++)
	{
		int s = edge[i].first;
		int t = edge[i].second;
		long long int sum = 0;
		for(int i=1;i<=c;i++)
		{
			int d = min(dist[P[i].first][P[i].second],dist[P[i].first][s]+dist[t][P[i].second],dist[P[i].first][t]+dist[s][P[i].second]);
			sum += d;
		}
		ans = ans<sum?ans:sum;
	}
	printf("%lld",ans);
}