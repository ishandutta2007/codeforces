#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=3010,P=1e9+7;
int n,m,inv_buf[maxn<<1],*inv=inv_buf+maxn;vector<int>E[maxn];

int sz[maxn],dp[maxn][maxn];
void dfs(int u){
  rep(i,1,n+1)dp[u][i]=1;
  for(int v:E[u]){
    dfs(v);
    rep(i,1,n+1){
      dp[u][i]=1ll*dp[u][i]*dp[v][i]%P;
    }
  }
  rep(i,1,n+1)dp[u][i]=(dp[u][i]+dp[u][i-1])%P;
}

int main(){
  cin>>n>>m,inv[1]=1,inv[-1]=P-1;
  rep(i,2,n){
    int f;cin>>f,E[f].push_back(i);
    inv[i]=1ll*(P-P/i)*inv[P%i]%P,inv[-i]=P-inv[i];
  }
  dfs(1);
  int ans=0;
  rep(i,1,n+1){
    int tp=1;
    rep(j,1,n+1)if(i!=j)tp=1ll*tp*(j-m+P)%P*inv[j-i]%P;
    ans=(ans+1ll*dp[1][i]*tp)%P;
  }
  cout<<ans<<endl;
  return 0;
}