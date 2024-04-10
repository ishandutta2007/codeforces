#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
typedef long long ll;
int n,k,sum,rt,a[N],si[N],f[N];
bool vis[N];
vector<pair<int,int>>e[N];
void getrt(int u,int p)
{
    si[u]=1;f[u]=0;
    for(pair<int,int> &x:e[u])
    {
        int v=x.first;
        if(v==p||vis[v]) continue;
        getrt(v,u);
        si[u]+=si[v];
        f[u]=max(f[u],si[v]);
    }
    f[u]=max(f[u],sum-si[u]);
    if(f[u]<f[rt]) rt=u;
}
ll ans;
int bit[2][N],sz[2][N];
void add(int c,int x,ll v,int dv)
{
    x++;
    while(x<=n) sz[c][x]=(sz[c][x]+dv)%mod,bit[c][x]=(bit[c][x]+v)%mod,x+=x&-x;
}
ll query(int c,int x)
{
    x++;
    ll ans=0;
    while(x) ans=(ans+bit[c][x])%mod,x-=x&-x;
    return ans;
}
ll querysz(int c,int x)
{
    x++;
    ll ans=0;
    while(x) ans=(ans+sz[c][x])%mod,x-=x&-x;
    return ans;
}
int ad;
void dfs(int u,int p,int c,int las,int d,ll dis)
{
    if(d<=k)
    { 
        ans=(ans+dis+ad)%mod;
        ans=(ans+query(c,k-d)+querysz(c,k-d)*dis%mod)%mod;
        if(d<k)
            ans=(ans+query(c^1,k-d-1)+querysz(c^1,k-d-1)*dis%mod)%mod;
    }
    for(pair<int,int>&x:e[u])
    {
        int v=x.first;
        if(vis[v]||v==p) continue;
        dfs(v,u,c,x.second,d+(las!=x.second),(dis+a[v])%mod);
    }
}
void gfs(int u,int p,int c,int las,int d,ll dis,int op)
{
    if(op==1) add(c,d,dis%mod,1);
    else add(c,d,(mod-dis)%mod,mod-1);
    for(pair<int,int>&x:e[u])
    {
        int v=x.first;
        if(vis[v]||v==p) continue;
        gfs(v,u,c,x.second,d+(las!=x.second),(dis+a[v])%mod,op);
    }
}
void sol(int u)
{
    vis[u]=true;
    ans=(ans+a[u])%mod;
    for(pair<int,int>&x:e[u])
    {
        int v=x.first;
        if(vis[v]) continue;
        ad=a[u];
        dfs(v,u,x.second,x.second,0,a[v]);
        gfs(v,u,x.second,x.second,0,(a[u]+a[v])%mod,1);
    }
    for(pair<int,int>&x:e[u])
    {
        int v=x.first;
        if(vis[v]) continue;
        gfs(v,u,x.second,x.second,0,(a[u]+a[v])%mod,-1);
    }
    for(pair<int,int>&x:e[u])
    {
        int v=x.first;
        if(vis[v]) continue;
        rt=0;sum=si[v];
        getrt(v,0);
        sol(rt);
    }
}
/*
3 1
2 3 4
1 2 0
1 3 1
*/
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    f[0]=1e9;sum=n;
    getrt(1,0);
    sol(rt);
    printf("%lld\n",ans);
}