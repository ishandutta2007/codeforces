#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

const int N = 2e5 + 5;

int n, a[N], deg[N];
vector<int> G[N];
int solve(int c) {
  queue<int> q[2];
  rep(i, 1, n) deg[i] = G[i].size();
  rep(i, 1, n) if(deg[i] == 1) q[(!a[i] || a[i] == c) ? 0 : 1].push(i);
  int ans = 0, cnt = 0;
  for(int t = 0, cur = c; cnt < n; t ^= 1, cur = 3 - cur) {
    ans ++;
    while(q[t].size()) {
      int u = q[t].front(); q[t].pop(); cnt ++;
      for(int v : G[u]) if(-- deg[v] == 1) {
        q[(!a[v] || a[v] == cur) ? t : (t ^ 1)].push(v);
      }
    }
  }
  return ans;
}
int main() {
  int test; scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", a + i);
    if(n == 1) { puts("1"); continue ; }
    rep(i, 1, n) G[i].clear();
    rep(i, 1, n - 1) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u].pb(v); G[v].pb(u);
    }
    printf("%d\n", min(solve(1), solve(2)));
  }
  return 0;
}