#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

ll n,a[maxn],tmp,ans[maxn],b[maxn];

inline void jud(int x)
{
	ll res=0;
	for(int i=1;i<=n;i++) a[i]=b[i];
	for(int i=x-1;i>=1;i--)
	{
		if(a[i]>a[i+1])
		{
			res+=(a[i]-a[i+1]);
			a[i]=a[i+1];
		}
	}
	for(int i=x+1;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			res+=(a[i]-a[i-1]);
			a[i]=a[i-1];
		}
	}
	if(res<tmp)
	{
		tmp=res;
		for(int i=1;i<=n;i++) ans[i]=a[i];
	}
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) b[i]=read();
	tmp=inf;
	for(int i=1;i<=n;i++) jud(i);
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}