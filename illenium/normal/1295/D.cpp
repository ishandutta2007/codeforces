#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

inline ll phi(ll x)
{
	ll ans=x;
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ans=ans/i*(i-1);
			while(x%i==0) x/=i;
		}
	}
	if(x!=1) ans=ans/x*(x-1);
	return ans;
}

int main()
{
	ll T=read();
	while(T--)
	{
		ll x=read(),y=read(); ll g=__gcd(x,y); //cout<<y/g<<endl;
		printf("%lld\n",phi(y/g));
	}
	return 0;
}