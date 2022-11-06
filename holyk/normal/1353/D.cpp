#include <bits/stdc++.h>

template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar()); w = w * 10 + (c & 15));
  if (p) w = -w;
}
template <class T, class... Args>
inline void readInt(T &w, Args &... args) { readInt(w), readInt(args...); }
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
typedef long long LL;
typedef std::pair<int, int> PII;
constexpr int N(2e5 + 5);

int main() {
  int t, n; readInt(t);
  while (t--) {
    readInt(n);
    std::vector<int> a(n + 1, 0);
    std::priority_queue<PII> q;
    q.push({n, -1});
    while (q.size()) {
      auto [x, l] = q.top(); q.pop();
      l = -l;
      int r = l + x - 1, m = l + r >> 1;
      a[m] = ++a[0];
      if (m > l) q.push({m - l, -l});
      if (r > m) q.push({r - m, -m - 1});
    }
    for (int i = 1; i <= n; i++)
      printf("%d ", a[i]);
    puts("");
  }
  return 0;
}