#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
int n,m;bool ok[1<<18],ano[1<<18];int chk[1<<18];ll wei[18],su[1<<18],dp[1<<18];
vi E[18];int go[18],ans[18];

void print(int S){
  static int now;
  if(!S)return;
  print(S^chk[S]),now++;
  rep(i,0,n-1)if(chk[S]>>i&1)ans[i]=now;
}

void solve(){
  cin>>n>>m;
  rep(i,1,m){
    int u=read()-1,v=read()-1,w=read();
    E[u].push_back(v),wei[u]+=w,wei[v]-=w;
  }
  rep(i,0,n-1)go[i]=1<<i;
  rep(T,1,n){
    rep(i,0,n-1)for(int j:E[i])go[i]|=go[j];
  }
  rep(S,0,(1<<n)-1){
    ok[S]=ano[S]=1;
    rep(i,0,n-1)if(S>>i&1)su[S]+=wei[i];
    rep(i,0,n-1)if((S>>i&1)&&(S&go[i])!=go[i])ok[S]=0;
    rep(i,0,n-1)if(S>>i&1)for(int j:E[i])if(S>>j&1)ano[S]=0;
  }
  rep(S,1,(1<<n)-1){
    ll&res=dp[S];res=1e18;
    if(!ok[S])continue;
    for(int sub=S;sub;sub=S&(sub-1))if(ok[S^sub]&&ano[sub]){
      ll x=dp[S^sub]+su[(1<<n)-1]-su[S^sub];
      if(res>x)res=x,chk[S]=sub;
    }
  }
  print((1<<n)-1);
//  printf("#%lld\n",dp[(1<<n)-1]);
  rep(i,0,n-1)printf("%d ",ans[i]);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}