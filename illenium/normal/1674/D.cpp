#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

int a[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(); rep(i,1,n) a[i]=read();
		for(int i=(n%2==0?1:2);i+1<=n;i+=2) if(a[i]>a[i+1]) swap(a[i],a[i+1]);
		int F=0; rep(i,2,n) if(a[i]<a[i-1]) {F=1; break;}
		if(F) puts("NO"); else puts("YES");
	}
	return 0;
}