#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		ll k,k2;
		cin>>n>>k;
		k2=k*k;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		ll ans=0;
		map<ll,ll> dp[2],np[2];
		if(k==1)
		{
			FOR(i,0,n)
			{
				if(a[i]>0)
				dp[0][a[i]]++;
				else
				np[0][a[i]*-1]++;
			}
			sort(a,a+n);
			ll p=-1*mod;
			FOR(i,0,n)
			{
				if(a[i]!=p)
				{
					p=a[i];
					if(a[i]>0)
					{
						ll o=dp[0][a[i]];
						ans+=(o*(o-1)*(o-2))/6;
					}
					else
					{
						ll o=np[0][a[i]*-1];
						ans+=(o*(o-1)*(o-2))/6;
					}
				}
			}
		}
		else
		FOR(i,0,n)
		{
			if(a[i]>0)
			{
				dp[0][a[i]]++;
				if((a[i]%k)==0)
				{
					dp[1][a[i]]+=dp[0][a[i]/k];
					if((a[i]%k2)==0)
					{
						ans+=dp[1][a[i]/k];
					}
				}
			}
			else if(a[i]<0)
			{
				a[i]*=(-1);
				np[0][a[i]]++;
				if((a[i]%k)==0)
				{
					np[1][a[i]]+=np[0][a[i]/k];
					if((a[i]%k2)==0)
					{
						ans+=np[1][a[i]/k];
					}
				}
			}
			else
			dp[0][0]++;
		}
		ll o=dp[0][0];
		ans+=(o*(o-1)*(o-2))/6;
		cout<<ans;
	}
	return 0;
}