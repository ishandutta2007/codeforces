#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007ll;
void ad(long long &a,long long b){a+=b;a%=mod;}
void mn(long long &a,long long b){a+=mod-b;a%=mod;}
void ml(long long &a,long long b){a*=b;a%=mod;}
const int MSIZE=500;
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
  int K;
  scanf("%d",&K);
  prev(K+1);
  long long dp[410][410]={0};
  dp[1][0]=1ll;
  dp[1][1]=1ll;
  for(int i=2;i<=K;i++){
    for(int j=0;j<=K-i+1;j++){
      for(int a=0;a<=j;a++){
	ad(dp[i][j],dp[i-1][a]*dp[i-1][j-a]%mod*Ch(j,a)%mod);
      }
      for(int a=0;a<=j-1;a++){
	long long Y=Ch(j-1,a)*j%mod;
	ad(dp[i][j],dp[i-1][a]*dp[i-1][j-a-1]%mod*Y);
	ad(dp[i][j],dp[i-1][a+1]*dp[i-1][j-a-1]%mod*Y*2ll);
	ad(dp[i][j],dp[i-1][a]*dp[i-1][j-a]%mod*Y*2ll);
	ad(dp[i][j],dp[i-1][a+1]*dp[i-1][j-a]%mod*Y*2ll);
	ad(dp[i][j],dp[i-1][a+2]*dp[i-1][j-a-1]%mod*Y);
	ad(dp[i][j],dp[i-1][a]*dp[i-1][j-a+1]%mod*Y);
      }
    }
  }
  printf("%lld\n",dp[K][1]);
  return 0;
}