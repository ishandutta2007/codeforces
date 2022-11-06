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
const int N(1e5 + 5);
int n, k, sx, sy, tx, ty;
PII a[N], b[N];
std::vector<PII> g[N];
std::priority_queue<PII> q;
LL d[N];
int main() {
  readInt(k, n, sx, sy, tx, ty);
  g[0].push_back({ n + 1, abs(sx - tx) + abs(sy - ty) });
  for (int i = 1, x, y; i <= n; i++) {
    readInt(x, y);
    a[i] = { x, i }, b[i] = { y, i };
    g[0].push_back({ i, std::min(abs(sx - x), abs(sy - y)) });
    g[i].push_back({ n + 1, abs(tx - x) + abs(ty - y) });
  }
  std::sort(a + 1, a + 1 + n);
  std::sort(b + 1, b + 1 + n);
  for (int i = 1; i < n; i++) {
    auto &u = a[i], &v = a[i + 1];
    int w = v.first - u.first;
    g[u.second].push_back({ v.second, w });
    g[v.second].push_back({ u.second, w });
  }
  for (int i = 1; i < n; i++) {
    auto &u = b[i], &v = b[i + 1];
    int w = v.first - u.first;
    g[u.second].push_back({ v.second, w });
    g[v.second].push_back({ u.second, w });
  }
  q.push({ 0, 0 });
  memset(d, 0x3f, sizeof d);
  d[0] = 0;
  while (!q.empty()) {
    auto u = q.top(); q.pop();
    int x = u.second;
    if (x == n + 1)
      return std::cout << d[n + 1], 0;
    if (u.first != -d[x]) continue;
    for (auto [y, z] : g[x])
      if (smin(d[y], d[x] + z))
        q.push({ -d[y], y });
  }
  return 0;
}