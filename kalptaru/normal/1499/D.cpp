#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
const ll mod=985661441;
ll INF=1e18;
ll po(ll a,ll b){
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
ll cnt[20000005];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif	
	ll test=1;
	cin>>test;
	// spre
	cnt[0]=1;
	cnt[1]=1;
	FOR(i,2,20000005)
	{
		if(cnt[i]==0)
		{
			cnt[i]=2;
			for(int j=2*i;j<20000005;j+=i)
			{
				if(cnt[j]==0)
				{
					cnt[j]=2;
				}
				else
				{
					cnt[j]*=2;
				}
			}
		}
	}
	while(test--)
	{
		ll c,d,e;
		cin>>c>>d>>e;
		ll o,ans=0;
		for(ll i=1;(i*i)<=e;i++)
		{
			if((e%i)==0)
			{
				o=e/i+d;
				// cout<<o<<' ';
				if((o%c)==0)
				{
					ans+=cnt[o/c];
				}
				if((i*i)!=e)
				{
					o=i+d;
					if((o%c)==0)
					{
						ans+=cnt[o/c];
					}
				}
			}

		}
		cout<<ans<<'\n';
	}
	return 0;
}