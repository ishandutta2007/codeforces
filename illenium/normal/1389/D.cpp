#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
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

ll n,k,l1,l2,r1,r2,ans,res,s,x1[maxn],x2[maxn],z1[maxn],y2[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); k=read(); l1=read(); r1=read(); l2=read(); r2=read(); ans=inf; s=0; res=0;
		if(l1>l2) swap(l1,l2),swap(r1,r2);
		if(r2<r1) l2+=r1-r2,r2+=r1-r2;
		rep(i,1,n) x1[i]=l1,x2[i]=r1,z1[i]=l2,y2[i]=r2;
		
		ll nw=max(0ll,r1-l2);
		if(nw>0)
		{
			s+=n*nw;
			rep(i,1,n) x2[i]-=nw,y2[i]-=nw;
		}
		if(s>=k) {puts("0"); continue;}
		
		if(s<k)
		{
			rep(i,1,n)
			{
				if(s>=k) break;
				res+=z1[i]-x2[i]; ll tmp=y2[i]-x1[i];
				if(s+tmp>=k) res+=k-s,s=k;
				else s+=tmp,res+=tmp,ans=min(ans,res+2*(k-s));
			}
		}
		if(s<k) res+=2*(k-s);
		ans=min(ans,res); printf("%lld\n",ans);
	}
	return 0;
}