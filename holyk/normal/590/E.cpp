// LUOGU_RID: 91906334
// Author:  HolyK
// Created: Fri Oct 28 16:54:57 2022
#include "bits/stdc++.h"

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

struct Bipartite {
  std::vector<int> d, g, l, r;
  int match;
  Bipartite(int n, int m, const std::vector<PII> &e)
      : d(n + 1), g(e.size()), l(n, -1), r(m, -1), match(0) {
    std::vector<int> a, p, q(n);
    for (auto &[x, y] : e) d[x]++;
    for (int i = 1; i <= n; i++) d[i] += d[i - 1];
    for (auto &[x, y] : e) g[--d[x]] = y;

    for (;;) {
      a.assign(n, -1), p.assign(n, -1);
      int t = 0;
      for (int i = 0; i < n; i++)
        if (l[i] == -1) q[t++] = a[i] = p[i] = i;
      bool found = false;
      for (int i = 0; i < t; i++) {
        int x = q[i];
        if (~l[a[x]]) continue;
        for (int j = d[x]; j < d[x + 1]; j++) {
          int y = g[j];
          if (r[y] == -1) {
            while (~y) r[y] = x, std::swap(l[x], y), x = p[x];
            found = true, match++;
            break;
          }
          if (p[r[y]] == -1)
            q[t++] = y = r[y], p[y] = x, a[y] = a[x];
        }
      }
      if (!found) break;
    }
  }

  std::vector<int> minCover() {
    int n = l.size(), m = r.size();
    std::vector<bool> vl(n, true), vr(m);
    for (int i : r) if (~i) vl[i] = false;
    std::vector<int> q, res;
    for (int i = 0; i < n; i++) if (vl[i]) q.push_back(i);
    while (!q.empty()) {
      int x = q.back(); q.pop_back();
      vl[x] = true;
      for (int i = d[x]; i < d[x + 1]; i++) {
        int y = g[i];
        if (!vr[y] && ~r[y]) vr[y] = true, q.push_back(r[y]);
      }
    }
    for (int i = 0; i < n; i++) if (!vl[i]) res.push_back(i);
    for (int i = 0; i < m; i++) if (vr[i]) res.push_back(i + n);

    assert(res.size() == match);
    return res;
  }
};

constexpr int N(1e7 + 5);
int ch[N][2], cnt = 1, fa[N], q[N], last[N];
int ins(int p, int x) {
  if (!ch[p][x]) {
    ch[p][x] = ++cnt;
  }
  return ch[p][x];
}
void build() {
  for (int l = 1, r = q[1] = 1; l <= r; l++) {
    int x = q[l];
    for (int i = 0; i < 2; i++) {
      int &y = ch[x][i], z = ch[fa[x]][i];
      if (y) {
        q[++r] = y, fa[y] = z ?: 1;
        if (!last[y]) last[y] = last[z];
      } else {
        y = z;
      }
    }
  }
}

int n;
std::bitset<750> a[750];
std::string s[750];
void solve() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
    int p = 1;
    for (char c : s[i]) p = ins(p, c - 'a');
    last[p] = i + 1;
  }
  build();
  for (int i = 0; i < n; i++) {
    int p = 1;
    for (char c : s[i]) {
      p = ch[p][c - 'a'];
      if (last[p]) a[i][last[p] - 1] = 1;
    }
    if (last[fa[p]]) a[i][last[fa[p]] - 1] = 1;
    a[i][i] = 1;
  }

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      if (a[i][j]) a[i] |= a[j];
    }
  }

  std::vector<PII> e;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && a[i][j]) e.push_back({i, j});
    }
  }

  // for (auto [x, y] : e) {
  //   std::cerr << "! " << x + 1 << " " << y + 1 << "\n"; 
  // }

  Bipartite g(n, n, e);

  auto c = g.minCover();
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (!std::binary_search(c.begin(), c.end(), i) &&
        !std::binary_search(c.begin(), c.end(), i + n)) {
      ans.push_back(i + 1);
    }
  }

  std::cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
}

int main() {
  // freopen("t.in", "r", stdin);
  // freopen("t.out", "w", stdout);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}