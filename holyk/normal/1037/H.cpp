// Author:  HolyK
// Created: Wed Aug  3 14:43:15 2022
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

constexpr int N(6e5 + 5);
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

std::string s, t[N];
int n, m, node[N], ans[N], f[20][N];
std::vector<int> g[N];
int in[N], dfn, id[N];
void dfs(int x) {
  in[x] = dfn++;
  id[in[x]] = x;
  for (int y : g[x]) {
    dfs(y);
  }
}
void solve() {
  fa[0] = -1, cnt = 0, ch[0].fill(0);
  std::cin >> s >> m;
  n = s.length();
  memset(pos, -1, sizeof pos);
  for (int i = n - 1, p = 0; i >= 0; i--) {
    p = ins(p, s[i] - 'a');
    pos[p] = i;
    node[i] = p;
  }
  std::vector<std::array<int, 5>> q(m);
  for (int i = 0; i < m; i++) {
    int l, r;
    std::cin >> l >> r >> t[i];
    int cur = s.length(), p = 0;
    s += t[i];
    for (int j = s.length() - 1; j >= cur; j--) {
      p = ins(p, s[j] - 'a');
      pos[p] = j;
    }
    int k = t[i].length();
    q[i] = {p, l - 1, r, k, i};
  }

  for (int i = 1; i <= cnt; i++) assert(pos[i] != -1);
  
  std::vector<int> p(cnt);
  std::iota(p.begin(), p.end(), 1);
  std::sort(p.begin(), p.end(), [](int i, int j) {
    return s[pos[i] + len[fa[i]]] < s[pos[j] + len[fa[j]]];
  });
  for (int i : p) g[fa[i]].push_back(i);

  dfs(0);
  for (auto &v : q) v[0] = in[v[0]];
  std::sort(q.rbegin(), q.rend());

  int nn = 1 << std::__lg(n * 2 - 1);
  std::vector<int> t(nn * 2, 1e9);
  p.resize(n);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [](int i, int j) {
    return in[node[i]] > in[node[j]];
  });

  for (int i = 1; i <= cnt; i++) {
    f[0][in[i]] = in[fa[i]];
  }
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= cnt; j++) {
      f[i][j] = f[i - 1][f[i - 1][j]];
    }
  }

  // for (int i = 0; i < n; i++) {
  //   std::cerr << s[pos[node[i]]];
  // }
  // std::cerr << "\n";
  
  for (int i = 0, j = 0; i < m; i++) {
    for (; j < n && in[node[p[j]]] > q[i][0]; j++) {
      int v = in[node[p[j]]];
      for (int x = p[j] + nn; x; x >>= 1) {
        t[x] = v;
      }
    }
    auto &[p, x, y, k, ii] = q[i];
    int &res = ans[ii] = 1e9, l = x, r = y;
    if (r - l > k) {
      for (l += nn, r += nn - k; l < r; l >>= 1, r >>= 1) {
        if (l & 1) smin(res, t[l++]);
        if (r & 1) smin(res, t[--r]);
      }
      if (res != 1e9) {
        for (int t = 19; t >= 0; t--) {
          if (f[t][res] > p) res = f[t][res];
        }
      }
    }

    l = x, r = y;
    for (int z =  std::max(l, r - k); z < r; z++) {
      int o = in[node[z]];
      if (o <= p) continue;
      for (int t = 19; t >= 0; t--) {
        if (f[t][o] > p) o = f[t][o];
      }
      if (z + len[fa[id[o]]] < r) {
        smin(res, o);
      }
    }
  }
  
  for (int i = 0; i < m; i++) {
    if (ans[i] == 1e9) {
      std::cout << "-1\n";
    } else {
      int p = id[ans[i]];
      std::cout << s.substr(pos[p], len[fa[p]] + 1) << "\n";
    }
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