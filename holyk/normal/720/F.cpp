// Author:  HolyK
// Created: Sat Jul 30 10:56:05 2022
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using LLL = __int128_t;
using PII = std::pair<int, int>;

template <class T>
struct FenwSum {
  std::vector<T> c;
  FenwSum(int n) : c(n) {}
  void clear() { std::fill(c.begin(), c.end(), 0); }
  void add(int p, T x) {
    for (; p < c.size(); p |= p + 1) c[p] += x;
  }
  T ask(int p) {
    T r = 0;
    for (; p; p &= p - 1) r += c[p - 1];
    return r;
  }
};

template <class T>
struct FenwMin {
  std::vector<T> c;
  FenwMin(int n) : c(n, std::numeric_limits<T>().max()) {}
  void clear() { std::fill(c.begin(), c.end(), std::numeric_limits<T>().max()); }
  void add(int p, T x) {
    for (; p < c.size(); p |= p + 1) smin(c[p], x);
  }
  T ask(int p) {
    T r = std::numeric_limits<T>().max();
    for (; p; p &= p - 1) smin(r, c[p - 1]);
    return r;
  }
};

template <class T>
struct FenwMax {
  std::vector<T> c;
  FenwMax(int n) : c(n) {}
  void clear() { std::fill(c.begin(), c.end()); }
  void add(int p, T x) {
    for (; p < c.size(); p |= p + 1) smax(c[p], x);
  }
  T ask(int p) {
    T r;
    for (; p; p &= p - 1) smax(r, c[p - 1]);
    return r;
  }
};

struct Info {
  LL sum = -1e16, cnt = 0;
  bool operator<(const Info &r) const {
    return sum < r.sum || sum == r.sum && cnt < r.cnt;
  }
};
constexpr int N(1e5 + 5);
int n, a[N], sid[N], left[N];
LL s[N], mins[N];
Info f[N];

std::vector<LL> vs;

std::pair<LLL, LL> cal(LL k) {
  LLL ans = 0;
  LL c = 0;
  {
    FenwMin<int> pos(vs.size());
    FenwSum<LL> sum(vs.size());
    FenwSum<int> cnt(vs.size());
    for (int i = 1; i <= n; i++) {
      pos.add(sid[i - 1], i);
      sum.add(sid[i - 1], s[i - 1]);
      cnt.add(sid[i - 1], 1);
      int p = std::upper_bound(vs.begin(), vs.end(), s[i] + k) - vs.begin();
      left[i] = std::min(i + 1, pos.ask(p));
      int v = cnt.ask(p);
      c += v;
      ans += (s[i] + k) * v - sum.ask(p);
    }
  }

  {
    FenwMax<Info> dp(n + 1), dps(n + 1);
    auto add = [&](int i) {
      dp.add(n - i, f[i]);
      dps.add(i, {f[i].sum - mins[i], f[i].cnt});
    };
    f[0] = {0, 0};
    add(0);
    for (int i = 1; i <= n; i++) {
      auto u = dp.ask(n - left[i] + 2), v = dps.ask(left[i] - 1);
      v.sum += s[i] + k;
      v.cnt++;
      f[i] = std::max(u, v);
      add(i);
    }
  }

  return {ans + f[n].sum, c + f[n].cnt};
}

void solve() {
  LL k;
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s[i] = a[i] + s[i - 1];
    mins[i] = std::min(mins[i - 1], s[i]);
  }
  vs.assign(s, s + n + 1);
  std::sort(vs.begin(), vs.end());
  vs.erase(std::unique(vs.begin(), vs.end()), vs.end());

  for (int i = 0; i <= n; i++) {
    sid[i] = std::lower_bound(vs.begin(), vs.end(), s[i]) - vs.begin();
  }

  LL l = -5e9, r = 5e9;
  while (l < r) {
    LL m = l + r >> 1;
    if (cal(m).second >= k) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  
  auto ans = cal(l).first - (LLL)k * l;
  if (ans == 0) {
    std::cout << "0\n";
  } else {
    if (ans < 0) std::cout << "-", ans = -ans;
    std::string s;
    while (ans) s += char(ans % 10 + '0'), ans /= 10;
    std::reverse(s.begin(), s.end());
    std::cout << s << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}