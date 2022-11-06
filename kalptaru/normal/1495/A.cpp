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
//ll mod=67280421310721;
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
	spre
	while(test--)
	{
		int n;
		cin>>n;
		int m[n],d[n],u,v;
		double x,y,ans=0;
		int a=0,b=0;
		FOR(i,0,2*n)
		{
			cin>>u>>v;
			if(u==0)
			{
				m[a]=abs(v);
				a++;
			}
			else
			{
				d[b]=abs(u);
				b++;
			}
		}
		sort(m,m+n);
		sort(d,d+n);
		FOR(i,0,n)
		{
			x=m[i];
			y=d[i];
			ans+=sqrt(x*x+y*y);
		}
		cout<<ans<<'\n';
	}
	return 0;
}