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

int n, k, a[N];
LL f[N], g[N];
LL ask(int x, int y) {
  static int l = 1, r = 0, cnt[N];
  static LL ans;
  while (r < y) ans += cnt[a[++r]]++;
  while (r > y) ans -= --cnt[a[r--]];
  while (l < x) ans -= --cnt[a[l++]];
  while (l > x) ans += cnt[a[--l]]++;
  return ans;
}
void solve(int l, int r, int x, int y) {
  if (l > r) return;
  int mid = l + r >> 1, p;
  for (int i = x, e = std::min(mid - 1, y); i <= e; i++)
    if (smin(f[mid], g[i] + ask(i + 1, mid)))
      p = i;
  solve(l, mid - 1, x, p), solve(mid + 1, r, p, y); 
}
int main() {
  readInt(n, k);
  for (int i = 1; i <= n; i++) readInt(a[i]);
  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  for (int i = 1; i <= k; i++) {
    memcpy(g, f, sizeof f);
    memset(f, 0x3f, sizeof f);
    solve(i, n, i - 1, n);
  }
  std::cout << f[n];
  return 0;
}