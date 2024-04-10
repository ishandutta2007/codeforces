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

typedef long long ll;
int n, A[10100], B[10100];

void solve() {
  cin >>n;
  int mn1=1e9,mn2=1e9;
  rep(i,1,n)A[i]=read(),chkmin(mn1,A[i]);
  rep(i,1,n)B[i]=read(),chkmin(mn2,B[i]);
  ll ans=0;
  rep(i,1,n){
    int x=A[i]-mn1,y=B[i]-mn2;
    ans+=x+y-min(x,y);
  }
  cout<<ans<<endl;
}

int main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}