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
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
ll mod=8589934592;
// const ll mod=1000000007;
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
	while(test--)
	{
		int n;
		cin>>n;
		ll a[n],u;
		bool b[n]={0};
		int m=0,t=0;
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		int c=0,o,ans;
		FOR(i,1,n-1)
		{
			if((a[i]<a[i-1] && a[i]<a[i+1])||(a[i]>a[i-1] && a[i]>a[i+1]))
			{
				c++;
				b[i]=1;
			}
		}
		if(c==0)
		{
			cout<<0<<'\n';
			continue;
		}
		ans=c;
		FOR(i,1,n-1)
		{
			t=0;
			m=0;
			o=0;
			FOR(j,i-1,i+2)
			{
				if(b[j])
					o++;
			}
			u=a[i];
			m=o;
			FOR(j,max(i-2,ll(0)),min(ll(n),i+3))
			{
				a[i]=a[j];
				if(i==j)
					a[i]=u;
				t=0;
				FOR(k,max(i-1,ll(1)),min(i+2,ll(n-1)))
				{
					if((a[k]<a[k-1] && a[k]<a[k+1])||(a[k]>a[k-1] && a[k]>a[k+1]))
					{
						t++;
					}
				}
				m=min(m,t);
			}
			a[i]=u;
			ans=min(ans,c-o+m);
		}
		cout<<ans<<'\n';
	}
	return 0;
}