#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void iary(int *a,int l,int r){rep(i,l,r)sc(a[i]);}
void iary(ll *a,int l,int r){rep(i,l,r)sc(a[i]);}
void oary(int *a,int l,int r){rep(i,l,r)printf(i==r?"%d\n":"%d ",a[i]);}
void oary(ll *a,int l,int r){rep(i,l,r)printf(i==r?"%lld\n":"%lld ",a[i]);}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=3e5+5,mod=1e9+7;
int n,m,f[N];
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
vector<pair<int,int>>e[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
queue<int>sq;
bool vis[N],ing[N];
void sol1()
{
    vis[1]=true;
    ll ans=0;
    sq.push(1);
    vector<int>vc;
    rep(i,2,n) vc.push_back(i);
    int si=n-1;
    while(si)
    {
        if(sq.empty())
        {
            while(!q.empty()&&vis[q.top().second]) q.pop();
            assert(!q.empty());
            si--;
            vis[q.top().second]=true;
            sq.push(q.top().second);
            ans+=q.top().first;
            q.pop();
            continue;
        }
        int u=sq.front();sq.pop();
        vector<int>gc;
        for(pair<int,int>x:e[u])
        {
            q.push({x.second,x.first});
            if(!vis[x.first]) gc.push_back(x.first),ing[x.first]=true;
        }
        for(int x:vc)
        if(!ing[x]&&!vis[x])
        {
            si--;
            vis[x]=true;
            sq.push(x);
        }
        vc=gc;
        for(int x:gc) ing[x]=false;
    }
    out(ans);
}
struct node
{
    int u,v,w;
    bool operator<(const node&o)const
    {
        return w<o.w;
    }
};
void sol2()
{
    int dis[n+1][n+1];
    memset(dis,0,sizeof(dis));
    rep(i,1,n)
        for(pair<int,int>x:e[i])
        dis[i][x.first]=x.second;
    vector<node>vc;
    int xo=0;
    rep(i,1,n)
        rep(j,i+1,n)
        vc.push_back({i,j,dis[i][j]}),xo^=dis[i][j];
    sort(vc.begin(),vc.end());
    ll ans=1e18;
    int l=0,r=0;
    while(r+1<vc.size()&&vc[r+1].w==0) r++;
    for(int k=l;k<=r;k++)
    {
        ll res=0;
        rep(i,1,n) f[i]=i;
        for(int i=0;i<vc.size();i++)
            if(vc[i].w<=xo&&i!=k)
            {
                int u=getf(vc[i].u),v=getf(vc[i].v);
                if(u!=v)
                {
                    f[u]=v;
                    res+=vc[i].w;
                }
            }
        for(int i=k;i<=k;i++)
        {
            int u=getf(vc[i].u),v=getf(vc[i].v);
            if(u!=v)
            {
                f[u]=v;
                res+=xo;
            }
        }
        for(int i=0;i<vc.size();i++)
            if(vc[i].w>xo&&i!=k)
            {
                int u=getf(vc[i].u),v=getf(vc[i].v);
                if(u!=v)
                {
                    f[u]=v;
                    res+=vc[i].w;
                }
            }
        ans=min(ans,res);
    }
    out(ans);
}
void sol(int cas)
{
    sc(n,m);
    rep(i,1,m)
    {
        int u,v,w;sc(u,v,w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    if(1ll*n*(n-1)/2-m>=n) sol1();
    else sol2();
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
  while(t--)
  {    
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/