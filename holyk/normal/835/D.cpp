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

constexpr int N(5005);
std::array<int, 26> ch[N];
int fa[N], len[N], cnt, f[N], val[N], g[N];
char s[N], *now;
int jmp(int x) {
  for (; now[~len[x]] != *now; x = fa[x]) ;
  return x;
}
int ins(int x) { 
  static int p, np;
  if (!ch[p = jmp(p)][x]) {
    len[np = ++cnt] = len[p] + 2;
    fa[np] = ch[jmp(fa[p])][x];
    ch[p][x] = np;

    if (len[np] <= 2) {
      f[np] = fa[np];
    } else {
      for (int &i = f[np] = f[p]; now[~len[i]] != *now || (len[i] + 2 << 1) > len[np]; i = fa[i]) ;
      f[np] = ch[f[np]][x];
    }
  }
  p = ch[p][x];
  val[p]++;
  return p;
}

int ans[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  len[1] = -1;
  fa[0] = 1;
  cnt = 1;
  std::cin >> s + 1;
  now = s;
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    ins(*++now - 'a');
  }
  for (int i = cnt; i > 1; i--) val[fa[i]] += val[i];

  for (int i = 2; i <= cnt; i++) {
    if (len[i] / 2 == len[f[i]]) {
      g[i] = g[f[i]] + 1;
    } else {
      g[i] = 1;
    }
    ans[g[i]] += val[i];
  }
  for (int i = n - 1; i; i--) ans[i] += ans[i + 1];
  for (int i = 1; i <= n; i++) std::cout << ans[i] << " ";
  return 0;
}