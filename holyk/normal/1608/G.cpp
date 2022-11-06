// Author:  HolyK
// Created: Tue May 17 22:57:11 2022
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

struct H {
  typedef uint64_t ULL;
  ULL x;
  H(ULL x = 0) : x(x) {}
#define OP(O, A, B)                                     \
  H operator O(H o) {                                   \
    ULL r = x;                                          \
    asm(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); \
    return r;                                           \
  }
  OP(+, , "d"(o.x))
  OP(*, "mul %1\n", "r"(o.x) : "rdx")
  H operator-(H o) { return *this + ~o.x; }
  ULL get() const { return x + !~x; }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
};
// using H = unsigned long long;
constexpr int N(2e5 + 5);
int n, m, q;
std::vector<std::pair<int, char>> g[N];
int in[N], dfn, top[N], son[N], dep[N], siz[N], fa[N];
char val[N], t[N];
H h1[N], h2[N], h3[N], pw[N];

H get1(int l, int r) {
  return h1[r] - h1[l - 1] * pw[r - l + 1];
}
H get2(int l, int r) {
  return h2[l] - h2[r + 1] * pw[r - l + 1];
}
H get3(int l, int r) {
  return h3[r] - h3[l] * pw[r - l];
}

void dfs1(int x) {
  siz[x] = 1;
  for (auto [y, z] : g[x]) {
    if (y == fa[x]) continue;
    fa[y] = x;
    dep[y] = dep[x] + 1; 
    val[y] = z;
    dfs1(y);
    siz[x] += siz[y];
    if (siz[y] > siz[son[x]]) son[x] = y;
  }
}
void dfs2(int x) {
  // std::cerr << "dfn " << x << "\n";
  in[x] = ++dfn;
  t[dfn] = val[x];
  if (!son[x]) return;
  top[son[x]] = top[x];
  dfs2(son[x]);
  for (auto [y, z] : g[x]) {
    if (y == fa[x] || y == son[x]) continue;
    top[y] = y;
    dfs2(y);
  }
}

struct SuffixArray {
  std::vector<int> p, r, h;
  SuffixArray(std::string s) : p(s.size()), r(s.size()), h(s.size()) {
    int n = s.size(), m = std::max(256, n), i, j, k, u, v;
    std::vector<int> x(n), y(n), c(m);
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) p[--c[x[i]]] = i;
    for (k = 1; k < n; k <<= 1) {
      for (i = n - k, v = 0; i < n; i++) y[v++] = i;
      for (i = 0; i < n; i++) {
        if (p[i] >= k) y[v++] = p[i] - k;
      }
      for (i = 0; i < m; i++) c[i] = 0;
      for (i = 0; i < n; i++) c[x[y[i]]]++;
      for (i = 1; i < m; i++) c[i] += c[i - 1];
      for (i = n - 1; i >= 0; i--) p[--c[x[y[i]]]] = y[i];
      std::swap(x, y);
      m = 1, x[p[0]] = 0;
      for (i = 1, v = p[0] + k < n ? y[p[0] + k] : -1; i < n; i++) {
        u = v, v = p[i] + k, v = v >= n ? -1 : y[v];
        x[p[i]] = u == v && y[p[i]] == y[p[i - 1]] ? m - 1 : m++;
      }
      if (m >= n) break;
    }
    for (i = 0; i < n; i++) r[p[i]] = i;
    for (i = 0, k = 0; i < n; i++) {
      if (k) k--;
      if (!r[i]) continue;
      for (j = p[r[i] - 1]; i + k < n && j + k < n && s[i + k] == s[j + k]; k++) ;
      h[r[i]] = k;
    }
  }
};

template <class T>
struct Fenwick {
  std::vector<T> c;
  Fenwick(int n) : c(n) {}
  void clear() { std::fill(c.begin(), c.end(), 0); }
  void add(int p, T x) {
    for (; p < c.size(); p |= p + 1) c[p] += x;
  }
  T ask(int p) {
    T r = 0;
    for (; p; p &= p - 1) r += c[p - 1];
    return r;
  }
  T ask(int l, int r) { return ask(r) - ask(l); }
};

void solve() {
  pw[0] = 1;
  for (int i = 1; i <= 2e5; i++) pw[i] = pw[i - 1] * 13331;
  
  std::cin >> n >> m >> q;
  for (int i = 1, x, y; i < n; i++) {
    std::string s;
    std::cin >> x >> y >> s;
    g[x].push_back({y, s[0]});
    g[y].push_back({x, s[0]});
  }

  dfs1(1), top[1] = 1, dfs2(1);

  for (int i = 1; i <= n; i++) {
    h1[i] = h1[i - 1] * pw[1] + t[i];
  }
  for (int i = n; i; i--) {
    h2[i] = h2[i + 1] * pw[1] + t[i];
  }

  std::string s;
  std::vector<int> pos(m + 1);
  for (int i = 0; i < m; i++) {
    std::string t;
    std::cin >> t;
    s += t + char('z' + 1);
    pos[i + 1] = s.length();
  }

  SuffixArray sa(s);

  int k = s.length();
  for (int i = 0; i < k; i++) {
    h3[i + 1] = h3[i] * pw[1] + s[i];
  }

  std::vector<std::vector<std::array<int, 3>>> qry(m + 1);

  // std::cerr << "k = " << k << "\n";
  for (int i = 0; i < q; i++) {
    int x, y, l, r;
    std::cin >> x >> y >> l >> r;
    std::vector<PII> p, q; 
    int u = x, v = y;
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        p.push_back({in[top[u]], in[u]});
        u = fa[top[u]];
      } else {
        q.push_back({in[top[v]], in[v]});
        v = fa[top[v]];
      }
    }
    if (in[u] != in[v]) {
      if (in[u] < in[v]) {
        q.push_back({in[u] + 1, in[v]});
      } else {
        p.push_back({in[v] + 1, in[u]});
      }
    }
    std::reverse(q.begin(), q.end());
    
    auto comp = [&](int i, char c) -> int {
      // std::cerr << "cmp " << i << ":";
      for (auto [x, y] : p) {
        if (i + y - x + 1 <= k && get2(x, y) == get3(i, i + y - x + 1)) {
          i += y - x + 1;
        } else {
          int l = x, r = y;
          while (l < r) {
            int m = l + r + 1 >> 1;
            if (i + y - m + 1 <= k && get2(m, y) == get3(i, i + y - m + 1)) {
              r = m - 1;
            } else {
              l = m;
            }
          }
          // std::cerr << t[l] << " " << s[i + y - l] << "\n";
          return t[l] - s[i + y - l];
        }
      }
      for (auto [x, y] : q) {
        if (i + y - x + 1 <= k && get1(x, y) == get3(i, i + y - x + 1)) {
          i += y - x + 1;
        } else {
          int l = x, r = y;
          while (l < r) {
            int m = l + r >> 1;
            if (i + m - x + 1 <= k && get1(x, m) == get3(i, i + m - x + 1)) {
              l = m + 1;
            } else {
              r = m;
            }
          }
          // std::cerr << t[l] << " " << s[i + l - x] << "\n";
          return t[l] - s[i + l - x];
        }
      }

      // std::cerr << c << " " << s[i] << "\n";
      return c - s[i];
    };
    auto getlb = [&](char c) {
      int l = 0, r = k;
      while (l < r) {
        int m = l + r >> 1;
        if (comp(sa.p[m], c) > 0) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      return l;
    };

    // for (auto [x, y] : p) std::cerr << "p " << x << " " << y << "\n";
    // for (auto [x, y] : q) std::cerr << "q " << x << " " << y << "\n";
    
    int lb = getlb(0), rb = getlb('z' + 2);
    qry[l - 1].push_back({lb, rb, ~i});
    qry[r].push_back({lb, rb, i});
    // std::cerr << lb << " " << rb << "\n";
  }

  Fenwick<int> fen(k);
  std::vector<int> ans(q);
  for (int i = 1; i <= m; i++) {
    for (int j = pos[i - 1]; j < pos[i]; j++) {
      fen.add(sa.r[j], 1);
    }
    for (auto [l, r, id] : qry[i]) {
      int k = id < 0 ? id = ~id, -1 : 1;
      ans[id] += k * fen.ask(l, r);
    }
  }

  for (int x : ans) std::cout << x << "\n";
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