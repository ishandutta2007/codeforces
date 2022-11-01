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
const int N=205,mod=998244353;
int n,k,x[N],y[N],vis[N];
bool judge(int x1,int y1,int x2,int y2)
{
  bool f1=x2>=x1&&x2<=y1;
  bool f2=y2>=x1&&y2<=y1;
  return f1!=f2;
}
int tot,b[N];
void sol(int cas)
{
  memset(vis,false,sizeof(vis));
  sc(n,k);
  rep(i,1,k) sc(x[i],y[i]),vis[x[i]]=vis[y[i]]=1;
  tot=0;
  rep(i,1,2*n) if(!vis[i]) b[++tot]=i;
  rep(i,1,tot/2)
  {
    k++;
    x[k]=b[i];
    y[k]=b[i+tot/2];
  }
  rep(i,1,k)
    if(x[i]>y[i]) swap(x[i],y[i]);
  int ans=0;
  rep(i,1,k)
    rep(j,i+1,k)
    ans+=judge(x[i],y[i],x[j],y[j]);
  out(ans);
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
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