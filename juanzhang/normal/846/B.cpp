#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
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
int n,k,M,A[50];

void solve(){
  cin>>n>>k>>M;
  int su=0;
  rep(i,1,k)cin>>A[i],su+=A[i];
  sort(A+1,A+k+1);
  int res=0;
  rep(i,0,n){
    if(1ll*i*su>M)break;
    int tp=(k+1)*i,cur=M-i*su;
    rep(j,1,k){
      if((n-i)*A[j]>cur){
        tp+=cur/A[j];
        break;
      }else{
        cur-=(n-i)*A[j],tp+=n-i;
      }
    }
    chkmax(res,tp);
  }
  cout<<res<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}