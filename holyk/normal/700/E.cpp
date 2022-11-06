// Author:  HolyK
// Created: Fri Aug 12 14:27:11 2022
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

constexpr int N(4e5 + 5);
std::array<int, 26> ch[N];
int len[N], fa[N], cnt, pos[N];

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
    pos[nq] = pos[q];
    
    for (; ~p && ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
    fa[np] = nq;
    fa[nq] = fa[q];
    fa[q] = nq;    
  }
  return np;
}


struct Node {
  int ls, rs, w;
} t[N * 20];
int tn;
void ins(int &o, int l, int r, int x) {
  if (!o) o = ++tn;
  t[o].w++;
  if (l == r) return;
  int m = l + r >> 1;
  if (x <= m) {
    ins(t[o].ls, l, m, x);
  } else {
    ins(t[o].rs, m + 1, r, x);
  }
}

int merge(int x, int y) {
  if (!x) return y;
  if (!y) return x;
  int z = ++tn;
  t[z] = {
    merge(t[x].ls, t[y].ls),
    merge(t[x].rs, t[y].rs),
    t[x].w + t[y].w
  };
  return z;
}

int ask(int o, int l, int r, int x, int y) {
  if (!o || r < x || y < l) return 0;
  if (x <= l && r <= y) return t[o].w;
  int m = l + r >> 1;
  return ask(t[o].ls, l, m, x, y) || ask(t[o].rs, m + 1, r, x, y);
}

std::vector<int> g[N];
int n, root[N], dp[N];
void dfs1(int x) {
  for (int y : g[x]) {
    dfs1(y);
    root[x] = merge(root[x], root[y]);
  }
}

void dfs2(int x, int p) {
  if (!p || x && ask(root[p], 1, n, pos[x] - len[x] + len[p], pos[x] - 1)) {
    dp[x] = dp[p] + 1;
    p = x;
  }
  if (!x) p = 0;
  for (int y : g[x]) {
    dfs2(y, p);
  }
}

void solve() {
  fa[0] = -1, cnt = 0, ch[0].fill(0);
  std::string s;
  std::cin >> n >> s;
  for (int i = 0, p = 0; i < n; i++) {
    p = ins(p, s[i] - 'a');
    pos[p] = i + 1;
    ins(root[p], 1, n, i + 1);
  }

  for (int i = 1; i <= cnt; i++) {
    g[fa[i]].push_back(i);
  }

 
  dfs1(0), dfs2(0, -1);

  std::cout << *std::max_element(dp + 1, dp + cnt + 1) << "\n";
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