#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

#define MOD 998244353

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

int count[5010];
int x[5010];
long long int DP[5010][5010];
std::vector<int> V;
std::map<int,int> hash;
int limit[5010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=a;i>=1;i--) limit[x[i]] = (a-i);
	
	for(int i=1;i<=a;i++) count[x[i]]++;
	for(int i=1;i<=a;i++) V.push_back(x[i]);
	V.erase(std::unique(V.begin(),V.end()),V.end());
	for(int i=0;i<V.size();i++) hash[V[i]] = i;
	
	for(int l=1;l<a;l++)
	{
		long long int I = inv(l);
		for(int k=0;k<V.size();k++)
		{
			if(limit[V[k]]<=l)
			{
				DP[l][k] += (count[V[k]]-1);
				DP[l][k] += (DP[l-1][V.size()-1]-DP[l-1][k]+MOD);
				DP[l][k] %= MOD;
				DP[l][k] *= I, DP[l][k]%=MOD;
			}
			else DP[l][k] = 0;
		}
		
		
		if(l==a-1) break;
		for(int k=0;k<V.size();k++)
		{
			DP[l][k] *= count[V[k]];
			DP[l][k] %= MOD;
		}
		for(int k=1;k<V.size();k++)
		{
			DP[l][k] += DP[l][k-1];
			DP[l][k]%=MOD;
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		ans += DP[a-1][hash[x[i]]];
		ans %= MOD;
	}
	ans *= inv(a), ans%=MOD;
	printf("%lld",ans);
}