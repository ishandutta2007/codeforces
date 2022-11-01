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

long long inv[200010],F[200010],iF[200010];

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
  int h,w,n;
  scanf("%d%d%d",&h,&w,&n);
  prev(h+w+1);
  pair<int,int> P[2001];
  for(int i=0;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    P[i]=make_pair(a-1,b-1);
  }
  P[n]=make_pair(h-1,w-1);
  sort(P,P+n+1);
  long long dp[2001];
  for(int i=0;i<=n;i++){
    int a=P[i].first,b=P[i].second;
    dp[i]=Ch(a+b,a);
    for(int j=0;j<i;j++){
      if(P[j].second<=b){
	mn(dp[i],dp[j]*Ch(a-P[j].first+b-P[j].second,a-P[j].first)%mod);
      }
    }
    //printf("%d %d %lld\n",a,b,dp[i]);
  }
  printf("%lld\n",dp[n]);
  return 0;
}