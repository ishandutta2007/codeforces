#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
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

constexpr int N(5e5 + 5);
#define int LL
std::vector<int> p;
int a[N], b[N];
struct FenwickTree {
  int l, r, c[N], id[N], cnt;
  inline void clear(int l_, int r_) {
    l = l_, r = r_;
    ++cnt;
  }
  void add(int p, int x) {
    assert(p >= l && p <= r);
    for (p -= l - 1; p <= r - l + 1; p += p & -p) {
      if (id[p] != cnt) {
        id[p] = cnt;
        c[p] = 1e10;
      }
      smin(c[p], x);
    }
  }
  int ask(int p) {
    assert(p <= r && p >= l);
    int res = 1e10;
    for (p -= l - 1; p; p -= p & -p) {
      if (id[p] != cnt) {
        id[p] = cnt;
        c[p] = 1e10;
      }
      smin(res, c[p]);
    }
    return res;
  }
} t1, t2;
struct Data {
  int type, a, b;
  inline bool operator<(const Data &rhs) const {
    return a < rhs.a || a == rhs.a && type < rhs.type;
  }
} s[N];
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i], p.push_back(a[i]);
  for (int i = 1; i <= n; i++) std::cin >> b[i], p.push_back(b[i]);
  std::sort(p.begin(), p.end());
  p.resize(std::unique(p.begin(), p.end()) - p.begin());
  for (int i = 1; i <= n; i++) {
    a[i] = std::lower_bound(p.begin(), p.end(), a[i]) - p.begin();
    b[i] = std::lower_bound(p.begin(), p.end(), b[i]) - p.begin();
  }
  for (int i = 1; i <= n; i++) {
    s[i] = {0, a[i], b[i]};
    s[i + n] = {1, b[i], a[i]};
  }
  std::sort(s + 1, s + 1 + n + n);
  t1.clear(0, p.size()), t2.clear(-(int)p.size(), 0);
  LL ans = 0;
  for (int i = 1; i <= n + n; i++) {
    auto &[t, a, b] = s[i];
    if (t) {
      smin(ans, p[a] + p[b] + t1.ask(b) - std::abs(p[a] - p[b]));
      smin(ans, p[a] - p[b] + t2.ask(-b) - std::abs(p[a] - p[b]));
    } else {
      t1.add(b, -p[a] - p[b] - std::abs(p[a] - p[b]));
      t2.add(-b, -p[a] + p[b] - std::abs(p[a] - p[b]));
    }
    a = -a;
  }
  std::sort(s + 1, s + 1 + n + n);
  t1.clear(0, p.size()), t2.clear(-(int)p.size(), 0);
  for (int i = 1; i <= n + n; i++) {
    auto &[t, a, b] = s[i];
    a = -a;
    if (t) {
      // for (int j = 1; j < i; j++) {
      //   smin(ans, p[s[j].a] - p[a] + std::abs(p[b] - p[s[j].b]) - std::abs(p[a] - p[b]) - std::abs(p[s[j].a] - p[s[j].b]));
      // }
      smin(ans, -p[a] + p[b] + t1.ask(b) - std::abs(p[a] - p[b]));
      smin(ans, -p[a] - p[b] + t2.ask(-b) - std::abs(p[a] - p[b]));
    } else {
      t1.add(b, p[a] - p[b] - std::abs(p[a] - p[b]));
      t2.add(-b, p[a] + p[b] - std::abs(p[a] - p[b]));
    }
  }
  for (int i = 1; i <= n; i++) ans += std::abs(p[a[i]] - p[b[i]]);
  std::cout << ans << "\n";
  return 0;
}