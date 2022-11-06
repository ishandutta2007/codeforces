// Author:  HolyK
// Created: Mon Aug 22 19:09:12 2022
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

// using H = uint64_t;
struct H {
  typedef uint64_t ULL;
  ULL x;
  H(ULL x = 0) : x(x) {}
#define OP(O, A, B)                                     \
  H operator O(H o) {                                   \
    ULL r = x;                                          \
    asm(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); \
    return r;                                           \
  }
  OP(+, , "d"(o.x))
  OP(*, "mul %1\n", "r"(o.x) : "rdx")
  H operator-(H o) { return *this + ~o.x; }
  ULL get() const { return x + !~x; }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
};

void work(std::string &s) {
  int n = s.size();
  std::vector<H> h(n + 1), pw(n + 1);

  auto check = [&](int i, int j, int l) {
    return h[i + l] - h[j + l] == (h[i] - h[j]) * pw[l];
  };

  auto lcp = [&](int i, int j, int r) {
    if (i > j) std::swap(i, j);
    if (j >= n || s[i] != s[j]) return 0;
    smin(r, n - j);
    if (check(i, j, r)) return r;
    for (int l = 1; l < r; ) {
      int m = l + r + 1 >> 1;
      if (check(i, j, m)) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return r;
  };
  
  auto lcs = [&](int i, int j, int r) {
    if (i > j) std::swap(i, j);
    if (!i || s[i - 1] != s[j - 1]) return 0;
    smin(r, i);
    if (check(i - r, j - r, r)) return r;
    for (int l = 1; l < r; ) {
      int m = l + r + 1 >> 1;
      if (check(i - m, j - m, m)) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return r;
  };

  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 1331;

  auto cal = [&] {
    for (int i = 0; i < n; i++) h[i + 1] = h[i] * 1331 + s[i];
  };

  cal();

  std::vector<int> v(n);
  
  for (int p = 1; p * 2 <= n; p++) {
    bool del = false;
    for (int i = 0; i + p <= n; i += p) {
      int l = lcs(i, i + p, n), r = lcp(i, i + p, n);
      if (l + r >= p) {
        del = true;
        l = i - l, r = i + p + r;
        while (l + p * 2 <= r) {
          for (int k = 0; k < p; k++) v[k + l] = 1;
          l += p;
        }
        i = (r - 1) / p * p;
      }
    }
    
    if (del) {
      n = 0;
      for (int i = 0; i < v.size(); i++) {
        if (!v[i]) s[n++] = s[i];
      }
      s.resize(n);
      v.assign(n, 0);
      cal();
    }
  }
}

void solve() {
  std::string s;
  std::cin >> s;
  work(s);
  std::cout << s << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}