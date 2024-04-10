#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
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

ll n,m,k,X[maxn],Y[maxn],pos[maxn],LCM,q[maxn],cnt;
ll A[maxn],B[maxn],p[maxn];

inline ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b) {x=1; y=0; return a;}
	else
	{
		ll d=exgcd(b,a%b,x,y),t=x; x=y; y=t-a/b*y;
		return d;
	}
}

inline ll excrt()
{
	ll ans=B[1],M=A[1];
	rep(i,2,2)
	{
		ll a=M,b=A[i],x,y; ll d=exgcd(a,b,x,y),c=(B[i]-ans%b+b)%b;
		if(c%d!=0) return -1;
		ll p=b/d; x*=c/d; x%=p; if(x<0) x+=p;
		ans+=x*M; M/=d; M*=A[i];
	}
	return ans;
}

inline bool jud(ll x)
{
	ll ret=0;
	rep(i,1,cnt)
	{
		ret+=(x/LCM);
		if(x%LCM>=q[i]) ret++;
	}
	if(x-ret>=k) return true; return false;
}

int main()
{
	n=read(); m=read(); k=read(); A[1]=n; A[2]=m; LCM=n/__gcd(n,m)*m;
	rep(i,0,n-1) X[i]=read(),pos[X[i]]=i,p[X[i]]=1;
	rep(i,0,m-1)
	{
		Y[i]=read();
		if(p[Y[i]])
		{
			B[1]=pos[Y[i]]; B[2]=i;
			ll tmp=excrt(); if(tmp!=-1) q[++cnt]=tmp+1;
		}
	}
	ll l=0,r=1e18,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(jud(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}