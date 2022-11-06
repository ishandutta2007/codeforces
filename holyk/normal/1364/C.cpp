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
  int n; readInt(n);
  std::vector<int> a(n), b(n + 1);
  std::set<int> v;
  for (int i = 0; i < n; i++) readInt(a[i]), v.insert(i);
  for (int i = 1; i < n; i++)
    if (a[i] < a[i - 1])
      return puts("-1"), 0;
  v.insert(n);
  for (int i = n - 1; i >= 0; i--) {
    auto t = v.find(a[i]);
    if (t != v.end()) {
      v.erase(t);
      b[i + 1] = a[i];
    } else {
      t = --v.end();
      if (*t == a[i]) return puts("-1"), 0;
      b[i + 1] = *t;
      v.erase(t);
    }
  }
  b[0] = *v.begin();
  for (int i = 0; i < n; i++)
    printf("%d ", b[i]);
  return 0;
}