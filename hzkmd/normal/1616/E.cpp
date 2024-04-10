#include <bits/stdc++.h>

template<typename Val, 
         typename VV = std::plus<Val>>
class fenwick_tree {
public:
  typedef std::size_t size_type;

protected:
  const Val E;

  size_type n;
  std::vector<Val> val;

  VV fun;

public:
  fenwick_tree() : fenwick_tree(0) {}

  fenwick_tree(size_type _n)
  : E(), n(_n), val(n + 1, E) {}

  fenwick_tree(size_type _n, const Val &_E)
  : E(_E), n(_n), val(n + 1, E) {}

  size_type size() const {
    return n;
  }

  void modify(size_type x, const Val &v) {
    for (++x; x <= n; x += x & -x) {
      val[x] = fun(val[x], v);
    }
  }

  Val query(size_type x) {
    Val s = E;
    for (; x; x ^= x & -x) {
      s = fun(s, val[x]);
    }
    return s;
  }
};

constexpr long long INF = std::numeric_limits<long long>::max() / 2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    std::vector<int> pos[26];
    for (int i = 0; i < n; ++i) {
      pos[a[i] - 'a'].push_back(i);
    }
    std::size_t h[26] = {};
    fenwick_tree<int> T(n);
    for (int i = 0; i < n; ++i) {
      T.modify(i, 1);
    }
    long long ans = INF;
    long long now = 0;
    for (int i = 0; i < n; ++i) {
      int c = b[i] - 'a';
      for (int j = 0; j < c; ++j) {
        if (h[j] < pos[j].size()) {
          ans = std::min(ans, now + T.query(pos[j][h[j]]));
        }
      }
      if (h[c] < pos[c].size()) {
        now += T.query(pos[c][h[c]]);
        T.modify(pos[c][h[c]], -1);
        ++h[c];
      } else {
        break;
      }
    }
    if (ans == INF) {
      std::cout << -1 << "\n";
    } else {
      std::cout << ans << "\n";
    }
  }
}