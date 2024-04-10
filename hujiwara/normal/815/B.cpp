#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007ll;
void ad(long long &a,long long b){a+=b;a%=mod;}
void mn(long long &a,long long b){a+=mod-b;a%=mod;}
void ml(long long &a,long long b){a*=b;a%=mod;}
long long sq(long long a){return a*a%mod;}
long long pw(long long a,long long n)
{
  return n==0?1ll:sq(pw(a,n/2))*(n%2==1?a:1ll)%mod;
}
long long iv(long long a){return pw(a,mod-2);}
const int MSIZE=300000;
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
  int n;
  scanf("%d",&n);
  prev(n+10);
  static long long a[200000];
  for(int i=0;i<n;i++){
    scanf("%lld",a+i);
  }
  long long ret=0ll;
  if(n%4==1){
    for(int t=0;t<=(n-1)/2;t++){
      long long C=Ch((n-1)/2,t);
      ad(ret,a[2*t]*C%mod);
    }
  }
  else if(n%4==0){
    for(int t=0;t<=2*(n/4-1);t++){
      long long C=Ch(2*(n/4-1),t);
      ad(ret,a[2*t]*C%mod);
      mn(ret,a[2*t+1]*C%mod);
      ad(ret,a[2*t+2]*C%mod);
      mn(ret,a[2*t+3]*C%mod);
    }
  }
  else if(n%4==2){
    for(int t=0;t<=(n-2)/2;t++){
      long long C=Ch((n-2)/2,t);
      ad(ret,a[2*t]*C%mod);
      ad(ret,a[2*t+1]*C%mod);
    }
  }
  else if(n%4==3){
    for(int t=0;t<=(n-3)/2;t++){
      long long C=Ch((n-3)/2,t);
      ad(ret,a[2*t]*C%mod);
      ad(ret,2*a[2*t+1]*C%mod);
      mn(ret,a[2*t+2]*C%mod);
    }
  }
  printf("%lld\n",ret);
  return 0;
}