// Author:  HolyK
// Created: Sat Feb 26 23:08:17 2022
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

constexpr LL QB = LLONG_MIN;
struct Line {
  LL a, b; // y = ax + b
  mutable std::function<const Line *()> next;
  bool operator<(const Line &r) const {
    if (r.b != QB) return a < r.a;
    auto q = next();
    if (!q) return 0;
    return b - q->b < (q->a - a) * r.a;
  }
};

using LLL = __int128;
struct DynamicHull : std::multiset<Line> {
  using multiset::multiset;

  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return false;
      return y->a == z->a && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) {
      return x->a == y->a && y->b <= x->b;
    }
    return LLL(x->b - y->b) * (z->a - y->a) >= LLL(y->b - z->b) * (y->a - x->a);
  }

  void ins(LL a, LL b) {
    auto it = insert({a, b});
    it->next = [=] {
      auto q = next(it);
      return q == end() ? nullptr : &*q;
    };

    if (bad(it)) {
      erase(it);
    } else {
      iterator z;
      while (it != begin() && bad(z = prev(it))) erase(z);
      it++;
      while (it != end() && bad(it)) it = erase(it);
    }
  }

  LL askMax(LL x) {
    auto l = *lower_bound({x, QB});
    return l.a * x + l.b;
  }
};

constexpr int N(2e5 + 5);
std::vector<int> g[N];
int a[N], b[N];

DynamicHull *s[N];
LL f[N];
void dfs(int x, int p) {
  s[x] = new DynamicHull;
  for (int y : g[x]) {
    if (y == p) continue;
    dfs(y, x);
    if (s[x]->size() < s[y]->size()) std::swap(s[x], s[y]);
    for (auto &[a, b, _] : *s[y]) {
      s[x]->ins(a, b);
    }
    s[y]->clear();
    s[x]->ins(b[y], f[y]);
  }
  f[x] = s[x]->empty() ? 0 : s[x]->askMax(a[x]);
}

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    b[i] = -b[i];
  }
  
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    std::cout << -f[i] << " \n"[i == n];
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