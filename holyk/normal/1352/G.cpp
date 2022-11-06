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
int main() {
  int t, n; readInt(t);
  while (t--) {
    readInt(n);
    if (n <= 3) {
      puts("-1");
      continue;
    }
    std::deque<int> q;
    std::vector<bool> v(n + 1);
    q.push_back(1);
    v[1] = 1;
    while (q.size() < n) {
      int x = q.front();
      std::vector<int> di { 4, 2, 3 };
      for (auto i : di) {
        if (x + i <= n && !v[x + i]) {
          v[x + i] = 1;
          q.push_front(x + i);
          break;
        }
        if (x - i > 0 && !v[x - i]) {
          v[x - i] = 1;
          q.push_front(x - i);
          break;
        }
      }
      x = q.back();
      std::reverse(di.begin(), di.end());
      for (int i = 2; i <= 4; i++) {
        if (x + i <= n && !v[x + i]) {
          v[x + i] = 1;
          q.push_back(x + i);
          break;
        }
        if (x - i > 0 && !v[x - i]) {
          v[x - i] = 1;
          q.push_back(x - i);
          break;
        }
      }
    }
    for (auto x : q) printf("%d ", x);
    puts("");
  }
  return 0;
}