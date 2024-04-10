#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
ll po(ll a,ll b)
{
	ll ans=1;
	while(b>0)
	{
		if(b%2==1)
		ans=((ans*a)%mod);
		a=((a*a)%mod);
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
		ll x,n,r,f,o;
		cin>>x>>n;
		ll ans=1;
		vector<int> p;
		r=sqrt(x);
		r+=2;
		FOR(i,2,r)
		{
			if(x%i==0)
			{
				p.push_back(i);
				while(x%i==0)
				x=x/i;
			}
		}
		if(x>1)
		p.push_back(x);
		r=p.size();
		FOR(i,0,r)
		{
//			cout<<p[i]<<' ';
			o=n%mod;
			f=n/p[i];
			while(f>0)
			{
				ans=((ans*po(p[i],f))%mod);
				f=f/p[i];
			}
		}
		cout<<ans;
	}
	return 0;
}