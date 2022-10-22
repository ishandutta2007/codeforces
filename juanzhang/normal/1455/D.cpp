#include <bits/stdc++.h>
using namespace std;

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
int n,A[505],flg[505];

bool pd(){rep(i,1,n-1)if(A[i]>A[i+1])return 0;return 1;}
void solve(){
  int x,ct=0;
  cin>>n>>x;
  rep(i,1,n)A[i]=read();
  while(!pd()){
    int ps=-1;
    rep(i,1,n)if(A[i]>x){
      swap(A[i],x),ps=i,ct++;break;
    }
    if(ps==-1)break;
  }
  cout<<(pd()?ct:-1)<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}