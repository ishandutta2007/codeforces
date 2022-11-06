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
ll gcd(ll a ,ll b)
{
	if(a<b)swap(a,b);
	if(a%b==0)
	return b;
	return gcd(b,a%b);
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
		ll n;
		cin>>n;
		ll o =n;
		ll s=sqrt(n);
		FOR(i,2,s+1)
		{
			if(n%i==0)
			{
				o=gcd(o,i);
				ll r=n/i;
				o=gcd(o,r);
				if(o==1)
				break;
			}
		}
		cout<<o;
	}
	return 0;
}