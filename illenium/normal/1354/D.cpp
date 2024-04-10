#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define N 1000000
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

int n,m,a[maxn],t[maxn<<2];

inline void upd(int now){t[now]=t[now<<1]+t[now<<1|1];}

inline void add(int now,int l,int r,int x,int w)
{
	//cout<<now<<" "<<l<<" "<<r<<" "<<x<<" "<<w<<endl;
	if(l==r) {t[now]+=w; return;}
	int mid=(l+r)>>1;
	if(x<=mid) add(now<<1,l,mid,x,w);
	else add(now<<1|1,mid+1,r,x,w); upd(now);
}

inline void del(int now,int l,int r,int w)
{
	//cout<<now<<" "<<l<<" "<<r<<endl;
	if(l==r) {t[now]--; return;}
	int mid=(l+r)>>1;
	if(w<=t[now<<1]) del(now<<1,l,mid,w);
	else del(now<<1|1,mid+1,r,w-t[now<<1]); upd(now);
}

inline int Q(int now,int l,int r)
{
	if(l==r) return l; int mid=(l+r)>>1;
	if(t[now<<1]) return Q(now<<1,l,mid);
	else return Q(now<<1|1,mid+1,r);
}

int main()
{
	n=read(); m=read();
	rep(i,1,n) a[i]=read(),add(1,1,N,a[i],1);
	rep(i,1,m) {int x=read(); if(x>0) add(1,1,N,x,1); else del(1,1,N,-x);}
	if(t[1]==0) puts("0"); else cout<<Q(1,1,N);
	return 0;
}