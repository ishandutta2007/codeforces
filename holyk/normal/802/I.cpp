// Author:  HolyK
// Created: Fri Jul 16 12:08:07 2021
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

constexpr int N(2e5 + 5);
std::array<int, 26> ch[N];
int len[N], fa[N], cnt, last, siz[N];
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
int c[N], p[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  fa[0] = -1;
  while (t--) {
    std::string s;
    std::cin >> s;
    int n = s.length();
    cnt = last = 0;
    ch[0].fill(0);
    for (char c : s) ins(c - 'a');
    memset(c, 0, sizeof c);
    for (int i = 1; i <= cnt; i++) c[len[i]]++;
    for (int i = 1; i <= n; i++) c[i] += c[i - 1];
    for (int i = 1; i <= cnt; i++) p[c[len[i]]--] = i;
    for (int i = cnt; i; i--) siz[fa[p[i]]] += siz[p[i]];
    LL ans = 0;
    // for (int i = 1; i <= cnt; i++) std::cout << siz[i] << "\n";
    for (int i = 1; i <= cnt; i++) {
      ans += 1LL * (len[i] - len[fa[i]]) * siz[i] * siz[i];
    }
    std::cout << ans << "\n";
  }
  return 0;
}
/*

 */