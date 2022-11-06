// Author:  HolyK
// Created: Wed Sep 14 17:52:35 2022
#include <bits/stdc++.h>
#include <queue>

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
  int n;
  std::cin >> n;
  std::vector<PII> a(n);
  for (int i = 0, x, y; i < n; i++) {
    std::cin >> x >> y;
    a[i] = {x + y, x};
  }
  std::sort(a.begin(), a.end());

  std::priority_queue<int> ql;
  std::priority_queue<int, std::vector<int>, std::greater<>> qr;

  ql.push(a[0].second);
  qr.push(a[0].second);
  
  LL ans = 0, offset = 0;
  for (int i = 1; i < n; i++) {
    offset += a[i].first - a[i - 1].first;
    int x = a[i].second;
    if (x < ql.top()) {
      ans += ql.top() - x;
      qr.push(ql.top() - offset);
      ql.pop();
      ql.push(x);
      ql.push(x);
    } else if (x > qr.top() + offset){
      ans -= qr.top() + offset - x;
      ql.push(qr.top() + offset);
      qr.pop();
      qr.push(x - offset);
      qr.push(x - offset);
    } else {
      ql.push(x);
      qr.push(x - offset);
    }
  }

  std::cout << ans << "\n";
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