// Author:  HolyK
// Created: Wed Sep 21 01:32:57 2022
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

void solve() {
  int n, k;
  std::cin >> n >> k;
  
  std::map<int, int> s;
  s[1] = 0, s[1e9 + 1] = 0;

  auto split = [&](int x) {
    auto it = --s.upper_bound(x);
    if (it->first != x) it = s.emplace(x, it->second).first;
    return it;
  };

  std::vector<int> c(n + 2);
  std::vector<PII> op;
  for (int i = 1; i <= n; i++) {
    int l, r;
    std::cin >> l >> r;

    c[i] = op.size();
    
    auto lt = split(l), rt = split(r);
    while (lt != rt) {
      op.emplace_back(lt->second + 1, std::next(lt)->first - lt->first);
      lt = s.erase(lt);
    }
    s[l] = i;
  }

  c[n + 1] = op.size();
  
  auto query = [&](int x) {
    int cnt = 0, p = 0, now = 0;
    LL sum = 0, nowsum = 0;
    std::vector<int> s(n + 2);
    auto add = [&](int x, int y) {
      if (x <= p) {
        now += y;
        nowsum += (p - x + 1LL) * y;
      } else {
        s[x] += y;
      }
    };
    
    for (int i = 1; i <= n; i++) {
      for (int j = c[i]; j < c[i + 1]; j++) {
        add(op[j].first, op[j].second);
        add(i + 1, -op[j].second);
      }

      while (p < i && now + s[p + 1] > x) {
        now += s[++p];
        nowsum += now;
      }

      cnt += p;
      sum += nowsum;
      if (cnt >= k) break;
    }

    return std::make_pair(cnt, sum);
  };

  int l = 1, r = 1e9;
  while (l < r) {
    int m = l + r >> 1;
    if (query(m).first < k) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  auto [cnt, sum] = query(l);

  std::cout << sum + 1LL * (k - cnt) * l << "\n";
}

signed main() {
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