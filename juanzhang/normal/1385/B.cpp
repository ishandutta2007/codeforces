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
bool vis[101];
int n,A[101],p[101];

void solve() {
  memset(vis,0,sizeof vis);
  cin>>n;
  int cur=0;
  rep(i,1,2*n){
    A[i]=read();
    if(!vis[A[i]]){
      vis[A[i]]=1,p[++cur]=A[i];
    }
  }
  rep(i,1,n)printf("%d%c",p[i],"\n "[i<n]);
}

signed main() {
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}