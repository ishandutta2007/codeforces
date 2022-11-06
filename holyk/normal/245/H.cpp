// Author:  HolyK
// Created: Sat Dec 11 12:46:41 2021
#include <bits/stdc++.h>
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

constexpr int N(10005);
char s[N], *now = s;
std::array<int, 26> ch[N];
int fa[N], len[N], cnt;
int jmp(int x) {
  for (; now[~len[x]] != *now; x = fa[x]) ;
  return x; 
}
int ins(int x) {
  static int p, q;
  now++;
  if (!ch[p = jmp(p)][x]) {
    len[q = ++cnt] = len[p] + 2;
    fa[q] = ch[jmp(fa[p])][x];
    ch[p][x] = q;
  }
  return p = ch[p][x];
}
std::vector<PII> q[N];
int n, m, ans[1000005], c[N];
void add(int p, int x) {
  for (; p; p -= p & -p) {
    c[p] += x;
  }
}
int ask(int p) {
  int r = 0;
  for (; p <= n; p += p & -p) r += c[p];
  return r;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> s + 1 >> m;
  n = strlen(s + 1);
  for (int i = 1; i <= m; i++) {
    int l, r;
    std::cin >> l >> r;
    q[r].push_back({l, i});
  }
  fa[0] = 1;
  len[1] = -1;
  cnt = 1;
  for (int i = 1; i <= n; i++) {
    int p = ins(s[i] - 'a');
    for (; p > 1; p = fa[p]) {
      add(i - len[p] + 1, 1);
    }
    for (auto &u : q[i]) {
      ans[u.second] = ask(u.first);
    }
  }
  for (int i = 1; i <= m; i++) {
    std::cout << ans[i] << "\n";
  }
  return 0;
}