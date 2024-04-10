// Author:  HolyK
// Created: Tue Sep  6 15:57:15 2022
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
constexpr int N(3e5 + 5);
std::vector<PII> g[N << 2];
void add(int o, int l, int r, int x, int y, const PII &z) {
  if (r <= x || y <= l) return;
  if (x <= l && r <= y) {
    g[o].push_back(z);
    return;
  }
  int m = l + r >> 1;
  add(ls, l, m, x, y, z);
  add(rs, m, r, x, y, z);
}

int f[N * 2], sl[N * 2], sr[N * 2];
int find(int x) {
  while (x != f[x]) x = f[x];
  return x;
}

LL ans;
int q, st[N], top;
void dfs(int o, int l, int r) {
  int cur = top;
  LL now = ans;
  for (auto [x, y] : g[o]) {
    x = find(x), y = find(y);
    if (x == y) continue;
    if (sl[x] + sr[x] > sl[y] + sr[y]) {
      std::swap(x, y);
    }
    st[++top] = x;
    f[x] = y;
    ans += 1LL * sl[x] * sr[y] + 1LL * sl[y] * sr[x];
    sl[y] += sl[x];
    sr[y] += sr[x];
  }
  if (r - l == 1) {
    std::cout << ans << " \n"[r == q];
  } else {
    int m = l + r >> 1;
    dfs(ls, l, m), dfs(rs, m, r);
  }

  ans = now;
  while (top > cur) {
    int x = st[top--];
    sl[f[x]] -= sl[x];
    sr[f[x]] -= sr[x];
    f[x] = x;
  }
}

void solve() {
  std::cin >> q;

  std::map<PII, int> a;
  for (int i = 0; i < q; i++) {
    int x, y;
    std::cin >> x >> y;
    PII p(x, y + 3e5);
    auto it = a.find(p);
    if (it == a.end()) {
      a[p] = i;
    } else {
      add(1, 0, q, it->second, i, p);
      a.erase(it);
    }
  }

  for (auto &k : a) {
    add(1, 0, q, k.second, q, k.first);
  }

  for (int i = 1; i <= 6e5; i++) {
    f[i] = i;
    sl[i] = i <= 3e5;
    sr[i] = i > 3e5;
  }
  dfs(1, 0, q);
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