#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
int n, m;
bool pd(vector< vector<int> > v) {
  rep(i, 2, n) {
    int c = 0;
    rep(j, 1, m) if((c += v[i][j] != v[1][j]) > 2) return 0;
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  vector< vector<int> > a(n + 1), vec(n + 1);
  vector<int> cur;
  rep(i, 1, n) {
    cur = {0};
    rep(j, 1, m) { int x; scanf("%d", &x); cur.pb(x); }
    a[i] = cur;
  }
  int id = 0;
  rep(i, 2, n) {
    rep(j, 1, m) if(a[1][j] != a[i][j]) vec[i].pb(j);
    if(vec[i].size() <= 2) continue ;
    if(vec[i].size() >= 5) { puts("No"); exit(0); }
    if(vec[i].size() > vec[id].size()) id = i;
  }
  #define out() do { puts("Yes");rep(i,1,m)printf("%d ", a[1][i]);putchar('\n');return 0; } while(0);

  if(vec[id].size() <= 2) {
    out();
  }
  if(vec[id].size() == 4) { //2 mistake
    vector<int> a1 = a[1];
    for(int i = 0; i < 4; i ++) {
      int ci = vec[id][i]; a[1][ci] = a[id][ci];
      for(int j = i + 1; j < 4; j ++) {
        int cj = vec[id][j]; a[1][cj] = a[id][cj];
        if(pd(a)) {
          out();
        }
        a[1][cj] = a1[cj];
      }
      a[1][ci] = a1[ci];
    }
  } else {
    for(int p = 0; p < 3; p ++) { //1 mistake
      int c = vec[id][p], to = a[id][c];
      swap(to, a[1][c]);
      if(pd(a)) {
        out();
      }
      swap(to, a[1][c]);
    }
    for(int p = 0; p < 3; p ++) { // answer in id
      int c = vec[id][p], to = a[id][c];
      swap(to, a[1][c]);
      for(int t = 0; t < 3; t ++) if(t != p) { //don't know answer
        int c2 = vec[id][t], tmp = a[1][c2]; a[1][c2] = -1;
        bool ok = 1;
        rep(i, 2, n) if(i != id) {
          vector<int> v;
          bool mk = 0;
          rep(j, 1, m) if(a[1][j] != a[i][j]) v.pb(j), mk |= j == c2;
          if(~a[1][c2]) mk = 0;
          if(v.size() > 3) { ok = 0; break ; }
          if(v.size() <= 2) continue ;
          if(!mk) { ok = 0; break ; }
          a[1][c2] = a[i][c2];
        }
        if(ok) {
          out();
        }
        a[1][c2] = tmp;
      }
      swap(to, a[1][c]);
    }
  }
  puts("No");
  return 0;
}