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
const int MSIZE=1000;
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
  int n,a[300];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  prev(n+10);
  for(int i=0;i<n;i++){
    for(int j=2;j*j<=a[i];j++){
      while(a[i]%(j*j)==0){
	a[i]/=j*j;
      }
    }
  }
  sort(a,a+n);
  static long long dp[2][400]={0};
  bool f=0;
  int N=1;
  dp[f][0]=1ll,dp[f][1]=0ll;
  for(int t=0;t<n;){
    int c=1;
    while(t+c<n&&a[t+c]==a[t])c++;
    t+=c;
    //printf("%d\n",c);
    for(int i=0;i<=N+c;i++)dp[!f][i]=0ll;
    for(int i=0;i<=N;i++){
      //printf("%d %lld\n",i,dp[f][i]);
      for(int a=0;a<=c&&a<=i;a++){
	for(int b=0;a+b<=c&&b<=N-i;b++){
	  if(a==0&&b==0)continue;
	  //printf("%d %d %d\n",
	  ad(dp[!f][i-a+(c-a-b)],dp[f][i]*Ch(i,a)%mod*Ch(N-i,b)%mod*Ch(c-1,a+b-1)%mod*F[c]%mod);
	}
      }
    }
    N+=c;
    f=!f;
  }
  printf("%lld\n",dp[f][0]);
  return 0;
}