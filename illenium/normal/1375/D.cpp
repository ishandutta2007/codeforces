#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
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

vector <int> v,p[maxn];
int a[maxn],c[maxn],n,pos[maxn],y[maxn],vis[maxn];

inline int mex()
{
	rep(i,0,1000) c[i]=0;
	rep(i,0,n-1) c[a[i]]=1;
	rep(i,0,1001) if(!c[i]) return i;
}

inline bool jud()
{
	rep(i,0,n-1) if(a[i]!=i) return false;
	return true;
}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); rep(i,0,n) p[i].clear(),y[i]=0,vis[i]=0;
		rep(i,0,n-1) a[i]=read(),p[a[i]].pb(i); v.clear();
		int nw=0;
		while(1)
		{
			int x=mex(); if(jud()) break;
			if(x==n)
			{
				rep(i,1,n-1) if(a[i]<a[i-1]) {a[i-1]=x; v.pb(i-1); break;}
			}
			else a[x]=x,v.pb(x);
		}
		printf("%d\n",v.size());
		for(int i=0;i<v.size();i++) printf("%d ",v[i]+1); puts("");
	}
	return 0;
}