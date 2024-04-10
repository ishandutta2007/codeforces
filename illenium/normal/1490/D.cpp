#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
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

int a[maxn],dep[maxn],ans[maxn],n;

inline void dfs(int l,int r,int dep)
{
	if(l>r) return;
	if(l==r) {ans[l]=dep; return;}
	int mx=0,f=0;
	rep(i,l,r) {if(a[i]>mx) mx=a[i],f=i;}
	ans[f]=dep; dfs(l,f-1,dep+1); dfs(f+1,r,dep+1);
}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); rep(i,1,n) a[i]=read();
		dfs(1,n,0); rep(i,1,n) printf("%d ",ans[i]); puts("");
	}
	return 0;
}