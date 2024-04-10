#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fll
typedef unsigned long long ull;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
const int N=3e5+5;
int n,si[N],son[N],fa[N],dep[N],top[N];
vector<int>e1[N],e2[N];
int id,L[N],R[N],rev[N];
void dfs(int u)
{
    si[u]=1;
    son[u]=0;
    for(int v:e2[u])
    {
        dep[v]=dep[u]+1;
        dfs(v);
        si[u]+=si[v];
        if(si[v]>si[son[u]]) son[u]=v;
    }
}
void dfs(int u,int tp)
{
    L[u]=++id;rev[id]=u;
    top[u]=tp;
    if(son[u]) dfs(son[u],tp);
    for(int v:e2[u])
        if(v!=son[u])
        dfs(v,v);
    R[u]=id;
}
int ans;
int t[N<<2];
void build(int l,int r,int k)
{
    t[k]=0;
    if(l==r) return;
    int m=l+r>>1;
    build(l,m,k<<1);build(m+1,r,k<<1|1);
}
void fix(int l,int r,int k,int x,int v)
{
    t[k]+=v;
    if(l==r) return;
    int m=l+r>>1;
    if(x<=m) fix(l,m,k<<1,x,v);
    else fix(m+1,r,k<<1|1,x,v);
}
int query(int l,int r,int k,int x,int y)
{
    if(r<x||l>y) return 0;
    if(l>=x&&r<=y) return t[k];
    int m=l+r>>1;
    return query(l,m,k<<1,x,y)+query(m+1,r,k<<1|1,x,y);
}
int vis[N];
int qmx(int l,int r,int k,int x,int y)
{
    if(r<x||l>y||!t[k]) return 0;
    if(l==r) return l;
    int m=l+r>>1;
    int ans=qmx(m+1,r,k<<1|1,x,y);
    if(!ans)
        ans=qmx(l,m,k<<1,x,y);
    return ans;
}
void add(int x)
{
    if(!query(1,n,1,L[x],R[x]))
    {
        int u=x;
        while(u&&!query(1,n,1,L[top[u]],L[u]))
            u=fa[top[u]];
        if(u)
        {
            vis[x]=rev[qmx(1,n,1,L[top[u]],L[u])];
            fix(1,n,1,L[vis[x]],-1);
            fix(1,n,1,L[x],1);
        }
        else
        {
            vis[x]=-1;
            fix(1,n,1,L[x],1);
        }
    }
}
void del(int x)
{
    if(vis[x]!=-1)
    {
        fix(1,n,1,L[x],-1);
        fix(1,n,1,L[vis[x]],1);
        vis[x]=0;
    }
    else if(vis[x]==-1)
    {
        fix(1,n,1,L[x],-1);
        vis[x]=0;
    }
}
void dfs2(int u)
{
    add(u);
    ans=max(ans,t[1]);
    for(int v:e1[u])
        dfs2(v);
    del(u);
}
int main()
{
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,1,n) e1[i].clear(),e2[i].clear();
        rep(i,2,n)
        {
            int p;sc(p);
            e1[p].push_back(i);
        }
        rep(i,2,n)
        {
            sc(fa[i]);
            e2[fa[i]].push_back(i);
        }
        dfs(1);
        id=0;
        dfs(1,1);
        ans=0;
        build(1,n,1);
        dfs2(1);
        out(ans);
    }
}