// Author:  HolyK
// Created: Fri Sep 16 11:05:08 2022
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

#include <ext/pb_ds/assoc_container.hpp>
template <class T, class U = __gnu_pbds::null_type, class Comp = std::less<T>>
using Tree = __gnu_pbds::tree<T, U, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

constexpr int N(1.5e5 + 5);
int n, m, k;
std::vector<int> g[N];

int in[N], id[N], dfn, siz[N], son[N], top[N], dep[N], fa[N];
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

int st[18][N], lg[N];
int get(int i, int j) {
  return in[i] < in[j] ? i : j;
}
int lca(int x, int y) {
  if (x == y) return x;
  x = in[x], y = in[y];
  if (x > y) std::swap(x, y);
  int k = lg[y - x];
  return get(st[k][x], st[k][y - (1 << k)]);
}

void dfs2(int x) {
  st[0][dfn] = fa[x];
  in[x] = ++dfn, id[in[x]] = x;
  if (!son[x]) return;
  top[son[x]] = top[x];
  dfs2(son[x]);
  for (int y : g[x]) {
    if (y == fa[x] || y == son[x]) continue;
    top[y] = y, dfs2(y);
  }
}

void init() {
  // int r = 1;
  int r = std::random_device{}() % n + 1;
  dfs1(r), top[r] = r, dfs2(r);
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i < 18; i++) {
    for (int j = 1; j + (1 << i) <= n; j++) {
      st[i][j] = get(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
    }
  }
}

int jmp(int x, int k) {
  while (fa[top[x]] && dep[fa[top[x]]] >= k) {
    x = fa[top[x]];
  }
  // assert(dep[x] >= k);
  int l = in[top[x]], r = in[x];
  while (l < r) {
    int m = l + r >> 1;
    if (dep[id[m]] >= k) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return id[l];
}

std::vector<PII> ch[N];
int c[N], d[N];
void add(int p, int x) {
  d[p] += x;
  for (; p <= n; p += p & -p) c[p] += x;
}
int ask(int l, int r) {
  int ans = 0;
  for (; r; r -= r & -r) ans += c[r];
  for (l--; l; l -= l & -l) ans -= c[l];
  return ans;
}

Tree<PII> s[N];
void solve() {
  std::cin >> n >> m >> k;
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  init();
  
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    if (in[x] > in[y]) std::swap(x, y);
    ch[lca(x, y)].emplace_back(x, y);
  }

  LL ans = 0;
  
  for (int i = 1; i <= n; i++) {
    int x = id[i];
    auto work = [&](int y) {
      if (dep[y] - dep[x] >= k) {
        y = jmp(y, dep[x] + k);
        ans += ask(in[y], in[y] + siz[y] - 1);
      }
    };

    for (auto [a, b] : ch[x]) {
      work(a), work(b);
      add(in[a], 1), add(in[b], 1);
    }
    add(i, -d[i]);
  }

  auto work = [&](int x) {
    std::vector<int> p;
    p.reserve(ch[x].size() * 2);
    for (auto &[a, b] : ch[x]) {
      if (a == x) continue;
      p.push_back(a);
      p.push_back(b);
    }
    if (p.empty()) return;
    std::sort(p.begin(), p.end(), [&](int i, int j) {
      return in[i] < in[j];
    });
    p.erase(std::unique(p.begin(), p.end()), p.end());

    auto ask = [&](int a, int b) -> int {
      if (s[a].empty()) return 0;
      int res = 0, v;
      if (dep[a] - dep[x] < k) {
        v = k - dep[a] + dep[x];
        if (v <= 0) {
          res += s[a].size();
        } else if (dep[x] + v <= dep[b]) {
          v = jmp(b, dep[x] + v);
          res +=
            s[a].order_of_key(PII(in[v] + siz[v], 0)) -
            s[a].order_of_key(PII(in[v], 0));
          
        }
      }
      
      if (dep[x] + k <= dep[b]) {
        v = jmp(b, dep[x] + k);
        res -=
          s[a].order_of_key(PII(in[v] + siz[v], 0)) -
          s[a].order_of_key(PII(in[v], 0));
      }
      return res;
    };

    auto merge = [&](int x, int y) {
      if (s[x].size() < s[y].size()) {
        s[x].swap(s[y]);
      }
      for (auto &&[u, _] : s[y]) {
        ans += ask(x, id[u]);
      }
      for (auto &&u : s[y]) {
        s[x].insert(u);
      }
      s[y].clear();
    };
    
    int tim = 0;
    for (auto &[a, b] : ch[x]) {
      if (a == x) continue;
      ans += ask(a, b);
      s[a].insert(PII(in[b], ++tim));
    }

    {
      std::vector<int> s(p.size() + 2);
      int t = 0;
      auto pop = [&] { merge(s[t - 1], s[t]), t--; };
      for (int x : p) {
        if (t && in[x] + siz[x] > in[s[t]] + siz[s[t]]) {
          int p = lca(s[t], x);
          while (t > 1 && in[s[t - 1]] >= in[p]) pop();
          if (s[t] != p) {
            ::s[p].clear();
            merge(p, s[t]);
            s[t] = p;
          }
        }
        s[++t] = x; 
      }
      while (t > 1) pop();
      assert(s[1] == x);
    }
   
    s[x].clear();
  };
  
  for (int i = 1; i <= n; i++) {
    work(i);
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