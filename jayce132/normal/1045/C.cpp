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

const int maxn=1e6+20;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n,m,dfn[maxn],low[maxn],st[maxn],top,times,q;

int tot;
vector<int>to[maxn];

void dfs(int u,int fa)
{
    low[u]=dfn[u]=++times;st[++top]=u;
    EREP(i,u)
    {
        int v=e[i].v;
        if(v==fa)continue;
        if(!dfn[v])
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u])
            {
                int x;
                ++tot;
                do{
                    x=st[top--];
                    to[tot].push_back(x);
                    to[x].push_back(tot);
                }while(x!=v);
                
                to[tot].push_back(u);
                to[u].push_back(tot);
            }
        }else low[u]=min(low[u],dfn[v]);
    }
}

int p[maxn][21],deep[maxn];

void dfs1(int u,int fa)
{
	for(int v:to[u])
	{
		if(v==fa)continue;
		p[v][0]=u;
		deep[v]=deep[u]+1;
		dfs1(v,u);
	}
}

inline void init()
{
	n=read();m=read();q=read();
	REP(i,1,m)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	tot=n;
	dfs(1,0);
	deep[1]=1;
	dfs1(1,0);
	REP(j,1,20)REP(i,1,tot)p[i][j]=p[p[i][j-1]][j-1];
}

inline int lca(int u,int v)
{
	if(deep[u]<deep[v])swap(u,v);
	int dis=deep[u]-deep[v];
	DREP(i,20,0)if(dis>>i&1)u=p[u][i];
	if(u==v)return u;
	DREP(i,20,0)if(p[u][i]!=p[v][i])u=p[u][i],v=p[v][i];
	return p[u][0];
}

inline int dis(int u,int v){ return deep[u]+deep[v]-2*deep[lca(u,v)];}

inline void doing()
{
	REP(i,1,q)
	{
		int u=read(),v=read();
		printf("%d\n",dis(u,v)/2);
	}
	
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}