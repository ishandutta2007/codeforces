#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,m,G[70][70];

int A[270][270];

void solve(){
  memset(G,0,sizeof G);
  memset(A,0,sizeof A);
  cin>>n>>m;
  rep(i,1,m){
    int u,v,w;cin>>u>>v>>w;
    if(w!=-1)A[i][i]=1,A[i][m+1]=w%=3;
    G[u][v]=G[v][u]=i;
  }
  vector<tuple<int,int,int>>V;
  rep(i,1,n)rep(j,i+1,n)rep(k,j+1,n)if(G[i][j]&&G[j][k]&&G[k][i]){
    V.push_back(make_tuple(G[i][j],G[j][k],G[k][i]));
  }
  mt19937 Rnd(time(0));
  shuffle(V.begin(),V.end(),Rnd);
  for(auto p:V){
    static int cur[270];
    memset(cur,0,sizeof cur);
    cur[get<0>(p)]=1;
    cur[get<1>(p)]=1;
    cur[get<2>(p)]=1;
    bool asf=0;
    rep(i,1,m)if(cur[i]){
      if(!A[i][i]){
        memcpy(A[i],cur,sizeof cur);
        asf=1;
        break;
      }
      int tp=(3-cur[i]*A[i][i]%3)%3;
      rep(j,i,m+1)cur[j]=(cur[j]+tp*A[i][j])%3;
    }
    if(!asf&&cur[m+1])return puts("-1"),void();
  }
//  puts("---");
//  rep(i,1,m){
//    rep(j,1,m+1)printf("%d%c",A[i][j],"\n "[j<jend]);
//  }
//  puts("");
  per(i,m,1){
    if(!A[i][i]&&A[i][m+1])return puts("-1"),void();
    if(!A[i][i])A[i][i]=1,A[i][m+1]=1;
    if(A[i][i]==2)A[i][i]=1,A[i][m+1]=2*A[i][m+1]%3;
    per(j,i-1,1)A[j][m+1]=(A[j][m+1]-A[j][i]*A[i][m+1]%3+3)%3,A[j][i]=0;
  }
  rep(i,1,m)printf("%d%c",A[i][m+1]?A[i][m+1]:3,"\n "[i<m]);
}

int main(){
  int T;cin>>T;
  while(T--)solve();
  return 0;
}