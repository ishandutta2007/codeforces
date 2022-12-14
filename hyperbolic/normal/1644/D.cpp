#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
#define MOD 998244353


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

std::pair<int,int> query[200010];
std::map<int,int> M1,M2;
std::vector<int> index;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M1.clear();
		M2.clear();
		index.clear();
		
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int i=1;i<=d;i++)
		{
			int e,f;
			scanf("%d%d",&e,&f);
			query[i] = std::make_pair(e,f);
		}
		for(int i=d;i>=1;i--)
		{
			if(M1.size()==a || M2.size()==b) break;
			int e = query[i].first, f = query[i].second;
			if(M1.find(e)==M1.end()) M1[e] = i;
			if(M2.find(f)==M2.end()) M2[f] = i;
		}
		
		std::map<int,int> ::iterator it;
		for(it = M1.begin();it!=M1.end();it++) index.push_back(it->second);
		for(it = M2.begin();it!=M2.end();it++) index.push_back(it->second);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		
		printf("%lld\n",power(c,index.size()));
	}
}