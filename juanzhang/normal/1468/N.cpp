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
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
  int c1=read(),c2=read(),c3=read();
  c1-=read(),c2-=read(),c3-=read();
  int a4=read(),a5=read();
  if(c1<0||c2<0||c3<0){
    puts("NO");return;
  }
  int t=min(c1,a4);
  c1-=t,a4-=t;
  t=min(c2,a5);
  c2-=t,a5-=t;
  if(c3<a4+a5){
    puts("NO");
    return;
  }
  puts("YES");
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}