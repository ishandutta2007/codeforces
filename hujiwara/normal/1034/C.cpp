#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007ll;

void ad(long long &a,long long b)
{
  a=(a+b)%mod;
}

long long gcd(long long a,long long b)
{
  return b==0?a:gcd(b,a%b);
}

int main()
{
  int n;
  scanf("%d",&n);
  vector<long long> a(n);
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
  }
  vector<int> p(n);
  for(int i=1;i<n;i++){
    scanf("%d",&p[i]);
    p[i]--;
  }
  vector<long long> A=a;
  for(int i=n-1;i>0;i--){
    A[p[i]]+=A[i];
  }
  vector<long long> C(n+1,0);
  for(int i=1;i<n;i++){
    long long k=A[0]/gcd(A[0],A[i]);
    //printf("%d %lld %lld\n",i,A[i],k);
    if(k<=n){
      C[k]++;
    }
  }
  vector<long long> D(n+1,0);
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j+=i){
      D[j]+=C[i];
    }
  }
  long long ans=0;
  vector<long long> dp(n+1,0ll);
  dp[1]=1ll;
  for(int i=1;i<=n;i++){
    if(D[i]<i-1)continue;
    //printf("%d %lld\n",i,dp[i]);
    ad(ans,dp[i]);
    for(int j=2*i;j<=n;j+=i){
      if(D[j]>=j-1){
	ad(dp[j],dp[i]);
      }
    }
  }
  printf("%lld\n",ans);
}