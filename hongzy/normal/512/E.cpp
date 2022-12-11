#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1024;
int n;
struct node {
  int x, y;
};
struct space {
  bool G[N][N], rev;
  void read() {
    rep(i, 1, n) G[i][i == n ? 1 : i + 1] = G[i][i == 1 ? n : i - 1] = 1;
    int x, y;
    rep(i, 1, n - 3) {
      scanf("%d%d", &x, &y);
      G[x][y] = G[y][x] = 1;
    }
  }
  vector<node> v;
  void solve() {
    while(1) {
      int la = 2, a = -1, b = -1;
      rep(i, 3, n) if(G[1][i]) {
        if(la < i - 1) { a = la; b = i; break ; }
        la = i;
      }
      if(a == -1) break ;
      int c = 1;
      rep(i, 2, n) if(G[i][a] && G[i][b]) { c = i; break ; }
      v.pb(rev ? node{1, c} : node{a, b});
      G[a][b] = G[b][a] = 0;
      G[1][c] = G[c][1] = 1;
    }
    if(rev) {
      reverse(v.begin(), v.end());
    }
  }
  void out() {
    for(node u : v) {
      printf("%d %d\n", u.x, u.y);
    }
  }
} a, b;
int main() {
  scanf("%d", &n);
  a.read(); b.read(); b.rev = 1;
  a.solve(); b.solve();
  printf("%d\n", int(a.v.size() + b.v.size()));
  a.out(); b.out();
  return 0;
}