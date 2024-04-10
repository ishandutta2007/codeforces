#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,dp[200010][2];char S[200010];

int main(){
  int T;cin>>T;while(T--){
    scanf("%s",S+1);
    n=strlen(S+1);
    long long ans=0;
    rep(i,1,n){
      dp[i][0]=dp[i][1]=0;
      if(S[i]=='0'){
        dp[i][0]=dp[i-1][1]+1;
      }else if(S[i]=='1'){
        dp[i][1]=dp[i-1][0]+1;
      }else{
        dp[i][0]=dp[i-1][1]+1;
        dp[i][1]=dp[i-1][0]+1;
      }
      ans+=max(dp[i][0],dp[i][1]);
    }
    cout<<ans<<endl;
  }
  return 0;
}