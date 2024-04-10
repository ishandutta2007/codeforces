#include <bits/stdc++.h>
using namespace std;

#define nc getchar()
typedef long long ll;
typedef long double db;
const int maxn = 1e6 + 10;
ll f[maxn];
int n, q[maxn];

struct node {
  ll x, y, w;
  bool operator < (const node& o) const {
    return y > o.y;
  }
} a[maxn];

inline ll read() {
  ll x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
}

db slope(int x, int y) {
  return a[x].x == a[y].x ? 1e18 : db(f[x] - f[y]) / db(a[x].x - a[y].x);
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i].x = read();
    a[i].y = read();
    a[i].w = read();
  }
  ll ans = 0;
  int l = 1, r = 1;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    while (l < r && slope(q[l], q[l + 1]) > a[i].y) l++;
    f[i] = f[q[l]] + (a[i].x - a[q[l]].x) * a[i].y - a[i].w;
    while (l < r && slope(q[r - 1], q[r]) < slope(q[r], i)) r--;
    q[++r] = i, ans = max(ans, f[i]);
  }
  printf("%I64d", ans);
  return 0;
}