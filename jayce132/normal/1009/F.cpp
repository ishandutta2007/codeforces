#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
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

const int maxn=1e6+20;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];

inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

struct Node {
	int mx,mxid,lc,rc;
	inline void Merge(Node lc,Node rc){
		mxid=lc.mxid;mx=lc.mx;
		if(lc.mx<rc.mx)mxid=rc.mxid,mx=rc.mx;
	}
};

Node c[maxn*26];
int root[maxn],tot;

int n,deep[maxn],ans[maxn];

void update(int x,int d,int &o,int l,int r)
{
	if(!o)o=++tot;
	c[o].mx=1;c[o].mxid=x;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)update(x,d,c[o].lc,l,mid);
	else update(x,d,c[o].rc,mid+1,r);
}

int Merge(int x,int y,int l,int r)
{
	if(!x || !y)return x|y;
	if(l==r)return c[x].mx=c[x].mx+c[y].mx,c[x].mxid=l,x;
	int mid=(l+r)>>1;
	c[x].lc=Merge(c[x].lc,c[y].lc,l,mid);
	c[x].rc=Merge(c[x].rc,c[y].rc,mid+1,r);
	c[x].Merge(c[c[x].lc],c[c[x].rc]);
	return x;
}
	

void dfs(int u,int fa)
{
	update(deep[u],1,root[u],1,n);
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		deep[v]=deep[u]+1;
		dfs(v,u);
		root[u]=Merge(root[u],root[v],1,n);
	}
	ans[u]=c[root[u]].mxid-deep[u];
}

inline void init()
{
	n=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	deep[1]=1;
	dfs(1,0);
	REP(i,1,n)printf("%d\n",ans[i]);
}

inline void doing()
{
	
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("F.in","r",stdin);
    freopen("F.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}