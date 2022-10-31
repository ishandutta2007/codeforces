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
long long inv(long long a){return pw(a,mod-2);}

int main()
{
  int n;
  long long a,b;
  scanf("%d%lld%lld",&n,&a,&b);
  long long p=a*inv(b)%mod,rp=(mod+1-p)%mod;
  long long Pp[3000],Prp[3000];
  Pp[0]=Prp[0]=1ll;
  for(int i=1;i<=n;i++){
    Pp[i]=Pp[i-1]*p%mod;
    Prp[i]=Prp[i-1]*rp%mod;
  }
  static long long dp1[3000][3000];
  dp1[1][1]=1ll;
  for(int i=2;i<=n;i++){
    for(int k=1;k<=i;k++){
      dp1[i][k]=((k<=i-1?dp1[i-1][k]*Pp[k]%mod:0)
		 +(k>1?dp1[i-1][k-1]*Prp[i-k]%mod:Prp[i-1]))%mod;
      //printf("%d %d %lld\n",i,k,dp1[i][k]*8%mod);
    }
  }
  static long long dp2[3000][3000];
  dp2[1][1]=1ll;
  for(int i=2;i<=n;i++){
    dp2[i][i]=1ll;
    for(int k=1;k<i;k++){
      dp2[i][k]=dp1[i][k]*dp2[k][k]%mod;
      mn(dp2[i][i],dp2[i][k]);
      //printf("%d %d %lld\n",i,k,dp2[i][k]*8%mod);
    }
  }
  static long long dp3[3000];
  dp3[1]=0;
  for(int i=2;i<=n;i++){
    dp3[i]=i*(i-1)/2;
    for(int k=1;k<i;k++){
      ad(dp3[i],dp2[i][k]*((dp3[k]+dp3[i-k]+mod-(i-k)*(i-k-1)/2)%mod)%mod);
    }
    ml(dp3[i],inv((1+mod-dp2[i][i])%mod));
    //printf("%d %lld %lld\n",i,dp3[i]*8%mod,dp2[i][i]*8%mod);
  }
  printf("%lld\n",dp3[n]);
  return 0;
}