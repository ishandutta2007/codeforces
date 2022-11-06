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

constexpr int N(1e6 + 5);

LL d[N];
int id[N], ch[N][2], siz[N];

int main() {
  int n; LL k;
  readInt(n, k);
  for (int i = 2, p; i <= n; i++) {
    readInt(p, d[i]), d[i] ^= d[p];
  }
  for (int i = 1; i <= n; i++) id[i] = 1;
  LL ans = 0;
  std::vector<PII> p = { PII(1, 1) }, np;
  for (int i = 61, c = 1, nc; ~i; i--, c = nc, p.swap(np)) {
    np.clear(), nc = 0;
    for (int j = 1; j <= c; j++) ch[j][0] = ch[j][1] = 0;
    for (int j = 1; j <= n; j++) {
      int k = d[j] >> i & 1;
      if (!ch[id[j]][k]) ch[id[j]][k] = ++nc, siz[nc] = 0;
      siz[id[j] = ch[id[j]][k]]++;
    }
    LL sum = 0;
    for (auto [x, y] : p) {
      sum += 1LL * siz[ch[x][0]] * siz[ch[y][0]] + 1LL * siz[ch[x][1]] * siz[ch[y][1]];
      if (sum >= k) break;
    }
    if (sum < k) {
      k -= sum, ans |= 1LL << i;
      for (auto [x, y] : p) {
        if (ch[x][0] && ch[y][1]) np.emplace_back(ch[x][0], ch[y][1]);
        if (ch[x][1] && ch[y][0]) np.emplace_back(ch[x][1], ch[y][0]);
      }
        
    } else {
      for (auto [x, y] : p) {
        if (ch[x][0] && ch[y][0]) np.emplace_back(ch[x][0], ch[y][0]);
        if (ch[x][1] && ch[y][1]) np.emplace_back(ch[x][1], ch[y][1]);

      }
    }
  }
  std::cout << ans;
  return 0;
}