#include <stdio.h>
#include <queue>
#include <vector>
#define MOD 1000000007
#define MAX 12345678

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

int dist[3][200010];
long long int count[3][200010];
int a,b;
std::queue<int> Q;
std::vector<int> V[200010];
void func(int s,int t)
{
	for(int i=1;i<=a;i++) dist[t][i] = MAX;
	for(int i=1;i<=a;i++) count[t][i] = 0;
	dist[t][s] = 0;
	count[t][s] = 1;
	Q.push(s);
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		for(int i=0;i<V[k].size();i++)
		{
			if(dist[t][V[k][i]] > dist[t][k]+1)
			{
				dist[t][V[k][i]] = dist[t][k]+1;
				count[t][V[k][i]] = count[t][k];
				Q.push(V[k][i]);
			}
			else if(dist[t][V[k][i]] == dist[t][k]+1)
			{
				count[t][V[k][i]] += count[t][k], count[t][V[k][i]]%=MOD;
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int s,t;
		scanf("%d%d%d%d",&a,&b,&s,&t);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			V[d].push_back(c);
		}
		
		func(s,1);
		func(t,2);
		
		int d = dist[1][t];
		long long int ans = count[1][t];
		
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<V[i].size();j++)
			{
				int t = V[i][j];
				long long int val;
				
				if(dist[1][i] + dist[2][t] == d && dist[1][i]+dist[2][i]==d)
				{
					val = count[1][i] * count[2][t], val %= MOD;
					ans += val, ans %= MOD;
				}
			}
		}
		
		printf("%lld\n",ans);
	}
}