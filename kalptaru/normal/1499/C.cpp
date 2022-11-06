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
	while(test--)
	{
		int n;
		cin>>n;
		ll c[n];
		FOR(i,0,n)
		{
			cin>>c[i];
		}
		ll m1=c[0],m2=c[1];
		ll c1=1,c2=1;
		ll s1=c[0],s2=c[1];
		ll ans=n*(c[0]+c[1]);
		FOR(i,2,n)
		{
			if((i%2)==0)
			{
				c1++;
				m1=min(m1,c[i]);
				s1+=c[i];
			}
			else
			{
				c2++;
				m2=min(m2,c[i]);
				s2+=c[i];
			}
			ans=min(ans,(n-c1)*m1+(n-c2)*m2+s1+s2);
		}
		cout<<ans<<'\n';
	}
	return 0;
}