// Author:  HolyK
// Created: Wed Sep 21 10:38:03 2022
#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

#define ls o << 1
#define rs o << 1 | 1

constexpr int N(1.5e5 + 5);
int n, max[N << 2][2], cnt[N << 2], tag[N << 2], c[N];

void add(int p, int x) {
  for (; p <= n; p += p & -p) c[p] += x;
}
int ask(int p) {
  int r = 0;
  for (; p; p -= p & -p) r += c[p];
  return r;
}

void apply(int o, int x) {
  max[o][0] += x;
  tag[o] += x;
}

void pushdown(int o) {
  if (tag[o]) {
    if (max[ls][0] >= max[rs][0]) {
      apply(ls, tag[o]);
    }
    if (max[rs][0] >= max[ls][0]) {
      apply(rs, tag[o]);
    }
    tag[o] = 0;
  }
}

void pushup(int o) {
  max[o][0] = std::max(max[ls][0], max[rs][0]);
  max[o][1] = 0;
  cnt[o] = 0;
  if (max[ls][0] == max[o][0]) {
    cnt[o] += cnt[ls];
    smax(max[o][1], max[ls][1]);
  } else {
    smax(max[o][1], max[ls][0]);
  }
  if (max[rs][0] == max[o][0]) {
    cnt[o] += cnt[rs];
    smax(max[o][1], max[rs][1]);
  } else {
    smax(max[o][1], max[rs][0]);
  }
}

void ins(int o, int l, int r, int x, int y) {
  if (l == r) {
    max[o][0] = y;
    max[o][1] = 0;
    cnt[o] = 1;
    return;
  }
  pushdown(o);
  int m = l + r >> 1;
  if (x <= m) {
    ins(ls, l, m, x, y);
  } else {
    ins(rs, m + 1, r, x, y);
  }
  pushup(o);
}

LL update(int o, int l, int r, int x, int y, int z) {
  if (r < x || y < l || z >= max[o][0]) return 0;
  if (x <= l && r <= y && max[o][0] > z && z > max[o][1]) {
    int k = ask(max[o][0]) - ask(z);
    apply(o, z - max[o][0]);
    return 1LL * k * cnt[o];
  }

  pushdown(o);
  int m = l + r >> 1,
      ans = update(ls, l, m, x, y, z) + update(rs, m + 1, r, x, y, z);

  pushup(o);

  return ans;
}

int a[N], b[N];
LL ans[N];
void work() {
  for (int i = 1; i <= n; i++) b[a[i]] = i;

  memset(max, 0, sizeof max);
  memset(cnt, 0, sizeof cnt);
  memset(tag, 0, sizeof tag);
  memset(c, 0, sizeof c);
  
  for (int i = 1; i <= n; i++) {
    ins(1, 1, n, b[i], n);
    if (b[i] > 1) ans[i] -= update(1, 1, n, 1, b[i] - 1, b[i] - 1);
    add(b[i], 1);
    ans[i] += i - ask(b[i]);
  }
}

void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  work();

  std::reverse(a + 1, a + 1 + n);

  work();

  for (int i = 1; i <= n; i++) {
    ans[i] += ans[i - 1];
    std::cout << ans[i] + i << "\n";
  }
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}