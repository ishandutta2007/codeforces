#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,A[3010],pre[3010],pos[3010],dp[3010][3010];

int main(){
  int T;cin>>T;while(T--){
    cin>>n;
    rep(i,1,n)pos[i]=0;
    rep(i,1,n){
      cin>>A[i],pre[i]=pos[A[i]],pos[A[i]]=i;
    }
    rep(len,2,n){
      rep(i,1,n-len+1){
        int j=i+len-1;
        dp[i][j]=dp[i][j-1]+1;
        for(int k=pre[j];k>=i;k=pre[k]){
          dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
      }
    }
    cout<<dp[1][n]<<endl;
  }
  return 0;
}