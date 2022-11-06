#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int gcd(ll a,ll b)
{
	if(a%b==0)
	return b;
	else
	return(gcd(b,a%b));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		ll n,d,e,v,l,g;
		cin>>n>>d>>e;
		e*=5;
		if(d<e)
		swap(d,e);
		v=n/e;
		g=gcd(d,e);
		l=e*d/g;
		if(n>e*d)
		cout<<n%g;
		else
		{
			ll m=n%e,r=n%e;
			while(v || r>=d)
			{
				if(r>=d)
				{
					r-=d;
				}
				else
				{
					r+=e;
					v--;
				}
				m=min(r,m);
			}
			cout<<m;
		}
	}
	return 0;
}