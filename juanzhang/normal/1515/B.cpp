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

void solve(){
  int n;
  cin>>n;
  if(n&1){
    return puts("NO"),void();
  }else{
    int s=n/2;
    int x=sqrt(s),y=sqrt(s/2);
    puts(x*x==s||(s%2==0&&y*y==s/2)?"YES":"NO");
  }
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}