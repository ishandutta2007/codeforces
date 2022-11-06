// Author:  HolyK
// Created: Tue Sep 20 21:19:43 2022
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

template <class Info, class Tag>
class LazySegmentTree {
private:
  void pull(int p) { info[p] = info[2 * p] + info[2 * p + 1]; }
  void apply(int p, const Tag &v) {
    info[p].apply(v);
    tag[p].apply(v);
  }
  void push(int p) {
    apply(2 * p, tag[p]);
    apply(2 * p + 1, tag[p]);
    tag[p] = Tag();
  }
  void modify(int p, int l, int r, int x, const Info &v) {
    if (r - l == 1) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    push(p);
    if (x < m) {
      modify(2 * p, l, m, x, v);
    } else {
      modify(2 * p + 1, m, r, x, v);
    }
    pull(p);
  }
  Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) {
      return Info();
    }
    if (l >= x && r <= y) {
      return info[p];
    }
    int m = (l + r) / 2;
    push(p);
    return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
  }
  void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
    if (l >= y || r <= x) {
      return;
    }
    if (l >= x && r <= y) {
      apply(p, v);
      return;
    }
    int m = (l + r) / 2;
    push(p);
    rangeApply(2 * p, l, m, x, y, v);
    rangeApply(2 * p + 1, m, r, x, y, v);
    pull(p);
  }
public:
  const int n;
  std::vector<Info> info;
  std::vector<Tag> tag;
  LazySegmentTree(int n)
    : n(n), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}
  LazySegmentTree(const std::vector<Info> &init) : LazySegmentTree(init.size()) {
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (r - l == 1) {
        info[p] = init[l];
        return;
      }
      int m = (l + r) / 2;
      build(2 * p, l, m);
      build(2 * p + 1, m, r);
      pull(p);
    };
    build(1, 0, n);
  }
  void modify(int p, const Info &v) { modify(1, 0, n, p, v); }
  Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
  void rangeApply(int l, int r, const Tag &v) {
    return rangeApply(1, 0, n, l, r, v);
  }
};

struct Tag {
  bool c = false;
  void apply(const Tag &e) {
    c = c || e.c;
  }
};

struct Info {
  int sum = 0, max = -1, len = 0;
  void apply(const Tag &e) {
    if (e.c) {
      sum = -len;
      max = -1;
    }
  }
  Info operator+(const Info &r) const {
    return {sum + r.sum, std::max(max + r.sum, r.max), len + r.len};
  }
};

using SegTree = LazySegmentTree<Info, Tag>;

constexpr int N(1e5 + 5);
int n, m, in[N], dfn, top[N], siz[N], son[N], fa[N];
std::vector<int> g[N];
void dfs1(int x) {
  siz[x] = 1;
  for (int y : g[x]) {
    if (y == fa[x]) continue;
    fa[y] = x;
    dfs1(y);
    siz[x] += siz[y];
    if (siz[y] > siz[son[x]]) son[x] = y;
  }
}
void dfs2(int x) {
  in[x] = dfn++;
  if (!son[x]) return;
  top[son[x]] = top[x];
  dfs2(son[x]);
  for (int y : g[x]) {
    if (y == fa[x] || y == son[x]) continue;
    top[y] = y;
    dfs2(y);
  }
}

void solve() {
  std::cin >> n >> m;
  for (int i = 2, x; i <= n; i++) {
    std::cin >> x;
    g[x].push_back(i);
  }

  dfs1(1), top[1] = 1, dfs2(1);

  std::vector<Info> a(n, {-1, -1, 1});
  SegTree seg(a);

  auto ask = [&](int x) {
    Info v;
    while (x) {
      v = seg.rangeQuery(in[top[x]], in[x] + 1) + v;
      x = fa[top[x]];
    }
    return v;
  };

  
  while (m--) {
    int opt, x;
    std::cin >> opt >> x;
    if (opt == 1) {
      x = in[x];
      a[x] = seg.rangeQuery(x, x + 1);
      a[x].sum++;
      a[x].max++;
      seg.modify(x, a[x]);
    } else if (opt == 2) {
      int l = in[x], r = in[x] + siz[x];
      seg.rangeApply(l, r, {true});
      a[l].max = a[l].sum = -ask(x).max - 2;
      seg.modify(l, a[l]);
      // std::cerr << "AA " <<  x << " " << ask(x).max << "\n";
    } else {
      // std::cerr << x << " " << ask(x).max << "\n";
      std::cout << (ask(x).max >= 0 ? "black\n" : "white\n");
    }

    // for (int i = 1; i <= n; i++) {
    //   auto v = seg.rangeQuery(in[i], in[i] + 1);
    //   std::cerr << "EE " << i << " " << v.sum << " " << v.max << " " << v.len << "\n";
    // }
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