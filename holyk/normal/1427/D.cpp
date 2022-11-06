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

int n;
int main() {
  readInt(n);
  std::vector<int> a(n), b, pos(n);
  for (int i = 0; i < n; i++)
    readInt(a[i]), a[i]--;
  b = a;
  std::sort(b.begin(), b.end());
  std::vector<std::vector<int>> ans;
  while (a != b) {
    for (int i = 0; i < n; i++)
      pos[a[i]] = i;
    for (int i = 0, x, y, z; i + 1 < n; i++) {
      if (pos[i] < pos[i + 1]) continue;
      x = pos[i + 1], y = pos[i], z = y + 1;
      while (a[y - 1] == a[y] - 1) y--;
      std::vector<int> v;
      if (x) v.push_back(x);
      v.push_back(y - x);
      v.push_back(z - y);
      if (n - z) v.push_back(n - z);
      ans.push_back(v);
      std::reverse(a.begin(), a.begin() + x);
      std::reverse(a.begin() + x, a.begin() + y);
      std::reverse(a.begin() + y, a.begin() + z);
      std::reverse(a.begin() + z, a.end());
      std::reverse(a.begin(), a.end());
      break;
    }
  }
  printf("%d\n", ans.size());
  for (auto &u : ans) {
    printf("%d", u.size());
    for (auto &v : u) printf(" %d", v);
    puts("");
  }
  return 0;
}