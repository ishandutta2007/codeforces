// Author:  HolyK
// Created: Wed Aug  3 13:33:52 2022
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
// 
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

int s1[N], s2[N];
void solve() {
  fa[0] = -1, cnt = 0, ch[0].fill(0);
  std::string s, t;
  std::cin >> s >> t;
  int p = 0;
  for (char c : s) p = ins(p, c - 'a'), s1[p]++;
  p = 0;
  for (char c : t) p = ins(p, c - 'a'), s2[p]++;

  std::vector<int> v(cnt);
  std::iota(v.begin(), v.end(), 1);
  std::sort(v.begin(), v.end(), [&](int i, int j) {
    return len[i] > len[j]; 
  });

  int ans = 1e9;
  for (int i : v) {
    s1[fa[i]] += s1[i];
    s2[fa[i]] += s2[i];
    if (s1[i] == 1 && s2[i] == 1) {
      smin(ans, len[fa[i]] + 1);
    }
  }
  std::cout << (ans == 1e9 ? -1 : ans) << "\n";
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