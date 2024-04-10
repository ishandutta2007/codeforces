#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 500005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],mn[maxn],mx[maxn],f[maxn],n,num;

int main()
{
	n=read(); mx[1]=1;
	for(ll i=2;i<=n;i++)
	{
		if(f[i]==0) mn[i]=i,a[++num]=i;
		for(ll j=1;a[j]*i<=n&&j<=num;j++)
		{
			ll x=i*a[j];
			mn[x]=a[j]; f[x]=1;
			if(i%a[j]==0) break;
		}
	}
	for(ll i=2;i<=n;i++) mx[i]=i/mn[i];
	sort(mx+1,mx+n+1);
	for(int i=2;i<=n;i++) printf("%lld ",mx[i]);
	return 0;
}