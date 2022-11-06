#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(2e6 + 5);
std::vector<std::pair<char, int>> g[N];
int p, fa[N], len[N], cnt, dep[N], a[N];
char s[N], *now;
int jmp(int x) {
  for (; now[~len[x]] != *now; x = fa[x]) ;
  return x;
}
int get(int x, char ch) {
  for (auto [c, y] : g[x]) if (c == ch) return y;
  return 0;
}
int ins(char x) {
  now++;
  int q = get(p = jmp(p), x);
  if (!q) {
    int np = ++cnt;
    g[np].clear();
    len[np] = len[p] + 2;
    fa[np] = get(jmp(fa[p]), x);
    dep[np] = dep[fa[np]] + 1;
    g[p].emplace_back(x, np);
    p = np;
  } else {
    p = q;
  }
  return p;
}
constexpr int P(51123987);
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n >> s + 1;
  cnt = 1;
  now = s;
  fa[0] = 1;
  len[1] = -1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    inc(a[i + 1] = a[i], dep[ins(s[i])]);
    inc(ans, dep[p]);
  }
  ans = 1LL * ans * (ans - 1) / 2 % P;
  cnt = 1;
  now = s;
  p = 0;
  g[0].clear(), g[1].clear();
  std::reverse(s + 1, s + 1 + n);
  for (int i = n; i; i--) {
    ans = (ans - 1LL * a[i] * dep[ins(s[n - i + 1])]) % P;
  }
  std::cout << (ans + P) % P << "\n";
  return 0;
}