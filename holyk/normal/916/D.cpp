// Author:  HolyK
// Created: Fri May  6 19:39:49 2022
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

#include <ext/pb_ds/assoc_container.hpp>
template <class T, class U = __gnu_pbds::null_type, class Comp = std::less<T>>
using Tree = __gnu_pbds::tree<T, U, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

constexpr int N(1e5 + 5);
struct Node {
  int ls, rs, w;
} t[N * 200];
int cnt;
struct Tree1 {
  void ins(int &o, int l, int r, int x, int y) {
    t[++cnt] = t[o], t[o = cnt].w += y;
    if (l == r) return;
    int m = l + r >> 1;
    if (x <= m) {
      ins(t[o].ls, l, m, x, y);
    } else {
      ins(t[o].rs, m + 1, r, x, y);
    }
  }
  int ask(int o, int l, int r, int x) {
    if (l >= x || !o) return 0;
    if (r < x) return t[o].w;
    int m = l + r >> 1;
    return ask(t[o].ls, l, m, x) + ask(t[o].rs, m + 1, r, x);
  }
} t0;
struct Tree2 {
  void ins(int &o, int l, int r, int x, int y) {
    t[++cnt] = t[o], o = cnt;
    if (l == r) {
      t[o].w = y;
      return;
    }
    int m = l + r >> 1;
    if (x <= m) {
      ins(t[o].ls, l, m, x, y);
    } else {
      ins(t[o].rs, m + 1, r, x, y);
    }
  }
  int ask(int o, int l, int r, int x) {
    if (l == r) return t[o].w;
    int m = l + r >> 1;
    return x <= m ? ask(t[o].ls, l, m, x) : ask(t[o].rs, m + 1, r, x);
  }
} t1;

int val[N];

std::array<int, 2> root[N];
void solve() {
  int n;
  std::cin >> n;
  std::map<std::string, int> id;
  
  memset(val, 0x3f, sizeof val);
  for (int i = 1; i <= n; i++) {
    std::string s;
    std::cin >> s;
    root[i] = root[i - 1];
    if (s[0] == 's') {
      int x, y;
      std::cin >> s >> y;
      int &o = id[s];
      if (!o) o = id.size();
      x = t1.ask(root[i][1], 1, n, o);
      if (x) t0.ins(root[i][0], 1, 1e9, x, -1);
      x = y;
      t0.ins(root[i][0], 1, 1e9, x, 1);
      t1.ins(root[i][1], 1, n, o, x);
    } else if (s[0] == 'r') {
      std::cin >> s;
      auto it = id.find(s);
      if (it == id.end()) continue;
      int o = it->second;
      int x = t1.ask(root[i][1], 1, n, o);
      if (x) {
        t1.ins(root[i][1], 1, n, o, 0);
        t0.ins(root[i][0], 1, 1e9, x, -1);
      }
    } else if (s[0] == 'q') {
      std::cin >> s;
      auto it = id.find(s);
      int ans = -1, o, x;
      if (it == id.end()) goto print;
      o = it->second;
      x = t1.ask(root[i][1], 1, n, o);
      if (!x) goto print;
      ans = t0.ask(root[i][0], 1, 1e9, x);
      print:
      std::cout << ans << std::endl;
    } else {
      int x;
      std::cin >> x;
      x = std::max(i - x - 1, 0);
      root[i] = root[x];
    }
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