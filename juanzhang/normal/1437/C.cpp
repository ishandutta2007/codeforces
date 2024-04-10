#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read() {
  #define nc getchar()
  int x=0;char c=nc;
  while(c<48)c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n,A[205],dp[405][205];

void solve() {
  memset(dp,0x3f,sizeof dp);
  cin>>n;
  int ans=1e9;
  rep(i,1,n){
    A[i]=read();
  }
  sort(A+1,A+n+1);
  dp[0][0]=0;
  rep(i,1,n+n){
    rep(j,0,n){
      dp[i][j]=dp[i-1][j];
      if(j)chkmin(dp[i][j],dp[i-1][j-1]+abs(A[j]-i));
    }
    chkmin(ans,dp[i][n]);
  }
  printf("%d\n",ans);
}

signed main() {
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}