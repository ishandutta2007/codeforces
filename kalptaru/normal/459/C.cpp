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
		int n,d;
		ll k;
		cin>>n>>k>>d;
		if(k==1 && n!=1)
		{
			cout<<-1;
			return 0;
		}
		if(n==1)
		{
			FOR(i,0,d)
			cout<<1<<'\n';
			return 0;
		}
		int o=ceil(log(n)/log(k));
		if(o>d)
		{
			cout<<-1;
			return 0;
		}
		int a[n];
		FOR(i,0,n)
		a[i]=i;
//		cout<<o<<'\n';
		FOR(i,0,d)
		{
			FOR(j,0,n)
			{
				cout<<a[j]%k+1<<' ';
				a[j]/=k;
			}
			cout<<'\n';
		}
		
	}
	return 0;
}