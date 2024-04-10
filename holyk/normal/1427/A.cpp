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

int main() {
  int t; readInt(t);
  while (t--) {
    LL s = 0;
    int n, x; readInt(n);
    std::vector<int> a, b;
    while (n--) {
      readInt(x);
      if (x >= 0) a.push_back(x);
      else b.push_back(x);
      s += x;
    }
    if (!s) {
      puts("NO");
      continue;
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    if (s < 0) std::swap(a, b);
    puts("YES");
    for (auto x : a) printf("%d ", x);
    for (auto x : b) printf("%d ", x);
    puts("");
  }
  return 0;
}