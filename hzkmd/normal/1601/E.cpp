#include <bits/stdc++.h>

template<typename Val,
         typename VV = std::plus<>,
         typename Tag = Val,
         typename VT = std::plus<>,
         typename TT = std::plus<>,
         typename Comp = std::less<>>
class lazy_seg_tree {
public:
  typedef std::size_t size_type;

private:
  constexpr static size_type enlarge(size_type n) {
    size_type res = 1;
    while (res < n) {
      res <<= 1;
    }
    return res;
  }

protected:
  const size_type n, en;

  VV fun_vv;
  VT fun_vt;
  TT fun_tt;
  Comp comp;

  std::vector<Val> val;
  std::vector<Tag> tag;

  void up(size_type u) {
    val[u] = fun_vv(val[u << 1], val[u << 1 | 1]);
  }

  void apply(size_type u, const Tag &v) {
    val[u] = fun_vt(val[u], v);
    tag[u] = fun_tt(tag[u], v);
  }

  void down(size_type u) {
    apply(u << 1, tag[u]);
    apply(u << 1 | 1, tag[u]);
    tag[u] = Tag();
  }

  template<typename T>
  void build(size_type u, size_type l, size_type r, 
             const std::vector<T> &a) {
    if (l + 1 == r) {
      val[u] = Val(a[l]);
      return;
    }
    size_type mid = (l + r) >> 1;
    build(u << 1, l, mid, a);
    build(u << 1 | 1, mid, r, a);
    up(u);
  }

  void modify(size_type u, size_type l, size_type r, 
              size_type x, const Val &v) {
    if (l + 1 == r) {
      val[u] = v;
      return;
    }
    size_type mid = (l + r) >> 1;
    down(u);
    if (x < mid) {
      modify(u << 1, l, mid, x, v);
    } else {
      modify(u << 1 | 1, mid, r, x, v);
    }
    up(u);
  }

  void modify(size_type u, size_type l, size_type r, 
              size_type L, size_type R, const Tag &v) {
    if (L <= l && r <= R) {
      apply(u, v);
      return;
    }
    size_type mid = (l + r) >> 1;
    down(u);
    if (L < mid) {
      modify(u << 1, l, mid, L, R, v);
    }
    if (mid < R) {
      modify(u << 1 | 1, mid, r, L, R, v);
    }
    up(u);
  }

  Val query(size_type u, size_type l, size_type r, 
            size_type L, size_type R) {
    if (L <= l && r <= R) {
      return val[u];
    }
    size_type mid = (l + r) >> 1;
    down(u);
    if (R <= mid) {
      return query(u << 1, l, mid, L, R);
    } else if (L >= mid) {
      return query(u << 1 | 1, mid, r, L, R);
    } else {
      return fun_vv(query(u << 1, l, mid, L, R), 
                    query(u << 1 | 1, mid, r, L, R));
    }
  }

  size_type lower_bound(size_type u, size_type l, size_type r, 
                        size_type L, size_type R,
                        Val &pre, const Val &v) {
    if (L <= l && r <= R) {
      const Val &tmp = fun_vv(pre, val[u]);
      if (comp(tmp, v)) {
        pre = tmp;
        return r;
      }
    }
    if (l + 1 == r) {
      return l;
    }
    size_type mid = (l + r) >> 1;
    down(u);
    if (R <= mid) {
      return lower_bound(u << 1, l, mid, L, R, pre, v);
    } else if (L >= mid) {
      return lower_bound(u << 1 | 1, mid, r, L, R, pre, v);
    } else {
      size_type res = lower_bound(u << 1, l, mid, L, R, pre, v);
      if (res < mid) {
        return res;
      } else {
        return lower_bound(u << 1 | 1, mid, r, L, R, pre, v);
      }
    }
  }

  size_type upper_bound(size_type u, size_type l, size_type r, 
                        size_type L, size_type R,
                        Val &pre, const Val &v) {
    if (L <= l && r <= R) {
      const Val &tmp = fun_vv(pre, val[u]);
      if (!comp(v, tmp)) {
        pre = tmp;
        return r;
      }
    }
    if (l + 1 == r) {
      return l;
    }
    size_type mid = (l + r) >> 1;
    down(u);
    if (R <= mid) {
      return upper_bound(u << 1, l, mid, L, R, pre, v);
    } else if (L >= mid) {
      return upper_bound(u << 1 | 1, mid, r, L, R, pre, v);
    } else {
      size_type res = upper_bound(u << 1, l, mid, L, R, pre, v);
      if (res < mid) {
        return res;
      } else {
        return upper_bound(u << 1 | 1, mid, r, L, R, pre, v);
      }
    }
  }

public:
  lazy_seg_tree() : lazy_seg_tree(0) {}

  lazy_seg_tree(size_type _n)
  : n(_n), en(enlarge(n)), val(en << 1), tag(en << 1) {}

  template<typename T>
  lazy_seg_tree(const std::vector<T> &a)
  : n(a.size()), en(enlarge(n)), val(en << 1), tag(en << 1) {
    if (n) {
      build(1, 0, n, a);
    }
  }

  size_type size() const {
    return n;
  }

  void modify(size_type x, const Val &v) {
    modify(1, 0, n, x, v);
  }

  void modify(size_type l, size_type r, const Tag &v) {
    if (l < r) {
      modify(1, 0, n, l, r, v);
    }
  }

  Val query(size_type l, size_type r) {
    if (l < r) {
      return query(1, 0, n, l, r);
    } else {
      return Val();
    }
  }

  size_type lower_bound(size_type l, size_type r, Val E, const Val &v) {
    return lower_bound(1, 0, n, l, r, E, v);
  }

  size_type upper_bound(size_type l, size_type r, Val E, const Val &v) {
    return upper_bound(1, 0, n, l, r, E, v);
  }
};

struct node {
  int l, r;
  long long sum;

  node() : l(), r(), sum() {}

  node(int i) : l(i), r(i + 1), sum() {}

  node(int _l, int _r, long long _sum) : l(_l), r(_r), sum(_sum) {}

  node operator+(const node &rhs) const {
    return node(l, rhs.r, sum + rhs.sum);
  }

  node operator+(int v) const {
    if (v == 0) {
      return *this;
    }
    return node(l, r, 1ll * v * (r - l));
  }
};

template<typename T>
struct cover {
  const T &operator()(const T &a, const T &b) const {
    return b == 0 ? a : b;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q, L;
  std::cin >> n >> q >> L;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int C = n / L + 1;
  std::vector<std::vector<std::vector<std::pair<int, int>>>> qu(L,
    std::vector<std::vector<std::pair<int, int>>>(C));
  for (int i = 0; i < q; ++i) {
    int l, r;
    std::cin >> l >> r;
    --l;
    qu[l % L][l / L].emplace_back(l / L + (r - l - 1) / L, i);
  }

  std::vector<std::vector<int>> val(L, std::vector<int>(C));
  std::vector<int> Q;
  int h = 0;

  auto push = [&](int x) {
    while (h < (int)Q.size() && a[Q.back()] >= a[x]) {
      Q.pop_back();
    }
    Q.push_back(x);
  };

  auto pop = [&](int x) {
    while (h < (int)Q.size() && Q[h] >= x) {
      ++h;
    }
    return Q[h];
  };

  for (int i = n - 1; i >= 0; --i) {
    push(i);
    val[i % L][i / L] = a[pop(i + L + 1)];
  }

  std::vector<node> tmp(C);
  for (int i = 0; i < C; ++i) {
    tmp[i] = node(i);
  }

  std::vector<long long> ans(q);
  for (int t = 0; t < L; ++t) {
    std::vector<int> sta;
    lazy_seg_tree<node, std::plus<>, int, std::plus<>, cover<int>> T(tmp);
    for (int i = C - 1; i >= 0; --i) {
      while (!sta.empty() && val[t][sta.back()] >= val[t][i]) {
        sta.pop_back();
      }
      T.modify(i, sta.empty() ? C : sta.back(), val[t][i]);
      sta.push_back(i);
      for (auto [r, id] : qu[t][i]) {
        ans[id] = a[i * L + t] + T.query(i, r).sum;
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    std::cout << ans[i] << "\n";
  }
}