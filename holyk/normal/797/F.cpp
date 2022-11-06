#include <bits/stdc++.h>
#include <numeric>
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

struct Info {
  LL val;
  mutable int cnt;
  bool operator<(const Info &r) const {
    return val > r.val;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> x(n), y(m), w(m), c(m);
  for (int &v : x) std::cin >> v;
  std::sort(x.begin(), x.end());
  for (int i = 0; i < m; i++) std::cin >> y[i] >> c[i], w[i] = i;
  std::sort(w.begin(), w.end(), [&](int i, int j) {
    return y[i] < y[j];
  });
  if (std::accumulate(c.begin(), c.end(), 0LL) < n) return puts("-1"), 0;
  std::priority_queue<Info> p, q;
  LL ans = 0;
  for (int i = 0, j = 0; i < n || j < m; ) {
    if (j == m || i < n && x[i] < y[w[j]]) {
      LL cost = 2e9;
      if (!q.empty()) {
        cost = x[i] + q.top().val;
        if (--q.top().cnt == 0) q.pop();
      }
      ans += cost;
      p.push({-x[i] - cost, 1});
      i++;
    } else {
      int cnt = 0;
      while (cnt < c[w[j]] && !p.empty()) {
        LL cost = y[w[j]] + p.top().val;
        if (cost >= 0) break;
        int f = std::min(c[w[j]] - cnt, p.top().cnt);
        cnt += f, p.top().cnt -= f;
        ans += f * cost;
        q.push({-y[w[j]] - cost, f});  
        if (!p.top().cnt) p.pop();
      }
      if (cnt) p.push({-y[w[j]], cnt});
      if (cnt < c[w[j]]) q.push({-y[w[j]], c[w[j]] - cnt});
      j++;
    }
  } 
  std::cout << ans << "\n";
  return 0;
}