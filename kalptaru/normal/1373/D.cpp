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
ll ms(ll a[], int size) 
{ 
	ll max_so_far = -1*INF, max_ending_here = 0; 

	for (int i = 0; i < size; i++) 
	{ 
		max_ending_here = max_ending_here + a[i]; 
		if (max_so_far < max_ending_here) 
			max_so_far = max_ending_here; 

		if (max_ending_here < 0) 
			max_ending_here = 0; 
	} 
	return max_so_far;
} 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[n];
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		ll ans=0;
		int u=n/2;
		FOR(i,0,u)
		ans+=a[2*i];
		if((n%2)==0)
		{
			ll b[u];
			FOR(i,0,u)
			{
				b[i]=a[2*i+1]-a[2*i];
			}
			ll bns=ans+ms(b,u);
			ll c[u-1];
			FOR(i,0,u-1)
			{
				c[i]=a[2*i+1]-a[2*i+2];
			}
			ll cns=ans+ms(c,u-1);
//			cout<<ans<<' '<<bns<<' '<<cns<<' ';
			cout<<max(ans,max(bns,cns))<<'\n';
		}
		else
		{
			ans+=a[n-1];
			ll b[u];
			FOR(i,0,u)
			{
				b[i]=a[2*i+1]-a[2*i];
			}
			ll bns=ans+ms(b,u);
			ll c[u];
			FOR(i,0,u)
			{
				c[i]=a[2*i+1]-a[2*i+2];
			}
			ll cns=ans+ms(c,u);
//			cout<<ans<<' '<<bns<<' '<<cns<<' ';
			cout<<max(ans,max(bns,cns))<<'\n';
		}
	}
	return 0;
}