// Author:  HolyK
// Created: Fri Aug 12 12:52:41 2022
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

constexpr int N(1e6 + 5);
std::array<int, 2> ch[N];
int len[N], fa[N], cnt, pos[N];

int ins(int last, int x) {
  int p = last, np = ++cnt, q;
  len[np] = len[p] + 1;
  ch[np].fill(0);
  for (; ~p && !ch[p][x]; p = fa[p]) ch[p][x] = np;
  if (p == -1) {
    fa[np] = 0;
  } else if (len[q = ch[p][x]] == len[p] + 1) {
    fa[np] = q;
  } else {
    int nq = ++cnt;
    len[nq] = len[p] + 1;
    ch[nq].fill(0);
    ch[nq] = ch[q];
    pos[nq] = pos[q];
    
    for (; ~p && ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
    fa[np] = nq;
    fa[nq] = fa[q];
    fa[q] = nq;    
  }
  return np;
}

void solve() {
  fa[0] = -1, cnt = 0, ch[0].fill(0);

  int n;
  std::string s;
  std::cin >> n >> s;

  std::vector<int> sum(n + 1);
  
  for (int i = 0, p = 0; i < n; i++) {
    p = ins(p, s[i] == ')');
    pos[p] = i + 1;

    sum[i + 1] = sum[i] + (s[i] == ')' ? -1 : 1);
  }

  // for (int i = 0; i <= n; i++) {
  //   std::cerr << sum[i] << " \n"[i == n];
  // }
  
  std::vector<int> stk = {0}, l(n + 1);
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && sum[stk.back()] >= sum[i]) {
      stk.pop_back();
    }

    if (!stk.empty()) {
      l[i] = stk.back() + 1;
    }

    stk.push_back(i);
  }

  std::vector<std::vector<int>> ps(n + n + 1);
  for (int i = 0; i <= n; i++) {
    ps[sum[i] + n].push_back(i);
  }

  LL ans = 0;
  for (int i = 1; i <= cnt; i++) {
    int p = pos[i], x = std::max(l[p], p - len[i]), y = p - len[fa[i]] - 1;
    if (x <= y) {
      auto &v = ps[sum[p] + n];
      ans += std::upper_bound(v.begin(), v.end(), y) - std::lower_bound(v.begin(), v.end(), x);

      // std::cerr << "! " << p - len[i] + 1 << " " << p - len[fa[i]] << " " << p << " " << std::upper_bound(v.begin(), v.end(), y) - std::lower_bound(v.begin(), v.end(), x) << "\n"; 
    }
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