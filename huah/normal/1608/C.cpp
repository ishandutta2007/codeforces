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
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=5e5+5,mod=1e9+7;
struct node
{
  int a,b,id;
}a[N];
int n;
bool cmp1(node &x,node &y){return x.a<y.a;}
bool cmp2(node &x,node &y){return x.b<y.b;}
vector<int>e[N];
int id,dfn[N],low[N],f[N];
bool ins[N];
stack<int>s;
void dfs(int u)
{
  dfn[u]=low[u]=++id;
  s.push(u);
  ins[u]=true;
  for(int v:e[u])
  {
    if(!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
    else if(ins[v]) low[u]=min(low[u],dfn[v]);
  }
  if(low[u]==dfn[u])
  {
    while(s.top()!=u)
    {
      f[s.top()]=u;
      ins[s.top()]=false;
      s.pop();
    }
    f[u]=u;
    ins[u]=false;
    s.pop();
  }
}
bool del[N];
vector<pair<int,int>>vc;
int main()
{
  // freopen("1.in","r",stdin);
  // freopen("1.out", "w", stdout);
  int t;sc(t);
  while(t--)
  {
    sc(n);
    rep(i,1,n) sc(a[i].a),a[i].id=i;
    rep(i,1,n) sc(a[i].b);
    id=0;
    rep(i,1,n) e[i].clear(),dfn[i]=low[i]=del[i]=0;;
    vc.clear();
    sort(a+1,a+1+n,cmp1);
    rep(i,1,n-1)
      e[a[i+1].id].push_back(a[i].id),vc.push_back({a[i+1].id,a[i].id});
    sort(a+1,a+1+n,cmp2);
    rep(i,1,n-1)
      e[a[i+1].id].push_back(a[i].id),vc.push_back({a[i+1].id,a[i].id});
    rep(i,1,n) if(!dfn[i]) dfs(i);
    for(pair<int,int>x:vc)
      if(f[x.first]!=f[x.second]) del[f[x.second]]=true;
    rep(i,1,n)
      if(!del[f[i]]) putchar('1');
      else putchar('0');
    putchar('\n');
  }
}