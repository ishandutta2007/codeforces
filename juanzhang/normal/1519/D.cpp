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
const int maxn=5010;
int n,A[maxn],B[maxn];ll pre[maxn],suf[maxn],dp[3][maxn];

void solve(){
  cin>>n;
  rep(i,1,n)A[i]=read();
  rep(i,1,n)B[i]=read(),pre[i]=(pre[i-1]+1ll*A[i]*B[i]);
  per(i,n,1)suf[i]=suf[i+1]+1ll*A[i]*B[i];
  ll ans=pre[n];
  rep(i,1,n)dp[1][i]=1ll*A[i]*B[i];
  rep(i,1,n-1)dp[2][i]=1ll*A[i]*B[i+1]+1ll*A[i+1]*B[i],chkmax(ans,pre[i-1]+suf[i+2]+dp[2][i]);
  rep(len,3,n){
    int sel=len%3;
    memset(dp[sel],0,sizeof dp[sel]);
    ll*ano=dp[(len+1)%3];
    rep(i,1,n-len+1)dp[sel][i]=ano[i+1]+1ll*A[i]*B[i+len-1]+1ll*A[i+len-1]*B[i],chkmax(ans,pre[i-1]+suf[i+len]+dp[sel][i]);
//    rep(i,1,n-len+1){
//      printf("%lld ",dp[sel][i]);
//      ll tp=0;
//      rep(j,1,len)tp+=1ll*A[i+j-1]*B[i+len-j]
//    }
  }
  cout<<ans<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}