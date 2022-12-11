#include <bits/stdc++.h>
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const int M = 450; 

int n, x, mx, fa[N], d[N], a[N], c[N], use[N];
int pre[M][N];
bool dp[M][N];
char ans[N];
vector<int> v, G[N], L[N], R[N];
void dfs(int u) {
  mx = max(mx, d[u] = d[fa[u]] + 1); a[d[u]] ++;
  (G[u].size() ? L[d[u]] : R[d[u]]).pb(u);
  for(int v : G[u]) dfs(v);
}
void find(int i, int j) {
  if(!i) return ;
  use[v[i - 1]] = pre[i][j];
  find(i - 1, j - v[i - 1] * pre[i][j]);
}
int main() {
  scanf("%d%d", &n, &x);
  rep(i, 2, n) scanf("%d", fa + i), G[fa[i]].pb(i);
  dfs(1);
  rep(i, 1, mx) c[a[i]] ++;
  rep(i, 1, n) if(c[i]) v.pb(i);
  dp[0][0] = 1;
  rep(i, 1, v.size()) {
    int s = v[i - 1], c = ::c[s];
    static int g[N];
    rep(j, 0, x) g[j] = dp[i - 1][j] ? 0 : (j >= s ? g[j - s] + 1 : N);
    rep(j, 0, x) if(g[j] <= c) { dp[i][j] = 1; pre[i][j] = g[j]; }
  }
  if(dp[v.size()][x]) {
    fill(ans + 1, ans + n + 1, 'b');
    find(v.size(), x);
    rep(i, 1, mx) if(use[a[i]]-- > 0) {
      for(int v : L[i]) ans[v] = 'a';
      for(int v : R[i]) ans[v] = 'a';
    }
    printf("%d\n", mx);
    ans[n + 1] = '\0'; puts(ans + 1);
    return 0;
  }
  int cnt = n, y = x; //nodes to assign & number of 'a' to assign
  rep(i, 1, mx) {
    if(a[i] <= y || a[i] <= cnt - y) {
      bool rev = a[i] > y;
      for(int v : L[i]) ans[v] = rev ? 'b' : 'a';
      for(int v : R[i]) ans[v] = rev ? 'b' : 'a';
      cnt -= a[i];
      if(!rev) y -= a[i];
      continue ;
    }
    bool rev = y < cnt - y ? 1 : 0;
    for(int v : L[i]) ans[v] = rev ? 'b' : 'a';
    int rm = max(y, cnt - y) - int(L[i].size());
    rep(j, 0, rm - 1) ans[R[i][j]] = rev ? 'b' : 'a';
    rep(u, 1, n) if(!ans[u]) ans[u] = rev ? 'a' : 'b';
    break ;
  }
  printf("%d\n", mx + 1);
  ans[n + 1] = '\0'; puts(ans + 1);
  return 0;
}