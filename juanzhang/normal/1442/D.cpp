#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read() {
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=3010;
int n,k;ll su[maxn];
vi A[maxn];

ll ans,dp[maxn],pst[15][maxn];
void divide(int l,int r,int lev){
  if(l==r){
    ll cur=0;
    chkmax(ans,dp[k]);
    rep(i,0,A[l].size()-1){
      cur+=A[l][i];
      chkmax(ans,dp[k-i-1]+cur);
    }
    return;
  }
  int mid=(l+r)/2;
  memcpy(pst[lev],dp,sizeof dp);
  rep(i,mid+1,r)per(j,k,A[i].size()){
    chkmax(dp[j],dp[j-A[i].size()]+su[i]);
  }
  divide(l,mid,lev+1);
  memcpy(dp,pst[lev],sizeof dp);
  rep(i,l,mid)per(j,k,A[i].size()){
    chkmax(dp[j],dp[j-A[i].size()]+su[i]);
  }
  divide(mid+1,r,lev+1);
  memcpy(dp,pst[lev],sizeof dp);
}

void solve() {
  cin>>n>>k;
  rep(i,1,n){
    int x=read();vi vec;
    while(x--)vec.push_back(read());
    for(int t:vec)if((int)A[i].size()<k)A[i].push_back(t),su[i]+=t;
  }
  divide(1,n,0);
  cout<<ans<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}