#pragma GCC optimize(3,"Ofast","inline")
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

ll n,p,k,x,y,suf[maxn];
char s[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); p=read(); k=read(); scanf("%s",s+1); x=read(); y=read();
		per(i,n,1)
		{
			if(i+k<=n) suf[i]=suf[i+k];
			suf[i]+=(s[i]=='0');
		}
		
		ll ans=inf;
		rep(i,p,n) ans=min(ans,(i-p)*y+suf[i]*x);
		printf("%lld\n",ans); rep(i,1,n) suf[i]=0;
	}
	return 0;
}