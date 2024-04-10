#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
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
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=2e3+5,mod=998244353;
int n,m,a[N],b[N];
vector<int>e[N];
bool vis[N],vv[N];
int sp,pre[N];
vector<int>vc;
bool dfs(int u,int fa,int p)
{
    vv[u]=true;
    for(int v:e[u])
    if(!vis[v]&&v!=fa&&p>a[v])
    {
        if(vv[v])
        {
            int x=u;
            while(!vis[x])
            {
                vis[x]=true;
                vc.push_back(x);
                sp+=b[x];
                sp=min(sp,1000000001);
                x=pre[x];
            }
            x=v;
            while(!vis[x])
            {
                vis[x]=true;
                vc.push_back(x);
                sp+=b[x];
                sp=min(sp,1000000001);
                x=pre[x];
            }
            return true;
        }
        pre[v]=u;
        if(dfs(v,u,min(1000000001,p+b[v]))) return true;
    }
    else if(vis[v]&&v!=fa&&!vis[u])
    {
        int x=u;
        while(!vis[x])
        {
            vis[x]=true;
            vc.push_back(x);
            sp+=b[x];
            sp=min(sp,1000000001);
            x=pre[x];
        }
        return true;
    }
    return false;
}
bool judge(int p)
{
    rep(i,1,n) vis[i]=false;
    vc.clear();
    vis[1]=true;
    vc.push_back(1);
    bool flag=true;
    while(flag)
    {
        flag=false;
        rep(i,1,n) vv[i]=false;
        for(int x:vc)
        if(dfs(x,0,p))
        {
            flag=true;
            p+=sp;
            p=min(p,1000000001);
            sp=0;
            break;
        }
    }
    rep(i,1,n)
        if(!vis[i]) return false;
    return true;
}
void sol(int cas)
{
    sc(n,m);
    rep(i,2,n) sc(a[i]);
    rep(i,2,n) sc(b[i]);
    rep(i,1,n) e[i].clear();
    rep(i,1,m)
    {
        int u,v;sc(u,v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int l=1,r=1e9;
    r++;
    while(l<r)
    {
        int m=(l+r)>>1;
        if(judge(m)) r=m;
        else l=m+1;
    }
    out(r);
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  scanf("%d",&t);
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