#pragma GCC optimize(3,"Ofast","inline")
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

ll n;

inline bool jud(ll x)
{
	ll tmp=2*x-1;
	if((tmp*tmp-1)/2+1<=n) return true;
	return false;
}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); ll l=1,r=n+1,ans;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(jud(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d\n",ans-1);
	}
	return 0;
}