// Author:  HolyK
// Created: Fri May  6 18:24:02 2022
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

constexpr int N(1e5 + 5);
struct Node {
  int ls, rs, w;
} t[N * 20];
int n, m, cnt, root[N];
void ins(int &o, int l, int r, int x) {
  t[++cnt] = t[o], t[o = cnt].w++;
  if (l == r) return;
  int m = l + r >> 1;
  if (x <= m) {
    ins(t[o].ls, l, m, x);
  } else {
    ins(t[o].rs, m + 1, r, x);
  }
}

struct Info {
  int p, q, l, r;
};
std::vector<Info> s;
void get(int p, int q, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    s.push_back({p, q, l, r}); 
    return;
  }
  int m = l + r >> 1;
  if (x <= m) get(t[p].ls, t[q].ls, l, m, x, y);
  if (y > m) get(t[p].rs, t[q].rs, m + 1, r, x, y);
}
int ask(int p, int q, int l, int r, int x) {
  if (l == r) return l;
  int m = l + r >> 1, k = m - l + 1 - (t[t[p].ls].w - t[t[q].ls].w);
  if (k >= x) {
    return ask(t[p].ls, t[q].ls, l, m, x);
  } else {
    return ask(t[p].rs, t[q].rs, m + 1, r, x - k);
  }
}

std::vector<int> g[N];
int fa[N], dep[N], top[N], in[N], siz[N], son[N], id[N], dfn;
void dfs1(int x) {
  siz[x] = 1;
  for (int y : g[x]) {
    if (y == fa[x]) continue;
    fa[y] = x;
    dep[y] = dep[x] + 1;
    dfs1(y);
    siz[x] += siz[y];
    if (siz[y] > siz[son[x]]) son[x] = y;
  }
}
void dfs2(int x) {
  in[x] = ++dfn;
  id[dfn] = x;
  if (!son[x]) return;
  top[son[x]] = top[x];
  dfs2(son[x]);
  for (int y : g[x]) {
    if (y == fa[x] || y == son[x]) continue;
    top[y] = y;
    dfs2(y);
  }
}

int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] > dep[top[y]]) {
      x = fa[top[x]]; 
    } else {
      y = fa[top[y]];
    }
  }
  return dep[x] < dep[y] ? x : y;
}

int jmp(int x, int y) {
  while (top[x] != top[y]) {
    if (fa[top[x]] == y) return top[x];
    x = fa[top[x]];
  }
  return son[y];
}

void solve() {
  std::cin >> n;
  int r = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> fa[i];
    if (!fa[i]) {
      r = i;
    } else {
      g[fa[i]].push_back(i);
    }
    
  }
  dfs1(r), top[r] = r, dfs2(r);

  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    root[i] = root[i - 1];
    int opt, x, y, k, p;
    std::cin >> opt;
    if (opt == 1) {
      std::cin >> x;
      ins(root[i], 1, n, in[x]);
    } else {
      std::cin >> x >> y >> k >> p;
      int l = lca(x, y);
      if (dep[x] + dep[y] - dep[l] * 2 - 1 < k) {
        std::cout << "-1\n";
        continue;
      }
      if (l != x && l != y) {
        x = fa[x], y = fa[y];
      } else if (l == x) {
        x = l = jmp(y, x), y = fa[y];
      } else {
        y = l = jmp(x, y), x = fa[x];
      }

      int ans = -1;
      std::vector<PII> seq;
      while (top[x] != top[l]) {
        seq.push_back({in[top[x]], in[x]});
        x = fa[top[x]];
      }
      seq.push_back({in[l], in[x]});
      for (auto [u, v] : seq) {
        s.clear();
        get(root[i], root[p], 1, n, u, v);
        std::reverse(s.begin(), s.end());
        for (auto [p, q, l, r] : s) {
          int c = r - l + 1 - (t[p].w - t[q].w);
          if (c < k) {
            k -= c;
          } else {
            ans = id[ask(p, q, l, r, c - k + 1)];
            goto print;
          }
        }
      }

      seq.clear();
      while (top[y] != top[l]) {
        seq.push_back({in[top[y]], in[y]});
        y = fa[top[y]];
      }
      if (l != y) seq.push_back({in[l] + 1, in[y]});
      std::reverse(seq.begin(), seq.end());
      for (auto [u, v] : seq) {
        s.clear();
        get(root[i], root[p], 1, n, u, v);
        for (auto [p, q, l, r] : s) {
          int c = r - l + 1 - (t[p].w - t[q].w);
          if (c < k) {
            k -= c;
          } else {
            ans = id[ask(p, q, l, r, k)];
            goto print;
          }
        }
      }
        
      print:
      std::cout << ans << "\n";
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