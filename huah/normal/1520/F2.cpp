#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3fll
#define mp(x, y) make_pair(x, y)
void ast(ll x, ll l, ll r) { assert(x >= l && x <= r); }
const int N = 2e5 + 5;
int n, t, a[N], bit[N],bit2[N];
vector<int> v;
void add(int x, int v) {
  while (x <= n) bit[x] += v, x += x & -x;
}
void add2(int x, int v) {
  while (x <= n) bit2[x] += v, x += x & -x;
}
int query(int x) {
  int ans = 0;
  while (x) ans += bit[x], x -= x & -x;
  return ans;
}
int query2(int x) {
  int ans = 0;
  while (x) ans += bit2[x], x -= x & -x;
  return ans;
}
int query(int l, int r) {
  printf("? %d %d\n", l, r);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans - (query2(r) - query2(l - 1));
}
int get(int k) {
  int ans = 0, sum = 0;
  for (int i = 1 << 17; i; i >>= 1)
    if ((ans | i) <= n && (ans | i) - sum - bit[ans | i] < k)
      ans = (ans | i), sum += bit[ans];
  return ans + 1;
}
int Query(int k) {
  int pos = lower_bound(v.begin(), v.end(), k) - v.begin();
  int l, r;
  l = pos * 20 + 1;
  r = min(n, (pos + 1) * 20);
  while (l < r) {
    int m = (l + r) >> 1;
    if (m - query(1, m) >= k)
      r = m;
    else
      l = m + 1;
  }
  return r;
}
int main() {
  scanf("%d%d", &n, &t);
  if (n <= 60000) {
    int k;
    scanf("%d", &k);
    t--;
    for (int i = 1; i <= n; i++) a[i] = query(1, i);
    for (int i = n; i >= 1; i--) a[i] -= a[i - 1];
    for (int i = 1; i <= n; i++)
      if (a[i] == 0) v.push_back(i);
    printf("! %d\n", v[k - 1]);
    fflush(stdout);
    add(k, 1);
    while (t--) {
      int k;
      scanf("%d", &k);
      k = get(k);
      printf("! %d\n", v[k - 1]);
      add(k, 1);
      fflush(stdout);
    }
  } else {
    int k;
    scanf("%d", &k);
    t--;
    for (int i = 20; i <= n; i += 20) a[i] = i - query(1, i), v.push_back(a[i]);
int ans;
    printf("! %d\n",ans=Query(k));
    add(k, 1);
add2(ans,1);
    fflush(stdout);
    while (t--) {
      scanf("%d", &k);
      k = get(k);
      printf("! %d\n", ans=Query(k));
      add(k, 1);
add2(ans,1);
      fflush(stdout);
    }
  }
}