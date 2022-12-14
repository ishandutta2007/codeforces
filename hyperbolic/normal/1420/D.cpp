#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#define MOD 998244353

std::vector<int> index;
std::map<int,int> hash;
std::priority_queue<int, std::vector<int>, std::greater<int> > Q;

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int s = a;
	while(b)
	{
		if(b%2==1) ans*=s, ans%=MOD;
		b/=2;
		s*=s, s%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[300010];
long long int comb(int s, int t)
{
	if(s<t) return 0;
	long long int ans = fact[s];
	ans *= inv(fact[t]), ans%=MOD;
	ans *= inv(fact[s-t]), ans%=MOD;
	return ans;
}

int x[300010],y[300010];
std::vector<int> V[600010];

int main()
{
	fact[0] = 1;
	for(int i=1;i<=300000;i++) fact[i] = fact[i-1]*i, fact[i]%=MOD;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=a;i++)
	{
		index.push_back(x[i]);
		index.push_back(y[i]);
	}
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	
	for(int i=1;i<=a;i++) V[hash[x[i]]].push_back(hash[y[i]]);
	
	long long int ans = 0;
	for(int i=1;i<=index.size();i++)
	{
		while(!Q.empty())
		{
			int k = Q.top();
			if(k<i) Q.pop();
			else break;
		}
		int s = V[i].size();
		int t = Q.size();
		ans += (comb(s+t,b) - comb(t,b)+MOD)%MOD;
		ans %= MOD;
		for(int j=0;j<V[i].size();j++) Q.push(V[i][j]);
	}
	
	printf("%lld",ans);
}