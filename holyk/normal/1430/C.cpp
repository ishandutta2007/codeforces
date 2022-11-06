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
    int n, i; readInt(n);
    std::vector<int> a(n);
    std::vector<std::pair<int, int>> b;
    for (int i = 0; i < n; i++) a[i] = i + 1;
    while (a.size() > 1) {
      int u = a.back(); a.pop_back();
      int v = a.back(); a.pop_back();
      a.push_back(u + v + 1 >> 1);
      b.push_back({u, v});
    }
    printf("%d\n", a[0]);
    for (auto [x, y] : b) {
      printf("%d %d\n", x, y);
    }
    // if (n & 1) {
    //   printf("%d\n", n + 1 >> 1);
      
    //   for (i = 1; i * 2 < n; i++)
    //     printf("%d %d\n", i, n - i + 1);
    //   for (; i < n; i++)
    //     printf("%d %d\n", n + 1 >> 1, n + 1 >> 1);
    // } else {
    //   printf("%d\n", n >> 1);
    //   for (i = 2; i * 2 <= n; i++)
    //     printf("%d %d\n", i, n - i + 2);
    //   for (; i < n; i++)
    //     printf("%d %d\n", n + 2 >> 1, n + 2 >> 1);
    //   printf("1 %d\n", n + 2 >> 1);
    // }
  }
  return 0;
}