#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define maxn 500005
#define ll long long
#define mid ((l+r)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define lson lc,l,mid
#define rson rc,mid+1,r
#define REP(i,a,b) for(ll i=a;i<=b;++i)
using namespace std;

template<typename T>void read(T &x)
{
    T _=0,mul=1;
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')mul=-1;ch=getchar();}
    while(isdigit(ch))_=(_<<1)+(_<<3)+(ch^'0'),ch=getchar();
    x=_*mul;
}

template<typename T>void write(T x,char ch)
{
    if(!x){putchar('0'); putchar(ch); return; }
    if(x<0){putchar('-'),x*=-1;}
    ll y=10;
    int len=1;
    while(y<=x)y=(y<<1)+(y<<3),++len;
    while(len--)
	{
        y=y/10;
        putchar(x/y+48);
        x=x%y;
    }
    putchar(ch);
}

struct Segment_Tree
{
    ll sum[maxn<<2],tag[maxn<<2];
    void pushdown(int rt,int l,int r)
	{
        sum[lc]+=tag[rt]*(mid-l+1);tag[lc]+=tag[rt];
        sum[rc]+=tag[rt]*(r-mid);  tag[rc]+=tag[rt];
        tag[rt]=0;
    }
    
    inline void update(int rt,int l,int r,int L,int R,ll x)
	{
        if(L<=l && r<=R){
            sum[rt]+=(r-l+1)*x;
            tag[rt]+=x;
            return;
        }
        if(tag[rt])pushdown(rt,l,r);
        if(L<=mid)update(lson,L,R,x);
        if(R>=mid+1)update(rson,L,R,x);
        sum[rt]=sum[lc]+sum[rc];
    }
    
    inline ll query(int rt,int l,int r,int L,int R)
	{
        if(L<=l && r<=R)return sum[rt];
        ll ret=0ll;
        if(tag[rt])pushdown(rt,l,r);
        if(L<=mid)ret+=query(lson,L,R);
        if(R>=mid+1)ret+=query(rson,L,R);
        return ret;
    }
}T;

ll n,q,root,w[maxn],cnt;
ll to[maxn<<1],last[maxn<<1],beg[maxn],cnte;
ll fa[maxn],son[maxn],top[maxn],siz[maxn],dep[maxn],cnt_dfn,dfn[maxn];

inline void add(int u,int v)
{
    last[++cnte]=beg[u];
    beg[u]=cnte;
    to[cnte]=v;
}

inline void dfs1(int u,int f)
{
    fa[u]=f; siz[u]=1; dep[u]=dep[f]+1;
    for(int i=beg[u];i;i=last[i])
	{
        if(to[i]==f)continue;
        dfs1(to[i],u);
        siz[u]+=siz[to[i]];
        if(siz[to[i]]>siz[son[u]]) son[u]=to[i];
    }
}

inline void dfs2(int u,int t)
{
    dfn[u]=++cnt_dfn; top[u]=t;
    if(son[u]) dfs2(son[u],t);
    for(int i=beg[u];i;i=last[i])
	{
        if(to[i]==fa[u]||to[i]==son[u]) continue;
        dfs2(to[i],to[i]);
    }
}

inline int find(int u,int v)
{
    while(top[u]!=top[v])
	{
        ++cnt;
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v] ? u : v;
}

inline int change(int u)
{
    int v=root;
    while(top[v]!=top[u])
	{
        if(fa[top[v]]==u)return top[v];
        v=fa[top[v]];
    }
    return son[u];
}

int main()
{
    read(n); read(q); root=1;
    REP(i,1,n) read(w[i]);
    REP(i,1,n-1)
	{
        int u,v;
        read(u); read(v);
        add(u,v); add(v,u);
    }
    dfs1(1,0); dfs2(1,1);
    REP(i,1,n) T.update(1,1,n,dfn[i],dfn[i],w[i]);
    REP(i,1,q)
	{
        int ty,u,v; ll x; read(ty);
        if(ty==1) {read(u); root=u;}
        else if(ty==2)
		{
            read(u); read(v); read(x);
            int lca=find(u,v),tmp;
            if(dep[tmp=find(u,root)]>dep[lca])lca=tmp;
            if(dep[tmp=find(v,root)]>dep[lca])lca=tmp;
            if(lca==root)T.update(1,1,n,1,n,x);
            else if(dfn[root]<dfn[lca]||dfn[root]>dfn[lca]+siz[lca]-1)
                T.update(1,1,n,dfn[lca],dfn[lca]+siz[lca]-1,x);
            else
			{
                lca=change(lca);
                T.update(1,1,n,1,n,x);
                T.update(1,1,n,dfn[lca],dfn[lca]+siz[lca]-1,-x);
            }
        }
        else
		{
            ll sum=0ll;
            read(u);
            if(u==root) sum=T.query(1,1,n,1,n);
            else if(dfn[root]<dfn[u]||dfn[root]>dfn[u]+siz[u]-1)
                sum=T.query(1,1,n,dfn[u],dfn[u]+siz[u]-1);
            else
			{
                u=change(u);
                sum+=T.query(1,1,n,1,n);
                sum-=T.query(1,1,n,dfn[u],dfn[u]+siz[u]-1);
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}