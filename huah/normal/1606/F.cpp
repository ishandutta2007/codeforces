#include<bits/stdc++.h>
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
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2e5+5,mod1=1e9+7,mod2=998244353;
#define inf 0x3f3f3f3f
int n,q,d[N],si[N],son[N],top[N],dep[N];
int id,dfn[N],fa[N],f[N];
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
vector<int>e[N];
bool vis[N];
struct node
{
    int x,y,u;
    bool operator==(const node&o)const
    {
        return x==o.x&&y==o.y&&u==o.u;
    }
    bool operator<(const node&o)const
    {
        if(1ll*x*o.y==1ll*o.x*y)
        {
            if(x!=o.x) return x<o.x;
            if(y!=o.y) return y<o.y;
            return u<o.u;
        }
        return 1ll*x*o.y<1ll*o.x*y;
    }
};
node s[N];
bool cmp(const node&a,const node&b)
{
    return a.x>b.x;
}
vector<node>vc;
priority_queue<node>pq,del;
void dfs(int u,int p)
{
    si[u]=1;fa[u]=p;
    dep[u]=dep[p]+1;
    for(int v:e[u])
    {
        if(v==p) continue;
        d[u]++;
        dfs(v,u);
        if(si[v]>si[son[u]]) son[u]=v;
        si[u]=max(si[u],si[v]+1);
    }
    pq.push({d[u]-1,1,u});
    s[u]={d[u]-1,1,u};
}
void dfs2(int u,int tp)
{
    top[u]=tp;
    dfn[u]=++id;
    if(son[u]) dfs2(son[u],tp);
    for(int v:e[u])
    {
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
ll ans[N];
pair<int,int>t[N<<2],lz[N<<2];
pair<int,int>operator+(const pair<int,int>&a,const pair<int,int>&b)
{
    return {a.first+b.first,a.second+b.second};
}
void update(int l,int r,int k)
{
    if(l!=r)
    {
        t[k<<1]=t[k<<1]+lz[k];
        t[k<<1|1]=t[k<<1|1]+lz[k];
        lz[k<<1]=lz[k<<1]+lz[k];
        lz[k<<1|1]=lz[k<<1|1]+lz[k];
    }
    lz[k]={0,0};
}
void ins(int l,int r,int k,int x,int y,pair<int,int>v)
{
    if(r<x||l>y) return;
    if(l>=x&&r<=y)
    {
        t[k]=t[k]+v;
        lz[k]=lz[k]+v;
        return;
    }
    if(lz[k]!=make_pair(0,0)) update(l,r,k);
    int m=(l+r)>>1;
    ins(l,m,k<<1,x,y,v);ins(m+1,r,k<<1|1,x,y,v);
    t[k]=t[k<<1]+t[k<<1|1];
}
pair<int,int>query(int l,int r,int k,int x,int y)
{
    if(r<x||l>y) return {0,0};
    if(l>=x&&r<=y) return t[k];
    if(lz[k]!=make_pair(0,0)) update(l,r,k);
    int m=(l+r)>>1;
    return query(l,m,k<<1,x,y)+query(m+1,r,k<<1|1,x,y);
}
void sol(int x,int y,int u,int v)
{
    // cout<<"sss: "<<v<<' '<<v<<' '<<x<<' '<<y<<endl;
    while(top[u]!=top[v])
    {
        ins(1,n,1,dfn[top[u]],dfn[u],{x,y});
        u=fa[top[u]];
    }
    if(v==0) assert(u==0);
    if(v) ins(1,n,1,dfn[v],dfn[u],{x,y});
}
void fc()
{
    fstream a,b,c;
    a.open("1.out");
    b.open("2.out");
    c.open("1.in");
    int n;
    c>>n;
    rep(i,1,n-1)
    {
        int s,t;c>>s>>t;
    }
    c>>n;
    int x,y,tot=0;
    while(true)
    {
        ++tot;
        a>>x;b>>y;
        int qx,qy;
        c>>qx>>qy;
        if(x!=y)
        { 
            cout<<qx<<' '<<qy<<'\n';
            break;
        }
    }
}
int main()
{
    // fc();return 0;
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    sc(n);
    rep(i,1,n-1)
    {
        int u,v;sc(u,v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    sc(q);
    rep(i,1,q)
    {
        int v,k;sc(v,k);
        vc.push_back({k,v,i});
    }
    sort(vc.begin(),vc.end(),cmp);
    dfs(1,0);
    dfs2(1,1);
    rep(i,1,n) f[i]=i;
    int zz=0;
    for(node x:vc)
    {
        zz++;
        while(pq.size()&&pq.top().x/pq.top().y>=x.x)
        {
            if(del.size()&&del.top()==pq.top())
            {
                del.pop();pq.pop();continue;
            }
            int u=pq.top().u;
            int g=getf(fa[u]);
            // cout<<"UP: "<<' '<<pq.size()<<' '<<pq.top().x<<' '<<pq.top().y<<' '<<pq.top().u<<' '<<g<<endl;
            sol(pq.top().x,pq.top().y,fa[u],g);
            int dx=pq.top().x,dy=pq.top().y;
            pq.pop();
            if(g)
            {
                del.push(s[g]);
                s[g].x+=dx;
                s[g].y+=dy;
                // cout<<"G: "<<s[g].x<<' '<<s[g].y<<'\n';
                pq.push(s[g]);
            }
            f[u]=g;
            vis[u]=true;
            // cout<<"ED: "<<pq.size()<<endl;
        }
        pair<int,int>z=query(1,n,1,dfn[x.y],dfn[x.y]);
        ans[x.u]=d[x.y]+z.first-1ll*z.second*x.x;
        // cout<<"Z: "<<z.first<<' '<<z.second<<'\n';
        // cout<<"G: "<<x.x<<' '<<x.y<<' '<<x.u<<' '<<z.first<<' '<<z.second<<' '<<ans[x.u]<<' '<<d[x.y]<<'\n';
    }
    rep(i,1,q) out(ans[i]);
}