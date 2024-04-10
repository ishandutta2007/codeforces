#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,k;
double A[20],ans[20],dp[1<<20];

int main(){
  cin>>n>>k;int ct=0;rep(i,0,n-1)cin>>A[i],ct+=A[i]>1e-6;
  dp[0]=1,k=min(k,ct);
  rep(S,0,(1<<n)-1){
    double su=0;
    rep(i,0,n-1)if(S>>i&1)su+=A[i];
    rep(i,0,n-1)if(~S>>i&1)dp[S|1<<i]+=dp[S]*A[i]/(1-su);
    if(__builtin_popcount(S)==k)rep(i,0,n-1)if(S>>i&1)ans[i]+=dp[S];
  }
  rep(i,0,n-1)printf("%.10lf ",ans[i]);
  return 0;
}