#include <algorithm>
#include <bits/stdc++.h>
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
using Polynom = std::vector<int>;
constexpr int P(998244353);
inline int& inc(int &x, int y) { return (x += y) >= P ? x -= P : x; }
inline int& dec(int &x, int y) { return (x -= y) <  0 ? x += P : x; }
inline int sum(int x, int y) { return x + y >= P ? x + y - P : x + y; }
class FwtBase {
 public:
  FwtBase() = default;
  Polynom conv(Polynom a, Polynom b) {
    assert(a.size() == b.size());
    fwt(a), fwt(b);
    for (int i = 0; i < (int)a.size(); i++)
      a[i] = 1LL * a[i] * b[i] % P;
    ifwt(a);
    return a;
  }
  virtual ~FwtBase() = default;
 private:
  virtual void fwt(Polynom &a) {}
  virtual void ifwt(Polynom &a) {}
};
class FwtXor: public FwtBase {
  void fwt(Polynom &a) {
    int n = a.size();
    assert((n & n - 1) == 0);
    for (int k = 1; k < n; k <<= 1)
      for (int i = 0; i < n; i += k << 1)
        for (int j = 0, x, y; j < k; j++) {
          x = a[i + j], y = a[i + j + k];
          inc(a[i + j], y);
          a[i + j + k] = sum(x, P - y);
        }
  }
  void ifwt(Polynom &a) {
    int n = a.size();
    auto shift = [](int &x) { x = x & 1 ? x + P >> 1 : x >> 1; };
    for (int k = n >> 1; k; k >>= 1)
      for (int i = 0; i < n; i += k << 1)
        for (int j = 0, x, y; j < k; j++) {
          x = a[i + j], y = a[i + j + k];
          shift(inc(a[i + j], y));
          shift(a[i + j + k] = sum(x, P - y));
        }
  }
} fwt_xor;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::string s;
  int t = 1 << n;
  std::vector<int> a(m), c(t), cnt(t), min(t);
  for (int i = 0; i < n; i++) {
    std::cin >> s;
    for (int j = 0; j < m; j++) {
      a[j] |= s[j] - '0' << i;
    }
  }
  for (auto x : a) c[x]++;
  for (int i = 1; i < t; i++) {
    cnt[i] = cnt[i & i - 1] + 1;
    min[i] = std::min(cnt[i], n - cnt[i]);
  }
  c = fwt_xor.conv(c, min);
  std::cout << *std::min_element(c.begin(), c.end()) << "\n";
  return 0;
}