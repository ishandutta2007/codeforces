#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
int n,m,q,G[13];ll dp[1<<13|5][13];
struct Arrow{
  int u,v,anc;
}Q[105];

int main(){
  int tpq;cin>>n>>m>>tpq;
  rep(i,1,m){
    int u,v;cin>>u>>v,u--,v--;G[u]|=1<<v,G[v]|=1<<u;
  }
  rep(i,0,tpq-1){
    int u,v,anc;cin>>u>>v>>anc;u--,v--,anc--;
    if(u==v&&u!=anc)return puts("0"),0;
    if(u!=v)Q[q++]={u,v,anc};
  }
  int all=(1<<n)-1;
  rep(i,0,n-1)dp[1<<i][i]=1;
  rep(S,0,all)if(__builtin_popcount(S)>1)rep(i,0,n-1)if((S>>i&1)&&((~S&1)||!i)){
    int tp=S^(1<<i),lw=tp&-tp;
    for(int T=tp;T;T=(T-1)&tp)if((T&lw)==lw)rep(j,0,n-1)if(T>>j&1){
      if(((T|1<<i)&G[j])!=G[j])continue;
      if((T&G[i])&&(T&G[i])!=(1<<j))continue;
      bool flg=1;
      rep(_,0,q-1){
        if((T>>Q[_].anc&1)&&((S^T)>>Q[_].u&1)&&((S^T)>>Q[_].v&1)){
          flg=0;break;
        }
        if(((tp^T)>>Q[_].anc&1)&&((T|1<<i)>>Q[_].u&1)&&((T|1<<i)>>Q[_].v&1)){
          flg=0;break;
        }
        if(((S^T)>>Q[_].u&1)&&(T>>Q[_].v&1)&&Q[_].anc!=i){
          flg=0;break;
        }
        if(((S^T)>>Q[_].v&1)&&(T>>Q[_].u&1)&&Q[_].anc!=i){
          flg=0;break;
        }
      }
      if(!flg)continue;
      dp[S][i]+=dp[S^T][i]*dp[T][j];
    }
  }
  cout<<dp[all][0]<<endl;
  return 0;
}