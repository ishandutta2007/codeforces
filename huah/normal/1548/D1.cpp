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
const int N=6e3+5,mod=1e9+7;
int n,x[N],y[N],g[N][N];
int cnt[N][4][4][4];
void sol(int cas)
{
  sc(n);
  rep(i,1,n) sc(x[i],y[i]);
  rep(i,1,n)
    rep(j,i+1,n) g[i][j]=g[j][i]=__gcd(abs(x[i]-x[j]),abs(y[i]-y[j]))%4;
  rep(i,1,n)
    rep(j,1,n)
    if(i!=j)
    cnt[i][x[j]%4][y[j]%4][g[i][j]]++;
  ll ans[2];
  ans[0]=ans[1]=0;
  rep(i,1,n)
    {
      rep(x1,0,3)
          rep(x2,0,3)
          if(x1%2==x2%2)
        rep(y1,0,3)
          rep(y2,0,3)
          if(y1%2==y2%2)
        rep(b1,0,3)
          rep(b2,0,3)
          if(b1%2==b2%2)
          {
            int b3=2;
            if(x1==x2&&y1==y2) b3=0;
            if((b1+b2+b3)%4==(((x1-x[i])*(y2-y[i])-(x2-x[i])*(y1-y[i]))%4+4)%4)
            {
              if(!(x1==x2&&y1==y2&&b1==b2)) ans[b1%2]+=cnt[i][x1][y1][b1]*cnt[i][x2][y2][b2];
              else ans[b1%2]+=cnt[i][x1][y1][b1]*(cnt[i][x1][y1][b1]-1);
            }
          }
    }
    out(ans[0]/6+ans[1]/2);
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("2.out", "w", stdout);
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