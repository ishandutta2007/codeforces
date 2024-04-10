#include<bits/stdc++.h>
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
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=5e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,a[N];
ll p[N];
ll cal()
{
  //0 1 2-> 1 2 3,-1 0 1 ,x=x+a[i] or x=x-a[i]
  //sum(ai/2) mod gcd(ai)==0
  //sum(ai)/2 mod gcd(ai)==0
  //gcd(ai)=t => ai/t%t=t/2
  ll ans=0;
  for(int i=1;i<30;i++)
  {
    int t=1<<i,x=0,y=0;
    for(int j=1;j<=n;j++)
      if(a[j]%t==0)
      {
        if(a[j]/2%t==0) y++;
        else x++;
      }
    if(x) ans=(ans+(p[x-1]+mod-1)*p[y])%mod;
  }
  return ans;
}
int main()
{
  p[0]=1;
  rep(i,1,N-1) p[i]=p[i-1]*2%mod;
  // freopen("1.in","r",stdin);
  int t=1;
  // sc(t);
  while(t--)
  {
    sc(n);
    rep(i,1,n) sc(a[i]);
    int m=0,z=0;
    rep(i,1,n)
      if(a[i]&1) z++;
      else a[++m]=a[i];
    n=m;
    ll ans=(p[z]+mod-1)*p[n]%mod;
    ans=(ans+cal())%mod;
    out(ans);
  }
}