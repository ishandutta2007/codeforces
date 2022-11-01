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
const int N=5e3+5;
int n;
ll a[N],b[N],sum[N][N],s[N];
void sol(int cas)
{
  sc(n);
  rep(i,1,n) sc(a[i]);
  rep(i,1,n) sc(b[i]);
  for(int i=1;i<=n;i++)
    for(int j=1,k=i;j<=n;j++)
    {
      if(k==0) k=n;
      sum[i][j]+=sum[i][j-1]+b[j]*a[k];
      k--;
    }
  rep(i,1,n) s[i]+=s[i-1]+a[i]*b[i];
  ll ans=s[n];
  rep(i,1,n)
    rep(j,i,n)
    {
      ll res=s[n]-(s[j]-s[i-1]);
      int t=j+i-1;
      if(t>n) t-=n;
      res+=sum[t][j]-sum[t][i-1];
      ans=max(ans,res);
    }
  out(ans);
}
int main() {
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
re Alaysis new problem
*/