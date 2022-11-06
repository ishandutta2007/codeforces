#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
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
		ll x,y;
		cin>>x>>y;
		if(y%x!=0)
		{
			cout<<0;
			return 0;
		}
		ll q=y/x;
		vector<int> div;
		for(ll i=1;((i*i)<=q);i++)
		{
			if(q%i==0)
			{
				div.pb(i);
				if((i*i)!=q)
				div.pb(q/i);
			}
		}
		sort(div.begin(),div.end());
		int n=div.size();
		int ans[n];
		FORD(i,n,0)
		{
			ans[i]=po(2,(q/div[i]-1));
			FORD(j,n,i+1)
			{
				if(div[j]%div[i]==0)
				ans[i]=(ans[i]-ans[j]+mod)%mod;
			}
		}
		cout<<ans[0];
	}
	return 0;
}