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
const int N=2e5+5,mod=998244353;
#define inf 0x3f3f3f3f
int n,a[N];
ll sum1[N],sum2[N],sum3[N];
ll getsum1(int l,int r){return sum1[r]-sum1[l-1];}
ll getsum2(int l,int r){return sum2[r]-sum2[l-1];}
ll getsum3(int l,int r){return sum3[r]-sum3[l-1];}
//1. c c c p p p
ll sol1()
{
  int ans=0;
  for(int i=1;i<=n;i++)
    if(getsum3(i+1,n)-getsum3(1,i)>0) ans++;
  return ans;
}
//2. c c c p p p c
ll sol2()
{
  int ans=0;
  for(int i=1;i<=n-2;i++)
    if(getsum3(i+1,n-1)-getsum3(1,i)-a[n]>0) ans++;
  return ans;
}
//3. c c c p c p c p p p p p p c
ll sol3()
{
  ll ans=0;
  for(int i=1;i<=n-4;i++)
  {
    int l=1,r=(n-2-i)/2,res=0;
    while(l<=r)
    {
      int m=(l+r)>>1;
      ll t=getsum1(i+1,i+2*m)-getsum2(i+1,i+2*m);
      if(i&1) t=-t;
      if(-getsum3(1,i)+t+getsum3(i+2*m+1,n-2)+a[n-1]-a[n]>0) res=m,l=m+1;
      else r=m-1;
    }
    ans=(ans+res)%mod;
  }
  return ans;
}
//4. c c c p c p c p p p p p p p
ll sol4()
{
  ll ans=0;
  for(int i=1;i<=n-3;i++)
  {
    int l=1,r=(n-1-i)/2,res=0;
    while(l<=r)
    {
      int m=(l+r)>>1;
      ll t=getsum1(i+1,i+2*m)-getsum2(i+1,i+2*m);
      if(i&1) t=-t;
      if(-getsum3(1,i)+t+getsum3(i+2*m+1,n)>0) res=m,l=m+1;
      else r=m-1;
    }
    ans=(ans+res)%mod;
  }
  return ans;
}
//5. p p p p p c c c c c 
ll sol5()
{
  int ans=0;
  for(int i=1;i<=n;i++)
    if(getsum3(1,i)-getsum3(i+1,n)>0) ans++;
  return ans;
}
//6. p c c c c p c p c p c p p p p p p c
ll sol6()
{
  ll ans=0,ss=a[1];
  for(int i=2;i<=n-2;i++)
  {
    ss-=a[i];
    int l=0,r=(n-2-i)/2,res=-1;
    while(l<=r)
    {
      int m=(l+r)>>1;
      ll t=getsum1(i+1,i+2*m)-getsum2(i+1,i+2*m);
      if(i&1) t=-t;
      if(ss+t+getsum3(i+2*m+1,n-1)-a[n]>0) res=m,l=m+1;
      else r=m-1;
    }
    ans=(ans+res+1)%mod;
  }
  return ans;
}
//7. p c c c c p c p c p c p p p p p p 
ll sol7()
{
  ll ans=0,ss=a[1];
  for(int i=2;i<=n-1;i++)
  {
    ss-=a[i];
    int l=0,r=(n-1-i)/2,res=-1;
    while(l<=r)
    {
      int m=(l+r)>>1;
      ll t=getsum1(i+1,i+2*m)-getsum2(i+1,i+2*m);
      if(i&1) t=-t;
      if(ss+t+getsum3(i+2*m+1,n)>0) res=m,l=m+1;
      else r=m-1;
    }
    ans=(ans+res+1)%mod;
  }
  return ans;
}
void sol(int cas)
{
  sc(n);
  rep(i,1,n)
  {
    sc(a[i]);
    sum1[i]=sum1[i-1]+((i&1)?a[i]:0);
    sum2[i]=sum2[i-1]+((i%2==0)?a[i]:0);
    sum3[i]=sum3[i-1]+a[i];
  }
  ll ans=sol1()+sol2()+sol3()+sol4()+sol5()+sol6()+sol7();
  ans%=mod;
  out(ans);
}
int main() {
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
re Alaysis new problem
*/