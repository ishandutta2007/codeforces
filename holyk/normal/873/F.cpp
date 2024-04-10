// Author:  HolyK
// Created: Fri Aug 19 16:49:37 2022
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

constexpr int N(2e6 + 5);
std::array<int, 26> ch[N];
int len[N], fa[N], cnt;

int ins(int last, int x) {
  if (ch[last][x] && len[last] + 1 == len[ch[last][x]]) return ch[last][x];
  int p = last, np = ++cnt, q;
  len[np] = len[p] + 1;
  ch[np].fill(0);
  for (; ~p && !ch[p][x]; p = fa[p]) ch[p][x] = np;
  if (p == -1) {
    fa[np] = 0;
  } else if (len[q = ch[p][x]] == len[p] + 1) {
    fa[np] = q;
  } else {
    int nq = p == last ? np : ++cnt;
    len[nq] = len[p] + 1;
    ch[nq].fill(0);
    ch[nq] = ch[q];
    for (; ~p && ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
    fa[np] = nq;
    fa[nq] = fa[q];
    fa[q] = nq;    
  }
  return np;
}

int siz[N];
void solve() {
  fa[0] = -1, cnt = 0, ch[0].fill(0);
  int n;
  std::string s, t;
  std::cin >> n >> s >> t;

  for (int i = 0, p = 0; i < n; i++) {
    p = ins(p, s[i] - 'a');
    if (t[i] == '0') {
      siz[p]++;
    }
  }

  std::vector<int> p(cnt);
  std::iota(p.begin(), p.end(), 1);
  std::sort(p.begin(), p.end(), [&](int i, int j) {
    return len[i] > len[j];
  });

  LL ans = 0;
  for (int i : p) {
    siz[fa[i]] += siz[i];
    smax(ans, 1LL * len[i] * siz[i]);
  }
  std::cout << ans << "\n";                 
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}