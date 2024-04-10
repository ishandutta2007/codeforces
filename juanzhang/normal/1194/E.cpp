#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n, n1, n2, tot;

struct node1 {
  int x, y1, y2;
} a[maxn];

struct node2 {
  int x1, x2, y;
} b[maxn];

typedef unsigned long long u64;

struct Bitset {
  u64 s[maxn >> 6];

  inline void set(int x) {
    s[x >> 6] |= 1llu << (x & 63);
  }
} tmp, f[maxn];

inline int add(int x, int y) {
  int ans = 0;
  for (register int i = 0; i <= tot; ++i) {
    ans += __builtin_popcountll(f[x].s[i] & f[y].s[i]);
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x1, x2, y1, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 == x2) {
      if (y1 > y2) swap(y1, y2);
      a[++n1] = node1{x1, y1, y2};
    } else {
      if (x1 > x2) swap(x1, x2);
      b[++n2] = node2{x1, x2, y1};
    }
  }
  tot = n2 >> 6;
  for (int i = 1; i <= n1; ++i) {
    for (int j = 1; j <= n2; ++j) {
      if (b[j].x1 <= a[i].x && a[i].x <= b[j].x2 && a[i].y1 <= b[j].y && b[j].y <= a[i].y2) {
        f[i].set(j);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < n1; ++i) {
    for (int j = i + 1; j <= n1; ++j) {
      int s = add(i, j);
      ans += s * (s - 1);
    }
  }
  printf("%I64d", ans >> 1);
  return 0;
}