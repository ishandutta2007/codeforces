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
const int N=2e5+5,mod=1e9+7;
int n,m,a[N],low[1<<9];
bool cot[1<<9][1<<9],vis[1<<9][1<<9];
int xsum[1<<9][1<<9];
int up=(1<<9)-1;
struct node
{
  int l,r,id;
  bool operator<(const node&o)const
  {
    return l<o.l;
  }
}b[N];
char ans[N];
void dec()
{
  rep(i,0,up)
  if(low[i]==0)
  {
    rep(j,0,up-1) vis[i][j]=vis[i][j+1];
    vis[i][up]=0;
    cot[i][0]=vis[i][0];
    assert(xsum[i][0]==0);
    rep(j,1,up) xsum[i][j]=xsum[i][j-1]^(vis[i][j]?(j<<9):0),cot[i][j]=cot[i][j-1]^vis[i][j];
    low[i]=up;
  }
  else if(low[i]!=-1) low[i]--;
}
int query(int r)
{
  int sg=0;
  rep(i,0,up)
  if(low[i]!=-1)
  {
    int t=r-low[i];
    if(t>=0)
      sg^=xsum[i][t/(up+1)]^(cot[i][t/(up+1)]?low[i]:0);
  }
  return sg;
}
void sol(int cas)
{
  memset(low,-1,sizeof(low));
  sc(n,m);
  rep(i,1,n)
  { 
    sc(a[i]);
    vis[a[i]&up][a[i]>>9]^=1;
    low[a[i]&up]=a[i]&up;
    int x=a[i]>>9,y=a[i]&up;
  }
  rep(i,0,up)
    if(low[i]!=-1)
  {
    cot[i][0]=vis[i][0];
    rep(j,1,up)
     xsum[i][j]=xsum[i][j-1]^(vis[i][j]?(j<<9):0),cot[i][j]=cot[i][j-1]^vis[i][j];
  }
  int q;sc(q);
  rep(i,1,q) sc(b[i].l,b[i].r),b[i].id=i;
  sort(b+1,b+1+q);
  int cur=0;
  rep(i,1,q)
  {
    while(cur<b[i].l) cur++,dec();
    if(query(b[i].r-b[i].l)) ans[b[i].id]='A';
    else ans[b[i].id]='B';
  }
  rep(i,1,q) putchar(ans[i]);
  putchar('\n');
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  // scanf("%d",&t);
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