#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e5+20;

struct edge {
	int u,v,w,op,id;

};

inline bool operator <(edge a,edge b){ return a.w==b.w?a.op<b.op:a.w<b.w;}
inline bool cmp1(edge a,edge b){ return a.w==b.w?a.op>b.op:a.w<b.w;}

edge E[maxn];
edge E1[maxn];

int n,m,k;

inline void init()
{
	n=read();m=read();k=read();
	REP(i,1,m)
	{
		int u=read(),v=read(),w=read();
		E[i]=(edge){u,v,w};
	}
}

#define pri pair<int,int>
#define mkr(a,b) make_pair(a,b)
#define fi first
#define se second

int fa[maxn];

int fin(int x){ return x==fa[x]?x:fa[x]=fin(fa[x]);}
inline void merge(int x,int y){ x=fin(x);y=fin(y);fa[y]=x;}

int vis[maxn];

pri check(int x)
{
	int ans=0,s=0;
	REP(i,1,m)E1[i]=E[i],E1[i].op=E[i].u==1 || E[i].v==1,E1[i].w+=x*(E1[i].op),E1[i].id=i;
	sort(E1+1,E1+m+1,cmp1);
	REP(i,1,n)fa[i]=i;
	memset(vis,0,sizeof(vis));
	REP(i,1,m)
	{
		int u=E1[i].u,v=E1[i].v,w=E1[i].w;
		if(fin(u)==fin(v))continue;
		ans+=w;s+=E1[i].op;
		vis[E1[i].id]=1;
		merge(u,v);
	}
	return mkr(ans,s);
}

pri calc(int x)
{
	int ans=0,s=0,s1=0;
	REP(i,1,m)E1[i]=E[i],E1[i].op=E[i].u==1 || E[i].v==1,E1[i].w+=x*(E1[i].op),E1[i].id=i;
	sort(E1+1,E1+m+1,cmp1);
	REP(i,1,n)fa[i]=i;
	memset(vis,0,sizeof(vis));
	REP(i,1,m)
	{
		int u=E1[i].u,v=E1[i].v,w=E1[i].w;
		if(fin(u)==fin(v))continue;
		if(s==k && E1[i].op)continue;
		ans+=w;s+=E1[i].op;s1+=!E1[i].op;
		vis[E1[i].id]=1;
		merge(u,v);
	}
	if(s1+s!=n-1)puts("-1"),exit(0);
	return mkr(ans,s);
}

inline void doing()
{
	int l=-1e5-1,r=1e5+1;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid).se>=k)l=mid;
		else r=mid-1;
	}
	pri x=calc(l);
	//if(x.se!=k)puts("-1");
	{
		//printf("%d\n",x.fi-k*l);
		printf("%d\n",n-1);
		REP(i,1,m)if(vis[i])printf("%d ",i);puts("");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("kmst.in","r",stdin);
	freopen("kmst.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}