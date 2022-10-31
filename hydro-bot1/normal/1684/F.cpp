// Hydro submission #62c67302c3a9fda5622ac188@1657172738398
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Template {{{
#define REP(n) for (int _ = 0; _ < (n); _++)
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}

namespace std {
template <class Fun>
class y_combinator_result {
  Fun fun_;

  public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
}  // namespace std

#define DEBUG(x) cerr << #x << ": " << x << '\n'
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '[';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << ']';
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// }}}

// From Atcoder ACL
namespace atcoder { //{{{
  // @param n `0 <= n`
  // @return minimum non-negative `x` s.t. `n <= 2**x`
  int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
  }

  template <class S, S (*op)(S, S), S (*e)()> struct segtree {
    public:
      segtree() : segtree(0) {}
      explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
      explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
          update(i);
        }
      }

      void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
      }

      S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
      }

      S prod(int l, int r) const {
        r++; // make range [l, r] inclusive.
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
          if (l & 1) sml = op(sml, d[l++]);
          if (r & 1) smr = op(d[--r], smr);
          l >>= 1;
          r >>= 1;
        }
        return op(sml, smr);
      }

      S all_prod() const { return d[1]; }

      template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
      }
      template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
          while (l % 2 == 0) l >>= 1;
          if (!f(op(sm, d[l]))) {
            while (l < size) {
              l = (2 * l);
              if (f(op(sm, d[l]))) {
                sm = op(sm, d[l]);
                l++;
              }
            }
            return l - size;
          }
          sm = op(sm, d[l]);
          l++;
        } while ((l & -l) != l);
        return _n;
      }

      template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
      }
      template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
          r--;
          while (r > 1 && (r % 2)) r >>= 1;
          if (!f(op(d[r], sm))) {
            while (r < size) {
              r = (2 * r + 1);
              if (f(op(d[r], sm))) {
                sm = op(d[r], sm);
                r--;
              }
            }
            return r + 1 - size;
          }
          sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
      }

    private:
      int _n, size, log;
      std::vector<S> d;

      void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  };
} // namespace atcoder }}}
using atcoder::segtree;

namespace Max {
  int op(int a, int b) { return max(a, b); }
  int e() { return -2e9; }
}
namespace Min {
  int op(int a, int b) { return min(a, b); }
  int e() { return 2e9; }
}

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  map<int, vector<int>> mp;
  F0R(i, n) {
    cin >> a[i];
    mp[a[i]].push_back(i);
  }

  vector<int> prev_idx(n);
  vector<int> next_idx(n);
  for (auto& [_, v]: mp) {
    prev_idx[v[0]] = -1;
    for (int i = 1; i < sz(v); i++) {
      prev_idx[v[i]] = v[i-1];
    }

    next_idx[v.back()] = n;
    for (int i = sz(v)-2; i >= 0; i--) {
      next_idx[v[i]] = v[i+1];
    }
  }
  segtree<int, Max::op, Max::e> seg1(prev_idx);
  segtree<int, Min::op, Min::e> seg2(next_idx);

  int maxL = n-1;
  vector<pair<int,int>> vs;
  F0R(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    vs.push_back({a, b});
    if (seg2.prod(a, b) <= b) {
      int r = a;
      for (int k = 17; k >= 0; k--) {
        int nr = r + (1<<k);
        if (nr <= b && seg2.prod(a, nr) > nr) {
          r = nr;
        }
      }
      ckmin(maxL, r+1);
    }
  }

  sort(all(vs));
  int idx = 0;

  int R = -1;
  for (auto [a, b]: vs) {
    if (seg1.prod(a, b) >= a) {
      int l = b;
      for (int k = 17; k >= 0; k--) {
        int nl = l - (1<<k);
        if (nl >= a && seg1.prod(nl, b) < nl) {
          l = nl;
        }
      }
      ckmax(R, l-1);
    }
  }
  int segR = -1;
  int ans = R+1; 
  for (int L = 0; L < maxL; L++) {
    ckmax(R, L+1);
    while (idx < sz(vs) && vs[idx].first == L) {
      ckmax(segR, vs[idx].second);
      idx++;
    }

    int x = a[L];
    auto it = upper_bound(all(mp[x]), segR);
    if (it != mp[x].begin()) {
      ckmax(R, *prev(it));
    }
    ckmin(ans, R-L);
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie();
  int T; cin >> T;
  while (T--) {
    solve();
  }
}