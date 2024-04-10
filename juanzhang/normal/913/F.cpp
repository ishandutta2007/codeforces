#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=2010,P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}
int n,p,pwp[maxn],pwq[maxn],dp[maxn],F[maxn],G[maxn][maxn];

int main(){
  int tpa,tpb;cin>>n>>tpa>>tpb;p=1ll*tpa*qp(tpb,P-2)%P;
  pwp[0]=pwq[0]=1;rep(i,1,n)pwp[i]=1ll*pwp[i-1]*p%P,pwq[i]=1ll*pwq[i-1]*(1-p+P)%P;
  rep(i,0,n){
    G[i][0]=1;
    rep(j,1,i)G[i][j]=(1ll*pwp[j]*G[i-1][j]+1ll*pwq[i-j]*G[i-1][j-1])%P;
  }
  rep(i,1,n){
    F[i]=1;
    rep(j,1,i-1)F[i]=(F[i]-1ll*G[i][j]*F[j]%P+P)%P;
  }
  rep(i,2,n){
    int tp=0;
    rep(j,1,i)tp=(tp+1ll*G[i][j]*F[j])%P;
    rep(j,1,i-1){
      dp[i]=(dp[i]+1ll*(dp[j]+dp[i-j]-(i-j)*(i-j-1)/2)*G[i][j]%P*F[j])%P;
    }
    dp[i]=1ll*(dp[i]+i*(i-1)/2)*qp(1-F[i]+P,P-2)%P;
  }
  cout<<dp[n]<<endl;
  return 0;
}