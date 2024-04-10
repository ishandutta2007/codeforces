#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,a[maxn];
bitset <2000005> s,t;

int main()
{
	int T=read(),st=1000000;
	while(T--)
	{
		n=read(); int F=0; s.reset(); s[st]=1;
		rep(i,1,n)
		{
			a[i]=read();
			if(a[i]>=0) t=(s<<a[i]);
			else a[i]=-a[i],t=(s>>a[i]);
			if((s&t).count()) F=1; s|=t;
		}
		if(F) puts("YES"); else puts("NO");
	}
	return 0;
}