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
void iary(int *a,int l,int r){rep(i,l,r)sc(a[i]);}
void iary(ll *a,int l,int r){rep(i,l,r)sc(a[i]);}
void oary(int *a,int l,int r){rep(i,l,r)printf(i==r?"%d\n":"%d ",a[i]);}
void oary(ll *a,int l,int r){rep(i,l,r)printf(i==r?"%lld\n":"%lld ",a[i]);}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=1e3+5,mod=998244353;
int n,mx;
vector<int>e[N];
vector<int>qst;
int query()
{
    printf("? %d",qst.size());
    for(int x:qst) printf(" %d",x);
    qst.clear();
    printf("\n");
    fflush(stdout);
    int ans;scanf("%d",&ans);
    return ans;
}
int id,fa[N],d[N],dfn[N],p[N];
bool mark[N],del[N];
void dfs(int u,int p)
{
    fa[u]=p;
    dfn[u]=++id;
    for(int v:e[u])
        if(v!=p)
        dfs(v,u);
}
bool cmp(int x,int y){return dfn[x]<dfn[y];}
void qaq()
{
    int si=n-1;
    rep(i,2,n) p[i]=i;
    sort(p+2,p+1+n,cmp);
    int l=2,r=n;
    while(l<r)
    {
        int m=(l+r)>>1;
        memset(mark,false,sizeof(mark));
        for(int i=l;i<=m;i++) mark[p[i]]=mark[fa[p[i]]]=true;
        rep(i,1,n) if(mark[i]) qst.push_back(i);
        if(query()==mx) r=m;
        else l=m+1;
    }
    printf("! %d %d\n",p[l],fa[p[l]]);
}
void sol(int cas)
{
    sc(n);
    rep(i,1,n-1)
    {
        int u,v;sc(u,v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    del[1]=true;
    rep(i,1,n) qst.push_back(i);
    mx=query();
    dfs(1,0);
    qaq();
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