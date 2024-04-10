#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define inf 1e9
#define ins insert
#define pb push_back
#define vi vector <int>
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

int n,k,a[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int ans=0;
		n=read(); k=read(); rep(i,1,n) a[i]=read();
		rep(b,0,k)
		{
			int c0=0,c1=0;
			rep(i,1,n) if(a[i]&(1<<b)) c1++; else c0++;
			if(c1>c0) ans+=(1<<b);
		}
		printf("%d\n",ans);
	}
	return 0;
}