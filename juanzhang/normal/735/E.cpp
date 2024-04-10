#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int P=1e9+7;
int n,k;vector<int>E[105];

int dp[105][25][25];

void dfs(int u,int f){
  static int tmp[25][25];
  dp[u][k][0]=dp[u][0][k]=1;
  for(int v:E[u])if(v!=f){
    dfs(v,u);
    memset(tmp,0,sizeof tmp);
    rep(i1,0,k)rep(j1,0,k){
      int x=dp[u][i1][j1];if(!x)continue;
      rep(i2,0,k)rep(j2,0,k){
        int y=dp[v][i2][j2];if(!y)continue;
        int j3=-1;
        if(j2<k&&i1+j2+1>k)j3=j2+1;
        if(j1<k&&j1+i2+1>k)j3=max(j3,j1);
        if(j3==k)j3=-1;
        else if(j3==-1)j3=k;
        int i3=min(min(i1,i2+1),k);
        if(j3!=-1)(tmp[i3][j3]+=1ll*x*y%P)%=P;
      }
    }
    memcpy(dp[u],tmp,sizeof tmp);
  }
}

int main(){
  cin>>n>>k;rep(i,2,n){
    int u,v;scanf("%d%d",&u,&v);E[u].push_back(v),E[v].push_back(u);
  }
  dfs(1,0);int ans=0;rep(i,0,k)ans=(ans+dp[1][i][k])%P;cout<<ans<<endl;
  return 0;
}