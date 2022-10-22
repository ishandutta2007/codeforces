#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define eps 1e-5
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

ll x,y,a,b;

inline double jud(double p1)
{
	if((x-a*p1)<0||(y-b*p1)<0) return -inf;
	double p2=min((x-a*p1)/b,(y-b*p1)/a); if(p2<0) return -inf;
	return p1+p2;
}

int main()
{
	int T=read();
	while(T--)
	{
		x=read(),y=read(),a=read(),b=read();
		if(x>y) swap(x,y); if(a>b) swap(a,b);
		ll l=0,r=inf,ans=0;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(jud(mid)==-inf) {r=mid-1; continue;}
			if(jud(mid)<=jud(mid+eps)) ans=max(ans,(ll)jud(mid)),l=mid+1;
			else ans=max(ans,(ll)jud(mid)),r=mid-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}