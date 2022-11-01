#include <bits/stdc++.h>

template<unsigned P>
class modint {
  static_assert(1 <= P);

  using mint = modint<P>;

protected:
  unsigned v;

public:
  constexpr modint() : v() {}

  template<typename T, 
           typename std::enable_if<
                    std::is_signed<T>::value
                    && std::is_integral<T>::value,
                    bool>::type = true>
  constexpr modint(T _v) : v() {
    long long tmp = _v % static_cast<long long>(P);
    if (tmp < 0) {
      tmp += P;
    }
    v = tmp;
  }

  template<typename T, 
           typename std::enable_if<
                    std::is_unsigned<T>::value
                    && std::is_integral<T>::value,
                    bool>::type = true>
  constexpr modint(T _v) : v() {
    v = _v % P;
  }

  constexpr unsigned val() const {
    return v;
  }

  static constexpr unsigned mod() {
    return P;
  }

  static constexpr mint raw(unsigned v) {
    mint res;
    res.v = v;
    return res;
  }

  constexpr mint &operator+=(const mint &rhs) {
    v < P - rhs.v ? v += rhs.v : v -= P - rhs.v;
    return *this;
  }

  constexpr mint &operator++() {
    v + 1 < P ? ++v : v = 0;
    return *this;
  }

  constexpr mint operator++(int) {
    mint tmp = *this;
    v + 1 < P ? ++v : v = 0;
    return tmp;
  }

  constexpr mint &operator-=(const mint &rhs) {
    v < rhs.v ? v += P - rhs.v : v -= rhs.v;
    return *this;
  }

  constexpr mint &operator--() {
    v == 0 ? v = P - 1 : --v;
    return *this;
  }

  constexpr mint operator--(int) {
    mint tmp = *this;
    v == 0 ? v = P - 1 : --v;
    return tmp;
  }

  constexpr mint operator-() const {
    mint res;
    res.v = v == 0 ? 0 : P - v;
    return res;
  }

  constexpr mint &operator*=(const mint &rhs) {
    v = static_cast<unsigned long long>(v) * rhs.v % P;
    return *this;
  }

  constexpr mint pow(unsigned long long b) const {
    mint a(*this), s(1);
    for (; b; b >>= 1) {
      if (b & 1) {
        s *= a;
      }
      a *= a;
    }
    return s;
  }

  constexpr mint inv() const {
    return pow(P - 2);
  }

  constexpr friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }

  constexpr friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }

  constexpr friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }

  constexpr friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs.v == rhs.v;
  }

  constexpr friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs.v != rhs.v;
  }

  friend std::istream &operator>>(std::istream &in, mint &x) {
    return in >> x.v;
  }

  friend std::ostream &operator<<(std::ostream &out, const mint &x) {
    return out << x.v;
  }
};

using mint = modint<998244353>;

std::vector<mint> pw2;

void init(int n) {
  pw2.resize(n + 1);
  pw2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pw2[i] = pw2[i - 1] + pw2[i - 1];
  }
}

class trie {
  struct node {
    node *son[2];
    int cnt;

    node() : son{}, cnt() {}
  };

  node *rt;

  mint query(node *u, node *v, int d, int x) {
    if (u == nullptr && v == nullptr) {
      return 1;
    }
    if (u == nullptr) {
      return pw2[v->cnt];
    }
    if (v == nullptr) {
      return pw2[u->cnt];
    }
    if (d < 0) {
      if (u == v) {
        return pw2[u->cnt];
      } else {
        return pw2[u->cnt + v->cnt];
      }
    }
    if (x >> d & 1) {
      if (u == v) {
        return query(u->son[0], u->son[1], d - 1, x);
      } else {
        return query(u->son[0], v->son[1], d - 1, x) *
               query(u->son[1], v->son[0], d - 1, x);
      }
    } else {
      mint tmp = 0;
      if (u != v) {
        if (u->son[0] != nullptr && u->son[1] != nullptr) {
          tmp += (pw2[u->son[0]->cnt] - 1) * (pw2[u->son[1]->cnt] - 1);
        }
        if (v->son[0] != nullptr && v->son[1] != nullptr) {
          tmp += (pw2[v->son[0]->cnt] - 1) * (pw2[v->son[1]->cnt] - 1);
        }
      }
      return query(u->son[0], v->son[0], d - 1, x) +
             query(u->son[1], v->son[1], d - 1, x) +
             tmp - 1;
    }
  }

public:
  trie() : rt() {}

  void insert(int x) {
    if (rt == nullptr) {
      rt = new node();
    };
    node *u = rt;
    ++u->cnt;
    for (int i = 29; i >= 0; --i) {
      node *&v = u->son[x >> i & 1];
      if (v == nullptr) {
        v = new node();
      }
      u = v;
      ++u->cnt;
    }
  }

  mint get_ans(int x) {
    return query(rt, rt, 29, x);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, x;
  std::cin >> n >> x;
  init(n);
  trie T;
  for (int i = 0; i < n; ++i) {
    int v;
    std::cin >> v;
    T.insert(v);
  }
  std::cout << T.get_ans(x) - 1 << "\n";
}