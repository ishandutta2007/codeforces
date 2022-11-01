#pragma GCC optimize(2)
#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
void iary(int *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void iary(ll *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void oary(int *a,int n){rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);}
void oary(ll *a,int n){rep(i,1,n) printf(i==n?"%lld\n":"%lld ",a[i]);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const int N=2e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,p[N],f[N];
char s[N];
int main()
{
  // freopen("1.in","r",stdin);
  // freopen("2.out","w",stdout);
  sc(s+1);n=strlen(s+1);ast(n,1,100000);
  rep(i,1,n) ast(s[i],'0','9');
  ast(s[1],'1','9');
  p[0]=1;
  rep(i,1,N-1) p[i]=1ll*p[i-1]*10%mod;
  f[0]=1;
  rep(i,1,N-1) f[i]=(f[i-1]+p[i])%mod;
  int sum=0,ans=0;
  rep(i,1,n-1)
  {
    sum=(1ll*sum*10+s[i]-'0')%mod;
    ans=(ans+1ll*sum*f[n-i-1])%mod;
  }
  sum=0;
  nep(i,n,2)
  {
    sum=(sum+1ll*(s[i]-'0')*p[n-i]%mod)%mod;
    ans=(ans+1ll*sum*(i-1)%mod)%mod;
  }
  out(ans);
}