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
int n, m, A[305][305], ans[305][305];

void solve() {
  cin>>n>>m;
  rep(i,1,n){
    rep(j,1,m)A[i][j]=read(),ans[i][j]=(i>1)+(j>1)+(i<n)+(j<m);
  }
  rep(i,1,n){
    rep(j,1,m)if(A[i][j]>ans[i][j]){
      puts("NO");return;
    }
  }
  puts("YES");
  rep(i,1,n)rep(j,1,m)printf("%d%c",ans[i][j],"\n "[j<m]);
}

int main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}