#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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

inline ll pd(int a,int b)
{
	if(a%b==0) return a/b;
	return a/b+1;
}

int main()
{
	ll T=read();
	while(T--)
	{
		ll n=read(),d=read(),ans=inf,lst=inf;
		for(int i=0;i<=d;i++)
		{
			ll nw=(i+pd(d,i+1));
			if(nw>lst) break;
			lst=nw;
		}
		if(lst<=n) puts("YES");
		else puts("NO");
	}
	return 0;
}