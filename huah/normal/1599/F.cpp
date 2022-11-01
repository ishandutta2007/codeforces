#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2e5+5,mod=1e9+7;
typedef long long ll;
int n,q,a[N];
ll s1[N],s2[N];
ll qpow(ll a,ll n)
{
  ll ans=1;
  for(;n;n>>=1,a=a*a%mod)
  if(n&1) ans=ans*a%mod;
  return ans;
}
const int inv6=qpow(6,mod-2);
ll sum2(ll n){return n*(n+1)%mod*(2*n+1)%mod*inv6%mod;}
ll sum(ll n){return n*(n+1)/2%mod;}
int main()
{
  // freopen("1.in","r",stdin);
    scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) s1[i]=(s1[i-1]+a[i])%mod;
    rep(i,1,n) s2[i]=(s2[i-1]+1ll*a[i]*a[i]%mod)%mod;
    while(q--)
    {
      int l,r,d;scanf("%d%d%d",&l,&r,&d);
      int len=r-l+1;
      ll s=1ll*d*sum(len-1)%mod;
      s=(s1[r]-s1[l-1]+mod-s+mod)%mod;
      s=s*qpow(len,mod-2)%mod;
      //s^2+(s+d)^2+...+(s+(len-1)*d)^2
      //s^2*len+2sd+d^2+4sd+4d^2+8sd+9d^2
      ll res=(s*s%mod*len%mod+2ll*d%mod*s%mod*sum(len-1)%mod)%mod;
      //res+=d^2+(2d)^2+(4d^2)+..+((len-1)d)^2=d^2(1+2^2+...+(len-1)^2)
      res=(res+1ll*d*d%mod*sum2(len-1)%mod)%mod;
      ll ret=(s2[r]-s2[l-1]+mod)%mod;
      printf(res==ret?"Yes\n":"No\n");
    }
}