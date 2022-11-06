// Author:  HolyK
// Created: Thu May 19 15:57:31 2022
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

constexpr int P(1e9 + 7);
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
inline void dec(int &x, int y) {
  x -= y;
  if (x < 0) x += P;
}
inline int mod(LL x) { return x % P; }
int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P) {
    if (k & 1) r = 1LL * r * x % P;
  }
  return r;
}

constexpr int N(2e5 + 5);
struct Node {
  int ls, rs, w;
} t[N * 100];
int cnt, mark;
void update(int &o, int l, int r, int x, int y, int z) {
  if (o <= mark) {
    t[++cnt] = t[o], o = cnt;
  }
  if (x <= l && r <= y) {
    t[o].w = 1LL * t[o].w * z % P;
    return;
  }
  int m = l + r >> 1;
  if (x <= m) update(t[o].ls, l, m, x, y, z);
  if (y > m) update(t[o].rs, m + 1, r, x, y, z);
}
int ask(int o, int l, int r, int x) {
  if (l == r) return t[o].w;
  int m = l + r >> 1;
  return 1LL * t[o].w * (x <= m ? ask(t[o].ls, l, m, x) : ask(t[o].rs, m + 1, r, x)) % P;
}

int n, pos[N], root[N];
void solve() {
  t[0].w = 1;
  std::cin >> n;
  for (int i = 1, x; i <= n; i++) {
    std::cin >> x;
    root[i] = root[i - 1];
    for (int j = 2; j * j <= x; j++) {
      int c = 0;
      while (x % j == 0) x /= j, c++;
      if (!c) continue;
      for (int k = 1, v = 1, y = 1; k <= c; k++) {
        v *= j, y *= j;
        if (k == c || pos[v] != pos[v * j]) {
          update(root[i], 1, n, pos[v] + 1, i, y);
          y = 1;
        }
        pos[v] = i;
      }
    }
    if (x > 1) {
      update(root[i], 1, n, pos[x] + 1, i, x);
      pos[x] = i;
    }
    mark = cnt;
  }

  int q, ans = 0;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    l = (l + ans) % n + 1;
    r = (r + ans) % n + 1;
    if (l > r) std::swap(l, r);
    ans = ask(root[r], 1, n, l);
    std::cout << ans << "\n";
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