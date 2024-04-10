#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,a[maxn];

inline ll wk2(ll x)
{
	per(i,63,0)
	{
		ll tmp=1ll<<i;
		if(x&tmp) return i+1;
	}
	return 0;
}

inline ll wk(ll x)
{
	per(i,63,0)
	{
		ll tmp=1ll<<i;
		if(x&tmp) return tmp;
	}
	return 0;
}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); rep(i,1,n) a[i]=read(); ll ff=0,ans=0;
		rep(i,2,n) if(a[i]<a[i-1]) ff=1;
		if(ff==0) {puts("0"); continue;}
		
		rep(i,2,n) if(a[i-1]>a[i])
		{
			ll tmp=a[i-1]-a[i];
			if(ans<tmp) ans=wk(tmp); a[i]=a[i-1];
		}
		
		ll q=wk2(ans); printf("%d\n",q);
		
	}
	return 0;
}