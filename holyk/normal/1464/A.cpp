#include <bits/stdc++.h>
#ifdef LOCAL
#define dbg(args...) std::cerr << "\033[32;1m" << #args << " -> ", err(args)
#else
#define dbg(...)
#endif
inline void err() { std::cerr << "\033[0m\n"; }
template<class T, class... U>
inline void err(const T &x, const U &... a) { std::cerr << x << ' '; err(a...); }
template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar());) w = w * 10 + (c & 15);
  if (p) w = -w;
}
template <class T, class... U>
inline void readInt(T &w, U &... a) { readInt(w), readInt(a...); }
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

typedef long long LL;
typedef std::pair<int, int> PII;

constexpr int N(1e5 + 5);
int fa[N];
inline int find(int x) { return fa[x] ? fa[x] = find(fa[x]) : x; }
int main() {
  int t; readInt(t);
  while (t--) {
    int n, m; readInt(n, m);
    memset(fa, 0, n + 1 << 2);
    int ans = 0;
    while (m--) {
      int x, y; readInt(x, y);
      if (x == y) continue;
      ans++;
      x = find(x), y = find(y);
      if (x == y) ans++;
      else fa[x] = y;
    }
    printf("%d\n", ans);
  }  
  return 0;
}