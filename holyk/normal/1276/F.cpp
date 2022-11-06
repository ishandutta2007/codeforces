// Author:  HolyK
// Created: Sun Aug 14 15:48:34 2022
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
struct SAM {
  SAM() {
    fa[0] = -1, cnt = 0, ch[0].fill(0);
  }  
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
} s1, s2;

int node[N];
std::vector<int> g[N];
int in[N], dfn, st[20][N], lg[N];

struct Comp {
  bool operator()(const int &i, const int &j) const {
    return in[i] < in[j];
  }
};

int get(int i, int j) {
  return in[i] < in[j] ? i : j;
}
void dfs2(int x) {
  in[x] = ++dfn;
  for (int y : g[x]) {
    st[0][dfn] = x;
    dfs2(y);
  }
}
void init() {
  for (int i = 2; i <= dfn; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j + (1 << i) <= dfn; j++) {
      st[i][j] = get(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
    }
  }
}

int lca(int x, int y) {
  if (x == y) return x;
  x = in[x], y = in[y];
  if (x > y) std::swap(x, y);
  int k = lg[y - x];
  return get(st[k][x], st[k][y - (1 << k)]);
}

LL dis(int x, int y) { return s2.len[x] + s2.len[y] - 2 * s2.len[lca(x, y)]; }
std::set<int, Comp> set[N];
LL val[N];

bool vis[N];
void solve() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  for (int i = 0, p = 0; i < n; i++) {
    p = s1.ins(p, s[i] - 'a');
  }
  for (int i = n, p = 0; i; i--) {
    p = s2.ins(p, s[i - 1] - 'a');
    node[i] = p;
    // std::cerr << i << " " << node[i] << "\n";
  }

  for (int i = 1; i <= s2.cnt; i++) {
    g[s2.fa[i]].push_back(i);
  }

  dfs2(0);
  init();

  for (int i = 0, p = 0; i + 3 <= n; i++) {
    p = s1.ch[p][s[i] - 'a'];
    set[p].insert(0);
    set[p].insert(node[i + 3]);
    val[p] = s2.len[node[i + 3]] * 2;
  }

  std::vector<int> p(s1.cnt);
  std::iota(p.begin(), p.end(), 1);
  std::sort(p.begin(), p.end(), [](int i, int j) {
    return s1.len[i] > s1.len[j];
  });

  LL ans = 2;
  for (int i = 1; i <= s1.cnt; i++) {
    ans += s1.len[i] - s1.len[s1.fa[i]];
  }

  for (int i = 0, p = 0; i + 1 < n; i++) {
    p = s1.ch[p][s[i] - 'a'];
    for (int x = p; x && !vis[x]; x = s1.fa[x]) {
      vis[x] = true;
      ans += s1.len[x] - s1.len[s1.fa[x]];
    }
  }
  
  memset(vis, 0, sizeof vis);
  for (int i = 2; i <= n; i++) {
    for (int x = node[i]; x && !vis[x]; x = s2.fa[x]) {
      vis[x] = true;
      ans += s2.len[x] - s2.len[s2.fa[x]];
    }
  }
  
  for (int i : p) {
    int j = s1.fa[i];
    ans += val[i] / 2 * (s1.len[i] - s1.len[j]);
    
    if (set[i].size() > set[j].size()) {
      std::swap(set[i], set[j]);
      std::swap(val[i], val[j]);
    }
    for (int x : set[i]) {
      auto [it, ok] = set[j].insert(x);
      if (ok) {
        int pr = it == set[j].begin() ? *set[j].rbegin() : *std::prev(it);
        int ne = ++it == set[j].end() ? *set[j].begin() : *it;
        val[j] -= dis(pr, ne);
        val[j] += dis(pr, x);
        val[j] += dis(x, ne);
      }
    }
    set[i].clear();
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