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

ll a[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),nw=0; rep(i,1,n) a[i]=read();
		if(a[1]>0) nw=1; else nw=-1;
		ll ans=0,tmp=a[1];
		rep(i,2,n)
		{
			if(a[i]*nw<0)
			{
				nw*=-1;
				ans+=tmp;
				tmp=a[i];
			}
			else
			{
				tmp=max(tmp,a[i]);
			}
		}
		ans+=tmp;
		printf("%lld\n",ans);
	}
	return 0;
}