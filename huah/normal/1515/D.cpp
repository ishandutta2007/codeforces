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
const int N=2e5+5;
int n,l,r,le[N],ri[N];
void sol(int cas)
{
  sc(n,l,r);
  rep(i,1,n) le[i]=ri[i]=0;
  rep(i,1,l)
  {
    int c;sc(c);
    le[c]++;
  }
  rep(i,1,r)
  {
    int c;sc(c);
    ri[c]++;
  }
  le[0]=ri[0]=0;
  int ans=0,ler=0,rir=0;
  rep(i,1,n)
  {
    int x=min(le[i],ri[i]);
    le[i]-=x;ri[i]-=x;
    ler+=le[i]/2;
    rir+=ri[i]/2;
    le[0]+=le[i];
    ri[0]+=ri[i];
  }
  int x=min(le[0],ri[0]);
  ans+=x;
  le[0]-=x;ri[0]-=x;
  ler*=2;
  rir*=2;
  if(le[0]<=ler) ans+=le[0]/2;
  else ans+=ler/2+(le[0]-ler);
  if(ri[0]<=rir) ans+=ri[0]/2;
  else ans+=rir/2+(ri[0]-rir);
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