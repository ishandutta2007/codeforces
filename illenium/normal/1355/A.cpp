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

inline ll wk(ll x)
{
	int mn=1000,mx=0;
	while(x)
	{
		int tmp=x%10;
		mx=max(mx,tmp); mn=min(mn,tmp); x/=10;
	}
	return mn*mx;
}

int main()
{
	int T=read();
	while(T--)
	{
		ll n=read(),k=read()-1;
		while(k)
		{
			int p=wk(n);
			if(p==0) break;
			n+=p; k--;
		}
		printf("%lld\n",n);
	}
	return 0;
}