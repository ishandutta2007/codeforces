#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
int n, k, a[16], b[16];
bitset<2045> f[1 << 16];
bool vis[16];
void solve(int s, int i) {
  if(!(s & (s - 1))) return ;
  rep(u, 0, n - 1) if(s >> u & 1 && a[u] < i && f[s ^ (1 << u)][i - a[u]]) {
    solve(s ^ (1 << u), i - a[u]);
    return ;
  }
  solve(s, i * k);
  rep(u, 0, n - 1) if(s >> u & 1) ++ b[u];
}
int main() {
  scanf("%d%d", &n, &k);
  rep(i, 0, n - 1) scanf("%d", a + i);
  rep(i, 0, n - 1) f[1 << i][a[i]] = 1;
  rep(s, 1, (1 << n) - 1) if(s & (s - 1)) {
    int z = 0;
    rep(u, 0, n - 1) if(s >> u & 1) {
      z += a[u];
      f[s] |= f[s ^ (1 << u)] << a[u];
    }
    per(i, z / k, 1)
      if(f[s][i * k])
        f[s][i] = 1;
  }
  if(!f[(1 << n) - 1][1])
    return puts("NO"), 0;
  puts("YES");
  solve((1 << n) - 1, 1);
  rep(T, 1, n - 1) {
    int mx = 0;
    rep(i, 0, n - 1) if(!vis[i]) mx = max(mx, b[i]);
    int x = -1, y = -1;
    rep(i, 0, n - 1) if(!vis[i] && mx == b[i]) {
      if(!~x) x = i;
      else if(!~y) y = i;
    }
    printf("%d %d\n", a[x], a[y]);
    vis[y] = 1;
    a[x] += a[y];
    while(a[x] % k == 0) a[x] /= k, -- b[x];
  }
  return 0;
}