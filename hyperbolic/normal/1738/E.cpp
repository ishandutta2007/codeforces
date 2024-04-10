#include <stdio.h>
#include <vector>
#include <map>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[100010];
long long int comb(int s, int t)
{
	if(s<t) return 0;
	long long int ans = fact[s];
	ans *= inv(fact[t]), ans %= MOD;
	ans *= inv(fact[s-t]), ans %= MOD;
	return ans;
}


int x[100010],y[100010];
std::map<long long int, std::pair<int,int> > M;

struct str{
	long long int first;
	int second;
	int index;
};
std::vector<str> V1,V2;

int main()
{
	fact[0] = 1;
	for(int i=1;i<=100000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		V1.clear();
		V2.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[i] = 0;
		for(int i=1;i<=a;i++) if(x[i]==0) y[i] = 1;
		for(int i=1;i<=a;i++) y[i] += y[i-1];
		
		if(y[a]-y[0]==a)
		{
			printf("%lld\n",power(2,a-1));
			continue;
		}
		
		x[0] = x[a+1] = 1;
		V1.push_back({1,1,0});
		for(int i=1;i<=a+1;i++)
		{
			if(x[i]==0) V1[V1.size()-1].second++;
			else
			{
				V1.push_back({V1.back().first+x[i],1,i});
			}
		}
		V2.push_back({1,1,a+1});
		for(int i=a;i>=0;i--)
		{
			if(x[i]==0) V2[V2.size()-1].second++;
			else
			{
				V2.push_back({V2.back().first+x[i],1,i});
			}
		}
		
		for(int i=0;i<V2.size();i++) M[V2[i].first] = std::make_pair(V2[i].second,V2[i].index);
		
		long long int ans = 1;
		for(int i=0;i<V1.size();i++)
		{
			if(M.find(V1[i].first)!=M.end())
			{
				std::pair<int,int> P1 = std::make_pair(V1[i].second,V1[i].index);
				std::pair<int,int> P2 = M[V1[i].first];
				if(P2.second<=P1.second) break;
				
				if(P1.second<P2.second && y[P2.second-1]-y[P1.second]==(P2.second-1-P1.second))
				{
					ans *= (power(2,P2.second-P1.second));
					ans %= MOD;
					break;
				}
				
				//printf("%d %d %d %d!!\n",P1.first,P2.first,P1.second,P2.second);
				long long int val = 0;
				if(P1.second==V1[0].index||P2.second==V2[0].index)
				{
					for(int k=0;k<=P1.first;k++)
					{
						val += comb(P1.first-1,k) * comb(P2.first-1,k);
						val %= MOD;
					}
				}
				else
				{
					for(int k=0;k<=P1.first;k++)
					{
						val += comb(P1.first,k) * comb(P2.first,k);
						val %= MOD;
					}
				}
				ans *= val, ans %= MOD;
				ans %= MOD;
			}
		}
		printf("%lld\n",ans);
	}
}