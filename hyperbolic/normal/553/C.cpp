#include <stdio.h>
#include <vector>
#define MOD 1000000007

long long int power(long long int s, int t)
{
	long long int ans = 1;
	for(int i=1;i<=t;i++) ans*=s, ans%=MOD;
	return ans;
}

int dist[100010];
std::vector< std::pair<int,int> > V[100010];
void func(int s, int t)
{
	if(dist[s]>0) return;
	dist[s] = t;
	for(int i=0;i<V[s].size();i++) func(V[s][i].first,V[s][i].second+t);
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back(std::make_pair(d,1-e));
		V[d].push_back(std::make_pair(c,1-e));
	}
	
	int C = 0;
	for(int i=1;i<=a;i++)
	{
		if(dist[i]==0)
		{
			func(i,1);
			C++;
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			if((dist[i] + dist[V[i][j].first] + V[i][j].second)%2==1)
			{
				printf("0");
				return 0;
			}
		}
	}
	
	printf("%lld",power(2,C-1));
}