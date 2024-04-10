// Author:  HolyK
// Created: Tue May  3 10:14:36 2022
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

constexpr int N(2e5 + 5);
struct LCT {
  int ch[N][2], fa[N];
  bool rev[N];
  bool nrt(int o) {
    return fa[o] && (ch[fa[o]][0] == o || ch[fa[o]][1] == o);
  }
  int dir(int o) {
    return ch[fa[o]][1] == o;
  }
  void sch(int o, int d, int x) {
    ch[o][d] = x;
    if (x) fa[x] = o;
  }
  void rotate(int o) {
    int k = dir(o), p = fa[o];
    fa[o] = fa[p];
    if (nrt(p)) ch[fa[o]][dir(p)] = o;
    sch(p, k, ch[o][!k]), sch(o, !k, p);
    pushup(p);
    pushup(o);
  }
  void pull(int o) {
    if (nrt(o)) pull(fa[o]);
    pushdown(o);
  }
  void splay(int o) {
    for (pull(o); nrt(o); rotate(o)) {
      if (nrt(fa[o])) {
        rotate(dir(fa[o]) == dir(o) ? fa[o] : o);
      }
    }
    pushup(o);
  }
  void access(int o) {
    for (int x = 0, i = o; i; i = fa[x = i]) {
      splay(i), ch[i][1] = x, pushup(i);
    }
    splay(o);
  }
  void evert(int o) {
    access(o), reverse(o), pushdown(o);
  }
  void expose(int x, int y) {
    evert(x), access(y); 
  }
  bool link(int x, int y) {
    if (x == y) return false;
    expose(x, y);
    if (fa[x]) return false;
    fa[x] = y;
    return true;
  }
  bool cut(int x, int y) {
    expose(x, y);
    if (fa[x] == y && !ch[x][0] && !ch[x][1] && !ch[y][1]) {
      fa[x] = ch[y][0] = 0;
      pushup(y);
      return true;
    }
    return false;
  }
  void pushup(int o) {
    // sum[o] = sum[ch[o][0]] ^ sum[ch[o][1]] ^ val[o];
  }
  void reverse(int o) {
    rev[o] ^= 1;
    std::swap(ch[o][0], ch[o][1]);
  }
  void pushdown(int o) {
    if (rev[o]) {
      if (ch[o][0]) reverse(ch[o][0]);
      if (ch[o][1]) reverse(ch[o][1]);
      rev[o] = false;
    }
  }
} lct;

struct SegTree {
#define ls o << 1
#define rs o << 1 | 1
  int min[N << 2], add[N << 2], cnt[N << 2];
  void pushup(int o) {
    min[o] = std::min(min[ls], min[rs]);
    cnt[o] = 0;
    if (min[o] == min[ls]) cnt[o] += cnt[ls];
    if (min[o] == min[rs]) cnt[o] += cnt[rs];
  }
  void build(int o, int l, int r) {
    min[o] = add[o] = 0, cnt[o] = r - l + 1;
    if (l == r) return;
    int m = l + r >> 1;
    build(ls, l, m);
    build(rs, m + 1, r);
  }
  void apply(int o, int x) {
    min[o] += x;
    add[o] += x;
  }
  void pushdown(int o) {
    if (add[o]) {
      apply(ls, add[o]);
      apply(rs, add[o]);
      add[o] = 0;
    }
  }
  void update(int o, int l, int r, int x, int y, int z) {
    if (x <= l && r <= y) return apply(o, z);
    int m = l + r >> 1;
    pushdown(o);
    if (x <= m) update(ls, l, m, x, y, z);
    if (y > m) update(rs, m + 1, r, x, y, z);
    pushup(o);
  }
  int ask(int o, int l, int r, int x, int y) {
    if (r < x || y < l) return 0;
    if (x <= l && r <= y) return min[o] == 1 ? cnt[o] : 0;
    int m = l + r >> 1;
    pushdown(o);
    return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
  }
} seg;

int n, m, a[N];
std::vector<int> g[N];
void add(int x, int y) {
  x = a[x + 1], y = a[y + 1];
  g[x].push_back(y);
  g[y].push_back(x);
}
void cut(int x) {
  for (int y : g[x]) lct.cut(x, y);
}
void solve() {
  std::cin >> n >> m;
  int s = n * m;
  for (int i = 1; i <= s; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i + 1 < n) {
        add(i * m + j, (i + 1) * m + j);
      }
      if (j + 1 < m) {
        add(i * m + j, i * m + j + 1);
      } 
    }
  }

  seg.build(1, 1, s);
  LL ans = 0;
  for (int r = 1, l = 1; r <= s; r++) {
    seg.update(1, 1, s, 1, r, 1);
    for (int y : g[r]) {
      if (y < r) {
        seg.update(1, 1, s, 1, y, -1);
        // std::cerr << "ry " << r << " " << y << "\n";
        while (y >= l && !lct.link(r, y)) cut(l++);
      }
    }
    // std::cerr << "lr " << l << " " << r << "\n"; 
    ans += seg.ask(1, 1, s, l, r);
  }
  std::cout << ans << "\n";
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