// Author:  HolyK
// Created: Wed Aug  3 13:57:05 2022
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
constexpr int N(2e5 + 5);
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

std::vector<int> a[N];
int vis[N], sum[N];
LL ans[N];
void solve() {
  fa[0] = -1, cnt = 0, ch[0].fill(0);
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::string s;
    std::cin >> s;
    int p = 0;
    for (char c : s) {
      p = ins(p, c - 'a');
      a[i].push_back(p);
    }
  }
  for (int i = 1; i <= n; i++) {
    a[0].clear();
    for (int j : a[i]) {
      for (int x = j; vis[x] != i; x = fa[x]) {
        sum[x]++;
        vis[x] = i;
      }
    }
  }

  std::vector<int> p(cnt);
  std::iota(p.begin(), p.end(), 1);
  std::sort(p.begin(), p.end(), [](int i, int j) {
    return len[i] < len[j];
  });
  for (int i : p) {
    ans[i] = ans[fa[i]];
    if (sum[i] >= m) {
      ans[i] += len[i] - len[fa[i]];
    }
  }
  for (int i = 1; i <= n; i++) {
    LL r = 0;
    for (int j : a[i]) {
      r += ans[j];
    }
    std::cout << r << " \n"[i == n];
  }
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