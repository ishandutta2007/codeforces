#include <bits/stdc++.h>
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long double db;
typedef long long ll;
const int N = 3e5 + 10;
int n, m, st[N], top;
ll x[N], y[N], B, S, sz;
ll calc0(int u) { return y[u] + (x[u] - 1) * S; }
ll calc1(int u) { return calc0(u) + B; }
db cross(int u, int v, int w) {
  db x1 = x[v] - x[u], x2 = x[w] - x[u];
  db y1 = y[v] - y[u], y2 = y[w] - y[u];
  return x1 * y2 - x2 * y1;
}
void insert(int u) {
  while(top >= 2 && cross(st[top - 1], st[top], u) < 0) top --;
  st[++ top] = u;
}
int main() {
  scanf("%lld%d", &sz, &m);
  n = 1; x[1] = 1; y[1] = 0; st[top = 1] = 1;
  int op, k, b, s;
  rep(T, 1, m) {
    scanf("%d", &op);
    if(op == 1) {
      scanf("%d", &k);
      sz += k;
      n = 1; x[1] = 1; y[1] = 0; B = S = 0;
      st[top = 1] = 1; 
    }
    if(op == 2) {
      scanf("%d", &k);
      n ++; x[n] = sz + 1; y[n] = 0; y[n] = -calc1(n); insert(n);
      sz += k;
    }
    if(op == 3) {
      scanf("%d%d", &b, &s); B += b; S += s;
    }
    while(top > 1 && calc0(st[top]) >= calc0(st[top - 1])) {
      top --;
    }
    printf("%lld %lld\n", x[st[top]], calc1(st[top]));
  }
  return 0;
}