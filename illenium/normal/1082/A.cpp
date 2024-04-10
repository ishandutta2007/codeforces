#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e18
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int main()
{
	ll T=read();
	while(T--)
	{
		ll n=read(),x=read(),y=read(),d=read(); ll ans=inf;
		if(abs(y-x)%d==0) printf("%lld\n",abs(y-x)/d);
		else
		{
			ll ans=inf;
			if((y-1)%d==0) ans=min(ans,(y-1)/d+(x-2)/d+1);
			if((n-y)%d==0) ans=min(ans,(n-y)/d+(n-x-1)/d+1);
			if(ans==inf) puts("-1");
			else printf("%lld\n",ans);
		}
	}
	return 0;
}