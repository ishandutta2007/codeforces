#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
int n, m, a[15], b[15], mp[1 << 15], sum[1 << 15], f[15][1 << 15];

inline void add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    mp[1 << i] = i;
    scanf("%d %d", a + i, b + i), b[i]--;
  }
  int all = (1 << n) - 1;
  for (int i = 1; i <= all; i++) {
    sum[i] = sum[i & (i - 1)] + a[mp[i & -i]];
  }
  for (int i = 0; i < n; i++) {
    f[i][1 << i] = 1;
  }
  for (int S = 1; S <= all; S++) {
    for (int i = 0; i < n; i++) {
      if (!(S >> i & 1)) continue;
      for (int j = 0; j < n; j++) {
        if ((S >> j & 1) || (b[i] == b[j])) continue;
        add(f[j][S | (1 << j)], f[i][S]);
      }
    }
  }
//  for (int i = 0; i < 3; i++) {
//    for (int j = 0; j < n; j++) {
//      if (b[j] == i) f[i][1 << j]++;
//    }
//  }
//  for (int S = 1; S <= all; S++) {
//    for (int i = 0; i < n; i++) {
//      if (!(S >> i & 1)) continue;
//      for (int j = 0; j < n; j++) {
//        if ((S >> j & 1) || b[i] == b[j]) continue;
//        add(f[b[j]][S | (1 << j)], f[b[i]][S]);
//      }
//    }
//  }
  int ans = 0;
  for (int S = 1; S <= all; S++) {
    if (sum[S] == m) {
      for (int i = 0; i < n; i++) {
        add(ans, f[i][S]);
      }
//      for (int i = 0; i < 3; i++) {
//        add(ans, f[i][S]);
//      }
    }
  }
  printf("%d", ans);
  return 0;
}