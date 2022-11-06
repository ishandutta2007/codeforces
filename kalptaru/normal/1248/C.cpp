#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) ;for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,m;
		cin>>n>>m;
		ll i=0,j=1,ans=0,t;
		if(n<m)swap(n,m);
		FOR(o,0,m)
		{
			t=(i+j)%mod;
			i=j;
			j=t;
		}
		ans+=2*(j-1);
		FOR(o,m,n)
		{
			t=(i+j)%mod;
			i=j;
			j=t;
		}
		ans+=2*j;
		cout<<ans%mod;
	}
	return 0;
}