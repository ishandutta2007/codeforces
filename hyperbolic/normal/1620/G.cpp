#include <stdio.h>
#include <string.h>
#include <vector>

#define MOD 998244353

int a;
std::vector< std::pair<char,int> > V[110];
long long int DP[9000010];
void func(int k, std::vector< std::pair<char,int> > &W, int bit)
{
	if(k>a)
	{
		long long int t = 1;
		for(int i=0;i<W.size();i++) t *= (W[i].second+1), t %= MOD;
		DP[bit] = t;
		return;
	}
	
	func(k+1,W,bit);
	
	std::vector< std::pair<char,int> > W2;
	int p = 0;
	for(int i=0;i<W.size();i++)
	{
		while(p<V[k].size() && V[k][p].first < W[i].first) p++;
		if(p==V[k].size()) break;
		if(V[k][p].first==W[i].first)
		{
			int t = W[i].second < V[k][p].second? W[i].second : V[k][p].second;
			W2.push_back(std::make_pair(W[i].first,t));
		}
	}
	func(k+1,W2,bit+(1<<(k-1)));
}

char x[20010];
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		x[b+1] = 0;
		int start = 1;
		int count = 1;
		for(int j=2;j<=b+1;j++)
		{
			if(x[j]!=x[start])
			{
				V[i].push_back(std::make_pair(x[start],count));
				start = j;
				count = 1;
			}
			else count++;
		}
	}
	
	for(int i=1;i<=a;i++) func(i+1,V[i],1<<(i-1));
	
	int b = (1<<a);
	
	for(int i=0;i<b;i++)
	{
		int b2 = i;
		int count = 0;
		while(b2) count += b2%2, b2/=2;
		if(count%2==1) DP[i] = (MOD-DP[i]), DP[i] %= MOD;
	}
	
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			if((j&(1<<i)) != 0)
			{
				DP[j] += DP[j ^ (1<<i)];
				DP[j] %= MOD;
			}
		}
	}
	
	for(int i=0;i<b;i++)
	{
		DP[i] = (MOD-DP[i]), DP[i] %= MOD;
	}
	
	long long int ans = 0;
	for(int i=0;i<b;i++)
	{
		int sum = 0;
		int count = 0;
		for(int j=0;j<a;j++)
		{
			if(((i>>j)&1)!=0)
			{
				count++;
				sum += (j+1);
			}
		}
		long long int val = DP[i];
		DP[i] *= sum;
		DP[i] *= count;
		ans ^= DP[i];
	}
	printf("%lld",ans);
}