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
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
const double eps=1e-8;
double c,m,p,v;
map<pair<int,int>,double>vis;
double Dp(double c,double m)
{
  int x=c*100000000ll,y=m*100000000ll;
  if(vis.count({x,y})) return vis[{x,y}];
  double ans=1;
  if(c>0)
  {
    ans+=c*Dp(max(double(0),c-v),m+(m>eps?min(c,v)/2:0));
  }
  if(m>0)
  {
    ans+=m*Dp(c+(c>eps?min(m,v)/2:0),max(double(0),m-v));
  }
  return vis[{x,y}]=ans;
}
void sol(int cas)
{
  // printf("Case #%d: ",cas);
  scanf("%lf%lf%lf%lf",&c,&m,&p,&v);
  vis.clear();
  printf("%.12f\n",Dp(c,m));
}
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  int t,cas=0;scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
}