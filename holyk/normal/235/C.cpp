// Author:  HolyK
// Created: Fri Jul 16 15:40:11 2021
#include <bits/stdc++.h>
#define dbg(a...) fprintf(stderr, a)
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
std::array<int, 26> ch[N];
int len[N], fa[N] = {-1}, cnt, last, siz[N];
int ins(int x) {
  int p = last, np = ++cnt, q;
  ch[np].fill(0);
  siz[np] = 0;
  len[np] = len[p] + 1;
  for (; ~p && !ch[p][x]; p = fa[p]) ch[p][x] = np;
  if (p == -1) {
    fa[np] = 0;
  } else if (len[q = ch[p][x]] == len[p] + 1) {
    fa[np] = q;
  } else {
    int nq = p == last ? np : ++cnt;
    ch[nq].fill(0);
    siz[nq] = 0;
    len[nq] = len[p] + 1;
    ch[nq] = ch[q];
    for (; ~p && ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
    fa[np] = nq, fa[nq] = fa[q], fa[q] = nq;
  }
  siz[np]++;
  return last = np;
}
int c[N], p[N], vis[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s, t;
  int m;
  std::cin >> s >> m;
  for (char c : s) ins(c - 'a');
  for (int i = 1; i <= cnt; i++) c[len[i]]++;
  for (int i = 1; i <= cnt; i++) c[i] += c[i - 1];
  for (int i = 1; i <= cnt; i++) p[c[len[i]]--] = i;
  for (int i = cnt; i; i--) siz[fa[p[i]]] += siz[p[i]];
  for (int k = 1; k <= m; k++) {
    std::cin >> t;
    int n = t.length();
    t += t;
    int now = 0, p = 0;
    LL ans = 0;
    for (char c : t) {
      int x = c - 'a';
      for (; ~p && !ch[p][x]; now = len[p = fa[p]]) ;
      if (ch[p][x]) p = ch[p][x], now++;
      if (p == -1) {
        p = 0;
        continue;
      }
      for (; ~p && ~fa[p] && len[fa[p]] >= n; now = len[p = fa[p]]) ;
      if (now >= n && vis[p] != k) {
        vis[p] = k;
        ans += siz[p];
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}
/*

 */