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
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=88;
int n,k,mod;
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int dp[N][N],f[N][N],all[N][N];
int p2[N*N];
int A(ll s,int n)
{
  ll ans=1;
  for(int i=1;i<=n;i++)
    ans=ans*s%mod,s--;
  return ans;
}
int c[N][N];
int C(int n,int m)
{
  if(n==m||m==0) return 1;
  if(m==1) return n;
  if(c[n][m]) return c[n][m];
  return c[n][m]=(C(n-1,m-1)+C(n-1,m))%mod;
}
int ok[N][N];
ll qpow(ll a,ll n)
{
  ll ans=1;
  for(;n;n>>=1,a=a*a%mod)
    if(n&1) ans=ans*a%mod;
  return ans;
}
int cal(int n,int m)
{
  if(ok[n][m]) return ok[n][m];
  return ok[n][m]=qpow(p2[m],n);
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  sc(n,k,mod);
  p2[0]=1;
  for(int i=1;i<N*N;i++) p2[i]=p2[i-1]*2%mod;
  for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
		{
      for(int h=0;h<=j;h++)
      {
        if((j-h)&1)
        { 
          add(all[i][j],mod-1ll*p2[i*h]*C(j,h)%mod);
          add(f[i][j],mod-1ll*A(p2[h]-1,i)*C(j,h)%mod);
        }
        else
        { 
          add(all[i][j],1ll*p2[i*h]*C(j,h)%mod);
          add(f[i][j],1ll*A(p2[h]-1,i)*C(j,h)%mod);
        }
      }
		}
  for(int i=1;i<=n;i++)
    for(int j=0;j<=k;j++)
    {
      for(int len=0;len<i;len++)
        for(int h=0;h<j;h++)
        {
          if((n&1)&&i==n&&len==i-1) continue;
          add(dp[i][j],1ll*(all[len][h]-dp[len][h]+mod)%mod*C(i,len)%mod*C(j,h)%mod*f[i-len][j-h]%mod*p2[(i-len)*h]%mod);
        }
    }
  int ans=0;
  for(int i=0;i<=k;i++) ans=(ans+1ll*(all[n][i]+mod-dp[n][i])*C(k,i)%mod)%mod;
  out(ans);
}