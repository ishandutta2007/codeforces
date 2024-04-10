#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  bool f=0;int x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
int E[105][105],ct[105],vis[105];

void solve(){
  int n;
  cin>>n;
  if(n&1){
    rep(i,1,n){
      rep(j,i+1,n){
        int x=j-i<=n/2;
        printf("%d ",x?1:-1);
      }
    }
  }else{
    rep(i,1,n){
      rep(j,i+1,n){
        int x=i%2==1&&j==i+1?0:(i%2)!=(j%2)?1:-1;
        printf("%d ",x);
      }
    }
  }
  puts("");
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}