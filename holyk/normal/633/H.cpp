// Author:  HolyK
// Created: Tue Jul 13 09:22:04 2021
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define dbg(a...) fprintf(stderr, a)
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

constexpr int N(3e4 + 5);
int n, P, f[N];
std::vector<int> b;
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
struct Node {
  Node *ls, *rs;
  int siz;
  std::array<int, 2> val;
} *null;
void ins(Node *&o, int l, int r, int x, int y) {
  if (o == null) {
    o = new Node;
    o->ls = o->rs = null;
    o->siz = 0;
    o->val = {0, 0};
  }
  o->siz += y;
  // assert(o->siz >= 0);
  if (l == r) {
    // assert(o->siz <= 1);
    o->val[1] = o->siz * b[l] % P;
    return;
  }
  int m = l + r >> 1;
  x <= m ? ins(o->ls, l, m, x, y) : ins(o->rs, m + 1, r, x, y);
  if (!o->ls->siz) {
    o->val = o->rs->val;
  } else {
    o->val[0] = (o->ls->val[0] + o->rs->val[0] * f[o->ls->siz - 1] + o->rs->val[1] * f[o->ls->siz]) % P;
    o->val[1] = (o->ls->val[1] + o->rs->val[0] * f[o->ls->siz] + o->rs->val[1] * f[o->ls->siz + 1]) % P;
  }
  
}
constexpr int T(512);
struct Qry {
  int l, r, id;
  bool operator<(const Qry &rhs) const {
    return l / T == rhs.l / T ? l / T & 1 ? r < rhs.r : r > rhs.r : l < rhs.l;
  }
};

int main() {
  null = new Node;
  null->ls = null->rs = null;
  null->siz = 0;
  null->val = {0, 0};
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> P;
  
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  b = a;
  std::sort(b.begin(), b.end());
  b.resize(std::unique(b.begin(), b.end()) - b.begin());
  f[1] = 1;
  for (int i = 2; i <= b.size() + 1; i++) {
    f[i] = f[i - 1] + f[i - 2];
    if (f[i] >= P) f[i] -= P;
  }
  for (int i = 0; i < n; i++) {
    a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
  }
  int m;
  std::cin >> m;
  std::vector<Qry> q(m);
  for (int i = 0; i < m; i++) {
    std::cin >> q[i].l >> q[i].r;
    q[i].id = i;
    q[i].l--, q[i].r--;
  }
  std::sort(q.begin(), q.end());
  Node *root = null;
  std::vector<int> cnt(b.size());
  auto add = [&](int x, int y) {
    if (!cnt[x]) ins(root, 0, b.size() - 1, x, 1);
    cnt[x] += y;
    // std::cout << x << " " << y << "\n";
    if (!cnt[x]) ins(root, 0, b.size() - 1, x, -1);
    // assert(cnt[x] >= 0);
  };  
  std::vector<int> out(m);
  int x = 0, y = -1;
  for (auto [l , r, id] : q) {
    while (x > l) add(a[--x], +1);
    while (y < r) add(a[++y], +1);
    while (y > r) add(a[y--], -1);
    while (x < l) add(a[x++], -1);
    out[id] = root->val[1];
  }
  for (int x : out) std::cout << x << "\n";
  return 0;
}
/*
3 10
1 2 1
1
1 3

5 10
2 1 2 1 2
2
2 4
4 5
 */