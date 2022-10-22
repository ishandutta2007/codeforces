#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

#define int long long

typedef long long ll;
typedef pair <int, int> pii;

void solve() {
  int n=read(),m=read();
  int x=read(),y=read();
  int vx=read(),vy=read();
  if(vx>vy)swap(vx,vy),swap(x,y);
  int res = 0;
  rep(i,0,x){
    if(i*vx>n)continue;
    int cnt=min((n-i*vx)/vy,y);
    int cc=min(x-i,m/vx);
    int tmp=i+cnt+cc+min(y-cnt,(m-cc*vx)/vy);
    chkmax(res,tmp);
  }
  cout<<res<<endl;
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}