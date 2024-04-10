#include <bits/stdc++.h>
using namespace std;

const long long mod=998244353ll;

void ad(long long &a,long long b){a+=b;a%=mod;}
void mn(long long &a,long long b){a+=mod-b;a%=mod;}
void ml(long long &a,long long b){a*=b;a%=mod;}
long long sq(long long a){return a*a%mod;}
long long pw(long long a,long long n)
{
  return n==0?1ll:sq(pw(a,n/2))*(n%2==1?a:1ll)%mod;
}
long long iv(long long a){return pw(a,mod-2);}

const int MSIZE=1000010;

long long inv[MSIZE],F[MSIZE],iF[MSIZE];

void prev(int N)
{
  inv[0]=0;
  inv[1]=1;
  for(int i=2;i<N;i++){
    inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  }
  F[0]=iF[0]=1;
  for(int i=1;i<N;i++){
    F[i]=F[i-1]*i%mod;
    iF[i]=iF[i-1]*inv[i]%mod;
  }
}

long long Ch(int i,int j)
{
  return F[i]*iF[j]%mod*iF[i-j]%mod;
}

int main()
{
  long long n;
  scanf("%lld",&n);
  prev(n+1);
  long long ans=0ll;
  for(int k=1;k<=n;k++){
    ad(ans,(k%2==1ll?1:mod-1ll)*2ll%mod*Ch(n,k)%mod*pw(3,k)%mod*pw(3,n*(n-k))%mod);
  }
  for(int a=1;a<=n;a++){
    long long x=pw(3,n-a);
    ad(ans,(a%2==1?1ll:mod-1ll)*3ll%mod*Ch(n,a)%mod*(pw((x+mod-1)%mod,n)+mod-pw(x,n))%mod);
  }
  printf("%lld\n",ans);
  return 0;
}