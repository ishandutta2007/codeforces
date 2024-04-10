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
const int N=10005,mod=998244353;
const double pi=3.0/4;
int n,m,wa[N],waa;
char s[N];
double p[N],w[N];
void sol(int cas)
{
  p[0]=1;
  rep(i,1,N-1) p[i]=p[i-1]*pi;
  sc(n,m);
  int lasguess=-1;
  mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
  rep(k,1,m)
  {
    sc(s+1);
    char guess;
    int mn=99999;
    rep(i,1,n) mn=min(mn,wa[i]);
    double ps=0;
    rep(i,1,n) w[i]=p[wa[i]-mn],ps+=w[i];
    ps=uniform_real_distribution<double>(0,ps)(gen);
    rep(i,1,n)
    {
      if(i==n||ps<w[i])
      {
        guess=s[i];
        break;
      }
      ps-=w[i];
    }
    printf("%c\n",guess);
    fflush(stdout);
    int answer;scanf("%d",&answer);
    rep(i,1,n) wa[i]+=answer!=s[i]-'0';
    waa+=answer!=guess-'0';
  }
  int mn=99999;
  rep(i,1,n) mn=min(mn,wa[i]);
  // cout<<waa<<' '<<mn*1.3+100<<endl;
  assert(waa<=mn*1.3+100);
}
int main() 
{
  // freopen("1.in", "r", stdin);
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
*/