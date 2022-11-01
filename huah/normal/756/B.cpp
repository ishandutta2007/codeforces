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
const int N=1e5+5,mod=998244353;
int n;
ll a[N],ans[N];
ll cost(int l,int r)
{
    ll ans=1ll*(r-l)*20;
    if(a[r]-a[l+1]+1<=90) ans=min(ans,50ll);
    if(a[r]-a[l+1]+1<=1440) ans=min(ans,120ll);
    return ans;
}
void sol(int cas)
{
    sc(n);ast(n,1,100000);
    rep(i,1,n) sc(a[i]),ast(a[i],0,1000000000);
    rep(i,2,n) assert(a[i]>a[i-1]);
    for(int i=1;i<=n;i++)
    {
        ans[i]=1e18;
        for(int j=max(0,i-1440);j<i;j++)
        ans[i]=min(ans[i],ans[j]+cost(j,i));
    }
    for(int i=n;i>1;i--)
    {
        assert(ans[i]>=ans[i-1]);
        ans[i]-=ans[i-1];
    }
    for(int i=1;i<=n;i++) out(ans[i]);
}
int main()
{
//   freopen("1.in", "r",stdin);
  // freopen("2.out", "w", stdout);
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