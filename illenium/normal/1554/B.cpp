#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e18
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

ll n,k,a[maxn],mx;

inline ll f(ll x,ll y){return x*y-k*(a[x]|a[y]);}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); k=read(); mx=-inf; rep(i,1,n) a[i]=read();
		for(int i=n;i>=max(1ll,n-100);i--)
		{
			for(int j=i-1;j>=max(1ll,n-100);j--)
				mx=max(mx,f(i,j));
		}
		printf("%lld\n",mx);
	}
	return 0;
}