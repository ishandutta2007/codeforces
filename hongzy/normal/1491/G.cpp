#include <bits/stdc++.h>
#define fs first
#define sc second
#define pb push_back
#define pii pair<int, int>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
int n, c, p[N]; //p[i] : a[i]  p[i]
bool vis[N];
vector<pii> op;
vector<int> cir[N];
void work(int x, int y) { swap(p[x], p[y]); op.pb({x, y}); }
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", p + i);
  rep(i, 1, n) if(p[i] != i && !vis[i]) {
    c ++;
    for(int v = i; !vis[v]; v = p[v]) {
      vis[v] = 1; cir[c].pb(v);
    }
  }
  for(int i = 1; i <= c; i += 2) {
    if(i != c) {
      work(cir[i][0], cir[i + 1][0]);
      for(int j = 1; j < (int)cir[i + 1].size(); j ++) work(cir[i][0], cir[i + 1][j]);
      for(int j = 1; j < (int)cir[i].size(); j ++) work(cir[i + 1][0], cir[i][j]);
      work(cir[i][0], cir[i + 1][0]);
    } else {
      if(cir[i].size() < n) {
        int u = 0;
        rep(j, 1, n) if(p[j] == j) { u = j; break ; }
        work(cir[i][0], u);
        for(int j = 1; j < (int)cir[i].size(); j ++) work(u, cir[i][j]);
        work(cir[i][0], u);;
      } else {
        int len = cir[i].size();
        work(cir[i][0], cir[i][1]);
        work(cir[i][1], cir[i][len - 1]);
        for(int j = 2; j < (int)cir[i].size(); j ++) work(cir[i][0], cir[i][j]);
        work(cir[i][0], cir[i][1]);
      }
    }
  }
  printf("%lu\n", op.size());
  for(auto x : op) printf("%d %d\n", x.fs, x.sc);
  return 0;
}