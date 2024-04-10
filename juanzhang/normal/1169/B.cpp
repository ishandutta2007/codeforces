#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int n, m, a[maxn], b[maxn];

bool check() {
  static bool flg[maxn];
  memset(flg, 0, sizeof flg);
  int v = a[1], tot = n;
  for (int i = 1; i <= n; i++) {
    if (a[i] == v || b[i] == v) {
      flg[i] = 1, tot--;
    }
  }
  static int cnt[maxn];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++) {
    if (!flg[i]) {
      cnt[a[i]]++, cnt[b[i]]++;
    }
  }
  int mx = 0;
  for (int i = 1; i <= m; i++) {
    mx = max(mx, cnt[i]);
  }
  return mx == tot;
}

int main() {
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", a + i, b + i);
    if (a[i] > b[i]) swap(a[i], b[i]);
  }
  bool flg = check();
  swap(a[1], b[1]);
  flg |= check();
  puts(flg ? "YES" : "NO");
  return 0;
}