#include <bits/stdc++.h>
using namespace std;

const int MSIZE=5010;

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
  int k;
  scanf("%lld%d",&n,&k);
  prev(k+10);
  static long long S[5010][5010];
  for(int j=0;j<=k;j++){
    S[0][j]=(j==0?1:0);
  }
  for(int i=1;i<=k;i++){
    S[i][0]=0ll;
    for(int j=1;j<i;j++){
      S[i][j]=(j*S[i-1][j]+S[i-1][j-1])%mod;
      //printf("%d %d %lld\n",i,j,S[i][j]);
    }
    S[i][i]=1ll;
  }
  long long ans=0ll;
  long long q=pw(2,n),v2=inv[2];
  for(int s=0;s<=k;s++){
    ad(ans,S[k][s]*q%mod);
    ml(q,(n-s)*v2%mod);
  }
  printf("%lld\n",ans); 
  return 0;
}