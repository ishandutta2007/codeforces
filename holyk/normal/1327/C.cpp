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

int n, m, k;
int main() {
  readInt(n, m, k);
  int mx = 0, my = 0;
  for (int i = 1, x, y; i <= k; i++) {
    readInt(x, y);
    smax(mx, x), smax(my, y);
  }
  std::string ans = "";
  for (int i = 1; i < mx; i++) ans += "U";
  for (int i = 1; i < my; i++) ans += "L";
  for (int i = 1; i <= n; i++) {
    char c = "LR"[i & 1];
    for (int j = 1; j < m; j++) ans += c;
    if (i < n) ans += "D";
  }
  std::cout << ans.length() << "\n" << ans;
  return 0;
}