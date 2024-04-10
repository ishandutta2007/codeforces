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
const int N =5e5+5;
int n,a[N],dp[N][20],lg[N];
int gcd(int x,int y)
{
  if(y==0) return x;
  return gcd(y,x%y);
}
int query(int l,int r)
{
  int k=lg[r-l+1];
  return gcd(dp[l][k],dp[r-(1<<k)+1][k]);
}
bool judge(int m)
{
  int g=query(1,m);
  for(int i=2;i<=n;i++)
    if(query(i,i+m-1)!=g) return false;
  return true;
}
void sol(int cas)
{
  sc(n);
  rep(i,1,n) sc(a[i]),a[i+n]=a[i];
  rep(i,1,2*n) dp[i][0]=a[i];
  for(int i=1;1<<i<=2*n;i++)
    for(int j=1;j+(1<<i)-1<=2*n;j++)
    dp[j][i]=gcd(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
  int l=1,r=n;
  while(l<r)
  {
    int m=(l+r)>>1;
    if(judge(m)) r=m;
    else l=m+1;
  }
  out(r-1);
}
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  for(int i=1;i<N;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i),lg[i-1]--;
  srand(time(0));
  int t,cas=0;scanf("%d",&t);
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