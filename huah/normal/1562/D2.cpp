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
int n,q,a[N];
char s[N];
bool judge(int x,int y){return 1ll*x*y>=0;}
int sol(int l,int r)
{
  int ll=l,rr=r;
  while(ll<rr)
  {
    int m=(ll+rr)>>1;
    if(judge(a[m-1]-a[l-1]-a[r]+a[m],a[r]-a[l-1])) rr=m;
    else ll=m+1;
  }
  return ll;
}
void sol(int cas)
{
  sc(n,q);
  sc(s+1);
  rep(i,1,n) a[i]=s[i]=='+'?1:-1;
  for(int i=2;i<=n;i+=2) a[i]=-a[i];
  rep(i,1,n) a[i]+=a[i-1];
  while(q--)
  {
    int l,r;sc(l,r);
    if(a[r]==a[l-1]) out(0);
    else if((r-l)&1)
    {
      out(2);
      out(l,sol(l+1,r));
    }
    else
    { 
      out(1);
      out(sol(l,r));
    }
  }
}
int main()
{
  // freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
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