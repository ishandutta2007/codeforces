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
const int N=1005;
int m,k,a[N][N],sum[N];
ll sum2[N];
ll getval(int i,int j,int k)
{
  return (sum2[k]-sum2[i])-(sum2[j]-sum2[i])*2;
}
void sol(int cas)
{
  sc(m,k);
  rep(i,1,k)
  {
    sum2[i]=sum[i]=0;
    rep(j,1,m) sc(a[i][j]),sum[i]+=a[i][j],sum2[i]+=1ll*a[i][j]*a[i][j];
  }
  ll d=0,ct=0;
  rep(i,1,k-1)
  {
    if(sum[i+1]-sum[i]==d) ct++;
    else if(ct) ct--;
    else d=sum[i+1]-sum[i],ct++;
  }
  rep(i,2,k)
  if(sum[i]-sum[i-1]!=d)
  {
    ll ps;
    if(i>3)
      ps=getval(i-3,i-2,i-1);
    else
      ps=getval(i+1,i+2,i+3);
    int ssum=sum[i-1]+d;
    rep(j,1,m)
    {
      sum2[i]=sum2[i]-1ll*a[i][j]*a[i][j]+1ll*(ssum-(sum[i]-a[i][j]))*(ssum-(sum[i]-a[i][j]));
      if(getval(i-1,i,i+1)==ps)
      {
        printf("%d %d\n",i-1,(ssum-(sum[i]-a[i][j])));
        fflush(stdout);
        break;
      }
      sum2[i]=sum2[i]+1ll*a[i][j]*a[i][j]-1ll*(ssum-(sum[i]-a[i][j]))*(ssum-(sum[i]-a[i][j]));
    }
    break;
  }
}
int main() {
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  // double ans=50*log2(50);
  // cout<<ans*100000<<endl;
  // return 0;
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