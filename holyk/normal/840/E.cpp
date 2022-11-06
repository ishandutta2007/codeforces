// Author:  HolyK
// Created: Wed Aug 17 16:52:00 2022
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

constexpr int N(5e4 + 5), M(256 * 8 + 5);
struct Trie {
  int ch[M][2], max[M], cnt;
  void clear() {
    for (int i = 0; i <= cnt; i++) {
      ch[i][0] = ch[i][1] = 0;
      max[i] = 0;
    }
    cnt = 0;
  }

  void ins(int x, int y) {
    int o = 0;
    for (int i = 7; i >= 0; i--) {
      int v = x >> i & 1;
      if (!ch[o][v]) {
        ch[o][v] = ++cnt;
      }
      o = ch[o][v];
    }
    smax(max[o], y);
  }

  int ask(int x) {
    int o = 0, ans = 0;
    for (int i = 7; i >= 0; i--) {
      int v = x >> i & 1;
      if (!ch[o][!v]) {
        o = ch[o][v];
      } else {
        o = ch[o][!v];
        ans |= 1 << i + 8;
      }
    }
    ans |= max[o];
    return ans;
  }
} t;

std::vector<int> g[N];
int a[N], s[N], top, dep[N], fa[N], f[N], val[N][256];
void dfs(int x) {
  s[++top] = x;
  if (top > 256) {
    f[x] = s[top - 256];
  }

  t.clear();
  for (int i = 0; i < 256 && i < top; i++) {
    int v = s[top - i];
    t.ins(a[v] >> 8, a[v] & 0xff ^ i);
  }
  for (int i = 0; i < 256; i++) {
    val[x][i] = t.ask(i);
  }
  
  for (int y : g[x]) {
    if (y == fa[x]) continue;
    dep[y] = dep[x] + 1;
    fa[y] = x;
    dfs(y);
  }
  top--;
}

void solve() {
  int n, q;
  std::cin >> n >> q;

  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(1);

  while (q--) {
    int x, y;
    std::cin >> x >> y;

    std::swap(x, y);
    int k = 0, v = 0, ans = 0;
    while (dep[x] - dep[y] >= 256) {
      smax(ans, val[x][k++]);
      x = f[x];
    }
    for (;;) {
      smax(ans, a[x] ^ (k << 8 | v++));
      if (x == y) break;
      x = fa[x];
    }

    std::cout << ans << "\n";
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