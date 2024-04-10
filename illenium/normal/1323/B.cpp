#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

ll n,m,k,a[maxn],b[maxn],pa[maxn],pb[maxn];

inline ll fa(ll x)
{
	ll cnt=0;
	for(int i=x;i<=n;i++)
	{
		if(pa[i]-pa[i-x]==x) cnt++;
	}
	return cnt;
}

inline ll fb(ll x)
{
	ll cnt=0;
	for(int i=x;i<=m;i++)
	{
		if(pb[i]-pb[i-x]==x) cnt++;
	}
	return cnt;
}

int main()
{
	n=read(); m=read(); k=read(); 
	for(int i=1;i<=n;i++) a[i]=read(),pa[i]=pa[i-1]+a[i];
	for(int i=1;i<=m;i++) b[i]=read(),pb[i]=pb[i-1]+b[i];
	ll ans=0;
	for(ll i=1;i*i<=k;i++)
	{
		if(k%i==0)
		{
			ll t1=i,t2=k/i,x1=fa(t1),x2=fb(t2);
			ans+=x1*x2;
			if(i*i==k) continue;
			x1=fa(t2),x2=fb(t1); ans+=x1*x2;
		}
	}
	cout<<ans<<endl;
	return 0;
}