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

constexpr int N(1e6 + 5), P(1e9 + 7);
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
std::array<int, 26> ch[N];
int n, fa[N], len[N], cnt, top[N], g[N], dp[N];
char s[N], *now = s;
int jmp(int x) {
  while (now[~len[x]] != *now) x = fa[x];
  return x;
}
int ins(int x) {
  static int p, np;
  if (!ch[p = jmp(p)][x]) {
    len[np = ++cnt] = len[p] + 2;
    fa[np] = ch[jmp(fa[p])][x];
    ch[p][x] = np;
    top[np] = len[np] - len[fa[np]] == len[fa[np]] - len[fa[fa[np]]] ? top[fa[np]] : fa[np];
  }
  return p = ch[p][x];
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string t;
  std::cin >> t;
  n = t.length();
  if (n & 1) return puts("0"), 0;
  cnt = 1, fa[0] = 1, len[1] = -1;
  dp[0] = 1;
  int p = 0;
  for (int i = 1; i <= n; i++) dp[i] = 0;
  for (int i = 0; i < n; i++) {
    *++now = t[i & 1 ? n - 1 - i / 2 : i / 2];
    p = ins(*now - 'a');
    // if (i & 1 ^ 1) continue;
    for (; p > 1; p = top[p]) {
      g[p] = dp[i + 1 - len[top[p]] - len[p] + len[fa[p]]];
      if (len[p] - len[fa[p]] == len[fa[p]] - len[fa[fa[p]]]) {
        inc(g[p], g[fa[p]]);
      }
      if (i & 1) inc(dp[i + 1], g[p]);
    }
    // dbg("%d %d\n", i + 1, dp[i + 1]);
  }
  // dbg("%s\n", s + 1);
  std::cout << dp[n] << "\n";
  return 0;
}