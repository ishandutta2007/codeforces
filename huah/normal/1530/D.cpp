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
const int N=5e5+5,mod=998244353;
int n,a[N],b[N];
bool vis[N];
vector<int>v;
void sol(int cas)
{
  sc(n);
  rep(i,1,n) sc(a[i]),vis[i]=false,b[i]=0;
  rep(i,1,n)
  if(!vis[a[i]])
  {
    vis[a[i]]=true;
    b[i]=a[i];
  }
  rep(i,1,n) if(!vis[i]) v.push_back(i);
  rep(i,1,n)
  if(!b[i])
  {
    if(v[0]!=i) swap(v[0],v[v.size()-1]);
    b[i]=v.back();
    v.pop_back();
  }
  nep(i,n,1)
  if(b[i]==i)
  {
    bool flag=false;
    for(int j=1;j<=n;j++)
    if(j!=i&&b[j]!=a[j])
    {
      swap(b[i],b[j]);
      flag=true;
      break;
    }
    if(!flag)
    {
      for(int j=1;j<=n;j++)
      if(i!=j&&b[j]==a[i])
      {
        swap(b[j],b[i]);
        break;
      }
    }
    break;
  }
  int ans=0;
  rep(i,1,n) ans+=a[i]==b[i];
  printf("%d\n",ans);
  rep(i,1,n) printf(i==n?"%d\n":"%d ",b[i]);
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