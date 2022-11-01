#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <map>
#include <memory>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 1e5 + 5, bs = 320, mod = 1e9 + 7;
int n, q, b[N], c[N];
int t[N << 2], lz[N << 2], bit[N];
vector<int> v[550];
bool needLoad[550];
void add(int x, int v) {
  while (x <= n) bit[x] += v, x += x & -x;
}
int query(int x) {
  int ans = 0, sum = 0;
  for (int i = 1 << 16; i; i >>= 1)
    if ((ans | i) <= n && sum + bit[ans | i] < x) ans |= i, sum += bit[ans];
  return ans + 1;
}
void load(int x) {
  int l = max(1, x * bs), r = min(n, (x + 1) * bs - 1);
  v[x].clear();
  for (int i = l; i <= r; i++) {
    v[x].push_back(query(b[i]));
    add(v[x].back(), 1);
  }
  for (int i = v[x].size() - 1; i >= 0; i--) add(v[x][i], -1);
  sort(v[x].begin(), v[x].end());
  needLoad[x] = false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]), b[i] = i - b[i];
  for (int i = 1; i <= n; i++) add(i, 1);
  for (int i = 0; i <= n / bs; i++) needLoad[i] = true;
  scanf("%d", &q);
  while (q--) {
    int op, x, y;
    scanf("%d%d", &op, &x);
    if (op == 1) {
      scanf("%d", &y);
      b[x] = x - y;
      needLoad[x / bs] = true;
    } else {
      int rkx = b[x];
      int las = min(n, (x / bs + 1) * bs - 1);
      for (int i = x + 1; i <= las; i++)
        if (b[i] <= rkx) rkx++;
      if (las + 1 <= n) {
        las = (las + 1) / bs;
        for (int i = las; i <= n / bs; i++) {
          if (needLoad[i]) load(i);
          int p = upper_bound(v[i].begin(), v[i].end(), rkx) - v[i].begin();
          rkx += p;
        }
      }
      printf("%d\n", rkx);
    }
  }
}