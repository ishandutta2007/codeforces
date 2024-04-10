#include <stdio.h>
#include <map>
#include <vector>
#define MOD 1000000007

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int ans = 0;
std::vector<int> V[100010];
long long int x[100010];
void func(int k, int prev, std::map<long long int, int> &M)
{
	std::map<long long int,int> M2;
	std::map<long long int,int> ::iterator it;
	for(it=M.begin();it!=M.end();it++) M2[gcd(it->first,x[k])] += (it->second);
	M2[x[k]]++;
	
	for(it=M2.begin();it!=M2.end();it++)
	{
		ans += (it->first)*(it->second);
		ans %= MOD;
	}
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,M2);
	}
}

std::map<long long int,int> M;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	func(1,0,M);
	
	printf("%lld",ans);
}