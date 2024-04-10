// Author:  HolyK
// Created: Sat May  7 15:44:54 2022
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


constexpr int N(3e5 + 5);
struct Node {
  int ls, rs, w;
} t[N * 20];
int cnt;
void ins(int &o, int l, int r, int x) {
  t[++cnt] = t[o], t[o = cnt].w++;
  if (l == r) return;
  int m = l + r >> 1;
  if (x <= m) {
    ins(t[o].ls, l, m, x);
  } else {
    ins(t[o].rs, m + 1, r, x);
  }
}
int ask(int p, int q, int l, int r, int x) {
  if (t[p].w - t[q].w <= x) return -1;
  if (l == r) return l;
  int m = l + r >> 1, ans = ask(t[p].ls, t[q].ls, l, m, x);
  if (ans == -1) ans = ask(t[p].rs, t[q].rs, m + 1, r, x);
  return ans;
}

int root[N];
void solve() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 1, x; i <= n; i++) {
    std::cin >> x;
    root[i] = root[i - 1];
    ins(root[i], 1, n, x);
  }
  while (m--) {
    int l, r, k;
    std::cin >> l >> r >> k;
    std::cout << ask(root[r], root[l - 1], 1, n, (r - l + 1) / k) << "\n";
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