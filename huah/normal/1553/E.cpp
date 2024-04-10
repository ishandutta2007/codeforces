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
const int N=3e5+5,mod=1e9+7;
int n,m,a[N],b[N],c[N];
bool vis[N];
bool check(int i)
{
  for(int j=1;j<=n;j++)
  {
    if(j>i) c[j-i]=a[j];
    else c[j-i+n]=a[j];
  }
  for(int i=1;i<=n;i++) vis[i]=false;
  int ans=0;
  for(int i=1;i<=n;i++)
  if(!vis[i])
  {
    int len=0;
    int now=i;
    while(!vis[now])
    {
      vis[now]=true;
      now=c[now];
      len++;
    }
    ans+=len-1;
  }
  return ans<=m;
}
void sol(int cas)
{
  sc(n,m);
  rep(i,0,n) b[i]=0;
  rep(i,1,n) sc(a[i]);
  rep(i,1,n)
  {
    int dis=i-a[i];
    if(dis<0) dis+=n;
    b[dis]++;
  }
  vector<int>ans;
  for(int i=0;i<n;i++)
  {
    if((n-b[i])-(n-b[i])/2<=m&&check(i)) ans.push_back(i);
  }
  printf("%d",ans.size());
  for(int x:ans) printf(" %d",x);
  printf("\n");
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