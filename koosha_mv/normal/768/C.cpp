#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
 
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
 
ll inf=1e15;
ll mod=1e9+7;
 
str ITS(ll x)
{
	str s="";
	while (x>0)
	{
		s+=(char)(x%10+'0');
		x/=10;
	}
	str t="";
	for (int i=s.size()-1;i>-1;i--)
		t+=s[i];
	return t;
}
 
ll bmm(ll a,ll b)
{
	if (a==0)
		return b;
	return bmm(b%a,a);
}
 
bool aval(ll x)
{
	if (x<2)
		return 0;
	if (x<4)
		return 1;
	for (ll i=2;i*i<=x;i++)
		if (x%i==0)
			return 0;
	return 1;
}
 
ll power(ll p,ll t)
{
	if (t==0)
		return 1;
	ll x=power(p,t/2);
	if (t%2)
		return x*x*p;
	else
		return x*x;
}
 
const ll M=2049;
ll a[M],b[M];
/*ll siz(ll n)
{
	if (n<2)
		return 1;
	return 2*siz(n/2)+1;
}
 
ll ans(ll n,ll l,ll r)
{
	if (l>r)
		return 0;
	if (n<2)
		return n;
	ll re=0;
	ll s=siz(n);
	ll vas=s/2+1;
	if (r<vas)
	{
		re=ans(n/2,l,r);
	}
	else if (l>vas)
	{
		re=ans(n/2,l-vas+1,r-vas+1);
	}
	else if (l==r && l==vas)
		re=n%2;
	else
		re=ans(n/2,l,vas-1)+n%2+ans(n/2,1,r-vas);
	cout << n << ' ' << l << ' ' << r << ' ';
	cout << re << '\n';
	return re;
}*/
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll n,k,x,f;
	cin >> n >> k >> x;
	for (ll i=0;i<n;i++)
	{
		cin >> f;
		a[f]++;
	}
	bool ak=0;
	for (ll i=0;i<k;i++)
	{
		for (ll j=0;j<M;j++)
			b[j]=0;
		for (ll j=0;j<M;j++)
		{
			if (!a[j])
				continue;
			if (a[j]%2 && ak)
			{
				b[j]+=a[j]/2+1;
				b[j^x]+=a[j]/2;
				ak=!ak;
			}
			else if (a[j]%2 && !ak)
			{
				b[j]+=a[j]/2;
				b[j^x]+=a[j]/2+1;
				ak=!ak;
			}
			else
			{
				b[j]+=a[j]/2;
				b[j^x]+=a[j]/2;
			}
		}
		for (ll j=0;j<M;j++)
		{
			a[j]=b[j];
			//if (a[j])
				//cout << j << ':' << a[j] << ' ';
		}
		ak=0;
		//cout << '\n';
	}
	ll mi=-1,ma=-1;
	for (ll i=0;i<M;i++)
	{
		if (a[i])
		{
			if (mi==-1)
				mi=i;
			ma=i;
		}
	}
	cout << ma << ' ' << mi;
}