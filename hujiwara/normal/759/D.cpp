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
long long inv(long long a){return pw(a,mod-2);}

const int MN=5000;

int main()
{
  int n;
  scanf("%d",&n);
  char s[MN+10];
  scanf("%s",s);
  static long long dp[2][MN]={0};
  bool b=0;
  int q[26];
  for(int c=0;c<26;c++){
    q[c]=-1;
  }
  for(int j=0;j<n;j++){
    int c=s[j]-'a';
    if(q[c]==-1){
      q[c]=j;
    }
  }
  for(int c=0;c<26;c++){
    if(q[c]!=-1){
      ad(dp[b][q[c]],1ll);
    }
  }
  for(int i=1;i<n;i++){
    for(int k=0;k<n;k++){
      //printf("%d %d %lld\n",i-1,k,dp[b][k]);
      dp[!b][k]=0ll;
    }
    static int S[MN+1];
    S[0]=0;
    for(int j=0;j<n;j++){
      S[j+1]=(S[j]+dp[b][j])%mod;
    }
    int C[26];
    for(int c=0;c<26;c++){
      C[c]=-1;
    }
    for(int j=0;j<i;j++){
      int c=s[j]-'a';
      long long T=(S[j+1]+mod-S[C[c]+1])%mod;
      ad(dp[!b][j],T);
      C[c]=j;
    }
    int D[26];
    for(int c=0;c<26;c++){
      D[c]=i-1;
    }
    for(int j=i;j<n;j++){
      int c=s[j]-'a';
      ad(dp[!b][j],(S[j+1]+mod-S[D[c]+1])%mod);
      D[c]=j;
    }
    int p[26],q[26];
    for(int c=0;c<26;c++){
      p[c]=-1;
      q[c]=-1;
    }
    for(int j=i-1;j>=0;j--){
      int c=s[j]-'a';
      if(p[c]==-1){
	p[c]=j;
      }
    }
    for(int j=i;j<n;j++){
      int c=s[j]-'a';
      if(q[c]==-1){
	q[c]=j;
      }
    }
    for(int c=0;c<26;c++){
      if(q[c]!=-1){
	ad(dp[!b][q[c]],(S[i]+mod-S[p[c]+1])%mod);
      }
    }
    b=!b;
  }
  long long ans=0ll;
  for(int i=0;i<n;i++){
    ad(ans,dp[b][i]);
  }
  printf("%lld\n",ans);
  return 0;
}