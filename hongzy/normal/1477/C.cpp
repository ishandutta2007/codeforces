#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 5000 + 10;
int n, x[N], y[N], p[N];
bool vis[N];
ll dis(int i, int j) {
  return (x[i] - x[j]) * ll(x[i] - x[j]) + (y[i] - y[j]) * ll(y[i] - y[j]);
}
int main() {
  scanf("%d", &n);
  rep(i, 1, n) {
    scanf("%d%d", x + i, y + i);
  }
  p[1] = 1; vis[1] = 1;
  rep(i, 2, n) {
    int u = p[i - 1], v = 0;
    rep(j, 1, n) if(!vis[j]) {
      if(!v || dis(u, v) < dis(u, j)) v = j;
    }
    p[i] = v; vis[v] = 1;
  }
  rep(i, 1, n) printf("%d%c", p[i], " \n"[i == n]);
  return 0;
}