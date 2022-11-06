#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
typedef long long int ll;
using namespace std;
ll gcd(ll a,ll b)
{
	if(a<b)
	swap(a,b);
	if(a%b==0)
	return b;
	else
	return gcd(b,a%b);
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		ll a[n],m=0,mi=100000000000;
		FOR(i,0,n)
		{
			cin>>a[i];
			m=max(m,a[i]);
			mi=min(mi,a[i]);
		}
		ll g=m-mi,s=0;
		FOR(i,0,n)
		{
			s+=(m-a[i]);
			if(a[i]!=m)
			g=gcd(g,m-a[i]);
		}
		s=s/g;
		cout<<s<<' '<<g;
		
	}
	return 0;
}