#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5;
int n, a[N], mn[N << 2], mx[N << 2], lz[N << 2];
vector<int> pos[N];
void build(int l, int r, int k) {
  if (l == r) {
    mn[k] = mx[k] = l;
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, k << 1);
  build(m + 1, r, k << 1 | 1);
  mn[k] = min(mn[k << 1], mn[k << 1 | 1]);
  mx[k] = max(mx[k << 1], mx[k << 1 | 1]);
}
void update(int l, int r, int k) {
  mn[k] += lz[k];
  mx[k] += lz[k];
  if (l != r) lz[k << 1] += lz[k], lz[k << 1 | 1] += lz[k];
  lz[k] = 0;
}
void fix(int l, int r, int k, int x, int y, int v) {
  if (lz[k]) update(l, r, k);
  if (r < x || l > y) return;
  if (l >= x && r <= y) {
    lz[k] += v;
    update(l, r, k);
    return;
  }
  int m = (l + r) >> 1;
  fix(l, m, k << 1, x, y, v);
  fix(m + 1, r, k << 1 | 1, x, y, v);
  mn[k] = min(mn[k << 1], mn[k << 1 | 1]);
  mx[k] = max(mx[k << 1], mx[k << 1 | 1]);
}
int querymn(int l, int r, int k, int x, int y) {
  if (lz[k]) update(l, r, k);
  if (r < x || l > y) return inf;
  if (l >= x && r <= y) return mn[k];
  int m = (l + r) >> 1;
  int ans =
      min(querymn(l, m, k << 1, x, y), querymn(m + 1, r, k << 1 | 1, x, y));
  mn[k] = min(mn[k << 1], mn[k << 1 | 1]);
  mx[k] = max(mx[k << 1], mx[k << 1 | 1]);
  return ans;
}
int querymx(int l, int r, int k, int x, int y) {
  if (lz[k]) update(l, r, k);
  if (r < x || l > y) return -inf;
  if (l >= x && r <= y) return mx[k];
  int m = (l + r) >> 1;
  int ans =
      max(querymx(l, m, k << 1, x, y), querymx(m + 1, r, k << 1 | 1, x, y));
  mn[k] = min(mn[k << 1], mn[k << 1 | 1]);
  mx[k] = max(mx[k << 1], mx[k << 1 | 1]);
  return ans;
}
int ans[N];
void sol(int x) {
  int px = querymn(0, n, 1, x, x), py = querymn(0, n, 1, x - 1, x - 1);
  int mx = (py - querymn(0, n, 1, 0, x - 1)) + (querymx(0, n, 1, x, n) - px);
  int mn = (py - querymx(0, n, 1, 0, x - 1)) + (querymn(0, n, 1, x, n) - px);
  ans[x] = max(ans[x], max((mx + 1) / 2, (-mn) / 2));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), pos[a[i]].push_back(i);
  build(0, n, 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < pos[i].size(); j++) sol(pos[i][j]);
    for (int j = 0; j < pos[i].size(); j++) fix(0, n, 1, pos[i][j], n, -2);
    for (int j = 0; j < pos[i].size(); j++) sol(pos[i][j]);
  }
  for (int i = 1; i <= n; i++) printf(i == n ? "%d\n" : "%d ", ans[i]);
}
// 2 3 4 5    2 3 4 5