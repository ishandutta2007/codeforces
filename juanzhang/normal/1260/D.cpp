#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

const int maxn = 2e5 + 10;
int n, m, k, T, a[maxn], cnt[maxn];

struct node {
  int l, r, x;
} data[maxn];

bool check(int mid) {
  if (!mid) return 1;
  int val = a[n - mid + 1];
  memset(cnt, 0, sizeof cnt);
  rep(i, 1, m) {
    if (data[i].x > val) {
      cnt[data[i].l]++;
      cnt[data[i].r + 1]--;
    }
  }
  int res = 1;
  rep(i, 1, k) {
    cnt[i] += cnt[i - 1];
    res += cnt[i] ? 3 : 1;
  }
  return res <= T;
}

int main() {
  scanf("%d %d %d %d", &n, &k, &m, &T);
  rep(i, 1, n) scanf("%d", a + i);
  rep(i, 1, m) scanf("%d %d %d", &data[i].l, &data[i].r, &data[i].x);
  sort(a + 1, a + n + 1);
  int l = 0, r = n, mid;
  while (l < r) {
    mid = (l + r + 1) >> 1;
    check(mid) ? l = mid : r = mid - 1;
  }
  printf("%d", r);
  return 0;
}