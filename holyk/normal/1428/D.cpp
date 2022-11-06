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

constexpr int N(1e5 + 5);
int n, a[N];
std::vector<PII> ans;
int main() {
  readInt(n);
  int now = 1;
  std::queue<int> q, p, z;
  for (int i = 1; i <= n; i++) {
    int x; readInt(x);
    switch (x) {
    case 1:
      if (!q.empty()) { 
        ans.push_back({q.front(), i}), q.pop();
      } else if (!p.empty()) {
        ans.push_back({p.front(), i}), p.pop();
        ans.push_back({now++, i});
      } else {
        ans.push_back({now++, i});
      }
      break;
    case 2:
      if (!p.empty())
        ans.push_back({p.front(), i}), p.pop();
      ans.push_back({now, i});
      q.push(now++);
      break;
    case 3:
      if (!p.empty())
        ans.push_back({p.front(), i}), p.pop();
      ans.push_back({now, i});
      p.push(now++);
      break;
    }
  }
  if (now > n + 1 || !q.empty() || !p.empty())
    return puts("-1"), 0;
  printf("%d\n", ans.size());
  for (auto [x, y] : ans) {
    printf("%d %d\n", x, y);
  }
  return 0;
}