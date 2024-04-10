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
int n,A[114514],B[114514];

void solve(){
  cin>>n;int su=0;
  rep(i,1,n){
    A[i]=read();
    B[i]=A[i]/2,su+=B[i];
  }
  rep(i,1,n){
    if(su<0&&B[i]*2<A[i])B[i]++,su++;
    if(su>0&&B[i]*2>A[i])B[i]--,su--;
    printf("%d\n",B[i]);
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}