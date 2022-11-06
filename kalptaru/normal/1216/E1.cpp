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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while ( t-- ) 
	{
		ll k;
		cin>>k;
		ll a=1,d=1,n=9,s=45;
		while(k>s)
		{
			k-=s;
			a=a+d*n+1;
			d++;
			n*=10;
			s=n*(2*a+(n-1)*d)/2;
		}
		ll l=0,r=n;
		while(l<r)
		{
			ll mid=l+((r-l+1)>>1);
			s=mid*(2*a+(mid-1)*d)/2;
			if(k>s)
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		s=l*(2*a+(l-1)*d)/2;
		k-=s;
		n=9;
		d=1;
		while(k>n*d)
		{
			k-=(n*d);
			n*=10;
			d++;
		}
		n=k/d;
//		cout<<k<<' '<<d<<' ';
		if(k%d==0)
		{
//			cout<<n<<' ';
			n=pow(10,d-1)+n-1;
//			cout<<n<<' ';
			cout<<n%10<<'\n';
		}
		else
		{
//			cout<<n<<' ';
			n=pow(10,d-1)+n;
//			cout<<n<<' ';
			n=n/pow(10,d-(k%d));
//			cout<<n<<' ';
			cout<<n%10<<'\n';
		}
	}
	return 0;
}