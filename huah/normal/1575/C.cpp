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
const int N=2e5+5,mod=1e9+7;
int n,m,k,a[N],c[N];
ll vis[N],b[N];
int p[N],val[N];
int main()
{
  // freopen("1.in","r",stdin);
  // freopen("1.out", "w", stdout);
  sc(n,m,k);
  int sum=0;
  rep(i,1,n) sc(a[i]),a[i]%=k,sum=(sum+a[i])%k,c[i]=(c[i-1]+a[i])%k;
  if(sum==0)
  {
    int s=0;
    rep(i,1,n)
    {
      s=(s+a[i])%k;
      vis[s]=(vis[s]+m)%mod;
    }
  }
  else
  {
    p[0]=1;
    val[1]=0;
    int now=sum,tot=1;
    while(!p[now])
    {
      p[now]=++tot;
      val[tot]=now;
      now=(now+sum)%k;
    }
    assert(now==0);
    int s=0;
    rep(i,1,n)
    {
      s=(s+a[i])%k;
      b[1]=(b[1]+m/k)%mod;
      if(m%k)
      {
        b[p[s]]++;
        if(p[s]+m%k<=k) b[p[s]+m%k]=(b[p[s]+m%k]+mod-1)%mod;
        else
        {
          b[1]=(b[1]+1)%mod;
          b[p[s]+m%k-k]=(b[p[s]+m%k-k]+mod-1)%mod;
        }
      }
    }
    assert(k==tot);
    rep(i,1,k) b[i]=(b[i-1]+b[i])%mod,vis[val[i]]=b[i];
  }
  sum=1ll*sum*m%k;
  ll ans=0;
  int s=sum;
  rep(i,1,n)
  { 
    sum=(sum+a[i])%k;
    ans=(ans+vis[sum])%mod;
    vis[c[i]]=(vis[c[i]]+mod-1)%mod;
    vis[(s+c[i])%k]++;
  }
  ans*=m;
  s=1ll*s*m%k;
  if(s==0) ans-=1ll*n*m-1;
  ans=(ans%mod+mod)%mod;
  out(ans);
}
/*
cnt[i] => cnt[i-a[1]]
cnt[x]+=b[1]
*/