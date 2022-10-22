#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e18
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

ll n,a,b,c,A[maxn],pre[maxn],suf[maxn],ans;

inline ll sol(ll x)
{
	ll x1=0,x2=0;
	for(int i=1;i<=n;i++) if(A[i]>=x) x1+=(A[i]-x); else x2+=(x-A[i]);
	ll p=min(x1,x2); x1-=p; x2-=p;
	return c*p+b*x1+a*x2;
}

int main()
{
	n=read(); a=read(); b=read(); c=read(); rep(i,1,n) A[i]=read();
	sort(A+1,A+n+1); c=min(c,a+b);
	rep(i,1,n) pre[i]=pre[i-1]+A[i];
	per(i,n,1) suf[i]=suf[i+1]+A[i];
	ll ans=inf;
	rep(i,1,n)
	{
		ll x1=i*A[i]-pre[i],x2=suf[i+1]-(n-i)*A[i];
		ll p=min(x1,x2); x1-=p; x2-=p;
		ans=min(ans,c*p+x1*a+x2*b);
	}
	for(int i=-10;i<=10;i++) ans=min(ans,sol((pre[n]/n)+i));
	cout<<ans<<endl;
	return 0;
}