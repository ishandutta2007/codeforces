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
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
#define inf 0x3f3f3f3f
const int N=1e6+5,mod=998244353;
int n,m,k,tot,p[N];
int a[2][N][2];
int b[N][2][2];
int c[2][2][2];
map<pair<int,int>,int>vis;
int y01,x01,z0,z1,z2,g[N];
void add(int x,int y,int v,int ad)
{
  x&=1;
  if(a[x][y][0]&&a[x][y][1]||a[x^1][y][0]&&a[x^1][y][1])
    y01--;
  if(a[x][y][0]&&a[x^1][y][0]||a[x][y][1]&&a[x^1][y][1])
    x01--;
  if(a[x][y][0]||a[x][y][1]||a[x^1][y][0]||a[x^1][y][1]) tot++;
  a[x][y][v]+=ad;
  c[x][y&1][v]+=ad;
  if(a[x][y][0]&&a[x][y][1]||a[x^1][y][0]&&a[x^1][y][1])
    y01++;
  if(a[x][y][0]&&a[x^1][y][0]||a[x][y][1]&&a[x^1][y][1])
    x01++;
  if(a[x][y][0]||a[x][y][1]||a[x^1][y][0]||a[x^1][y][1]) tot--;
}
void add2(int x,int y,int v,int ad)
{
  y&=1;
  if(g[x]==0) z0--;
  else if(g[x]==1) z1--;
  else z2--;
  b[x][y][v]+=ad;
  g[x]=0;
  if(!b[x][0][1]&&!b[x][1][0]) g[x]++;
  if(!b[x][0][0]&&!b[x][1][1]) g[x]++;
  if(g[x]==0) z0++;
  else if(g[x]==1) z1++;
  else z2++;
}
void sol(int cas)
{
  p[0]=1;
  rep(i,1,N-1) p[i]=(p[i-1]<<1)%mod;
  sc(n,m,k);
  tot=m;
  z2=n;
  rep(i,1,n) g[i]=2;
  rep(i,1,k)
  {
    int x,y,t;sc(x,y,t);
    int las=-1;
    if(vis.count({x,y}))
      las=vis[{x,y}];
    vis[{x,y}]=t;
    if(las!=-1) add(x,y,las,-1),add2(x,y,las,-1);
    if(t!=-1) add(x,y,t,1),add2(x,y,t,1);
    int ans=0;
    if(!y01&&!x01) ans=p[tot];
    if(!z0) ans=(ans+p[z2])%mod;
    if(!y01&&!x01&&!z0)
    /*
    01
    10
    */
    if(!c[0][0][1]&&!c[0][1][0]&&!c[1][0][0]&&!c[1][1][1]) ans--;
    /*
    10
    01
    */
    if(!c[0][0][0]&&!c[0][1][1]&&!c[1][0][1]&&!c[1][1][0]) ans--;
    ans=(ans+mod)%mod;
    out(ans);
  }
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
  return 0;
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/
/*
011010000111001
100101111000110

010101
010101
101010


10101010101
10101010101

010101
010101
*/