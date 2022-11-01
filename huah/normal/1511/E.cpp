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
const int N=4e5+5,mod=998244353;
int n,m,tot;
ll p[N],ip[N],pre[N];
ll cal(int len,int dec)
{
  int s=tot-dec;
  /*
  \sum_{i=1}^(len-1) (i/2)*2^{s-i-1}

  */
  ll ans=1ll*pre[len-1]*p[s]%mod;
  ans=(ans+1ll*(len/2)*p[s-len]%mod)%mod;
  return ans;
}
void sol(int cas)
{
  p[0]=ip[0]=1;
  rep(i,1,N-1) p[i]=p[i-1]*2%mod,ip[i]=1ll*ip[i-1]*(mod-mod/2)%mod;
  rep(i,1,N-2) pre[i]=(pre[i-1]+1ll*(i/2)*ip[i+1]%mod)%mod;
  sc(n,m);
  // n=300000;m=1; 
  char s[n][m];
  int l1[n][m],l2[n][m];
  rep(i,0,n-1) sc(s[i]);
  // rep(i,0,n-1) s[i][0]='o';
  rep(i,0,n-1)
    rep(j,0,m-1)
  {
    l1[i][j]=l2[i][j]=0;
    if(s[i][j]=='o') tot++;
  }
  int ans=0;
  rep(i,0,n-1)
    rep(j,0,m-1)
  {
    if(s[i][j]=='o')
    {
      l1[i][j]=l2[i][j]=1;
      if(j) l1[i][j]+=l1[i][j-1];
      if(i) l2[i][j]+=l2[i-1][j];
      ans=(ans+cal(l1[i][j],j<m-1&&s[i][j+1]=='o'))%mod;
      ans=(ans+cal(l2[i][j],i<n-1&&s[i+1][j]=='o'))%mod;
    }
  }
  out(ans);
}
int main() 
{
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
*/