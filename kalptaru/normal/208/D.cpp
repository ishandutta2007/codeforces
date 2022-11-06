#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
ll powm(ll a,ll b)
{
	ll r=a%mod,ans=1;
	while(b>0)
	{
		if(b%2==1)
		ans=(ans*r)%mod;
		r=(r*r)%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		ll p[n];
		FOR(i,0,n)
		cin>>p[i];
		ll a[5];
		FOR(i,0,5)
		cin>>a[4-i];
		ll o=0,f[5]={0};
		FOR(i,0,n)
		{
			o+=p[i];
			FOR(j,0,5)
			{
				f[j]+=(o/a[j]);
				o%=a[j];
			}
		}
		FOR(i,0,5)
		cout<<f[4-i]<<' ';
		cout<<'\n';
		cout<<o;
	}
	return 0;
}