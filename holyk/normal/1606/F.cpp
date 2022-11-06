// Author:  HolyK(Asuka Kyle)
// Created: Sat Jan 15 20:39:45 2022
#include <bits/stdc++.h>
#include <queue>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
template <int S>
using AI = std::array<int, S>;
using LL = long long;
using PII = std::pair<int, int>;

inline char gc() {
  static constexpr int BufferSize = 1 << 22 | 5;
  static char buf[BufferSize], *p, *q;
  static std::streambuf *i = std::cin.rdbuf();
  return p == q ? p = buf, q = p + i->sgetn(p, BufferSize), p == q ? EOF : *p++ : *p++;
}
struct Reader {
  template <class T>
  Reader &operator>>(T &w) {
    char c, p = 0;
    for (; !std::isdigit(c = gc());) if (c == '-') p = 1;
    for (w = c & 15; std::isdigit(c = gc()); w = w * 10 + (c & 15)) ;
    if (p) w = -w;
    return *this;
  }
} cin;

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

  int n, m;
  cin >> n;
  std::vector<int> a(n), fa(n);
  std::vector<std::vector<int>> g(n);
  
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y), g[y].push_back(x);
  }
  std::vector<int> in(n), out(n);
  int cnt = 0;

  std::function<void(int)> dfs = [&](int x) {
    in[x] = cnt++;
    for (int y : g[x]) {
      if (y == fa[x]) continue;
      fa[y] = x;
      dfs(y);
    }
    out[x] = cnt;
  };

  fa[0] = -1;
  dfs(0);

  std::priority_queue<PII, std::vector<PII>, std::greater<PII>> q;

  std::vector<int> f(n), siz(n, 1);
  std::vector<LL> sum(n);

  auto find = [&](int i) {
    while (i != f[i]) i = f[i] = f[f[i]];
    return i;
  };

  
  for (int i = 0; i < n; i++) {
    f[i] = i;
    sum[i] = a[i] = (int)g[i].size() - 1 - (i > 0);
    q.push({-a[i], i});
  }


  cin >> m;
  
  std::vector<std::array<int, 3>> qry(m);

  for (int i = 0; i < m; i++) {
    int u, x;
    cin >> u >> x;
    qry[i] = {-x, u - 1, i};
  }

  std::sort(qry.begin(), qry.end());

  Fenwick<LL> fsum(n);
  Fenwick<int> fsiz(n);

  std::vector<LL> ans(m);


  for (auto &[u, x, id] : qry) {
    while (!q.empty() && q.top().first <= u) {
      int x = q.top().second;
      q.pop();

      if (!x || x != f[x]) continue;
      
      int p = fa[x];
      fsum.add(in[p], sum[x]);
      fsiz.add(in[p], siz[x]);
      f[x] = p = find(p);
      sum[p] += sum[x], siz[p] += siz[x];
      if (p) {
        fsum.add(in[fa[p]], -sum[x]);
        fsiz.add(in[fa[p]], -siz[x]);
        LL u = sum[p], v = siz[p];
        q.push({u > 0 ? -(u / v) : (-u + v - 1) / v, p});
      }
    }
    
    ans[id] = 1 + (fsum.ask(in[x], out[x]) + a[x]) + 1LL * u * fsiz.ask(in[x], out[x]);
  }
  
  for (auto x : ans) std::cout << x << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}