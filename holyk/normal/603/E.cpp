// Author:  HolyK
// Created: Tue Sep  6 18:09:01 2022
#include <bits/stdc++.h>
#include <queue>
#include <stdint.h>

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
int n, m;
std::array<int, 3> e[N];
int get(int i, int j) {
  return e[i][2] < e[j][2] ? j : i;
}

struct LCT {
  int ch[N][2], fa[N];
  bool rev[N];
  bool nrt(int o) { return fa[o] && (ch[fa[o]][0] == o || ch[fa[o]][1] == o); }
  int dir(int o) { return ch[fa[o]][1] == o; }
  void sch(int o, int d, int x) {
    ch[o][d] = x;
    if (x) fa[x] = o;
  }
  void rotate(int o) {
    int k = dir(o), p = fa[o];
    fa[o] = fa[p];
    if (nrt(p)) ch[fa[o]][dir(p)] = o;
    sch(p, k, ch[o][!k]), sch(o, !k, p);
    pushup(p);
    pushup(o);
  }
  void push(int o) {
    if (nrt(o)) push(fa[o]);
    pushdown(o);
  }
  void splay(int o) {
    for (push(o); nrt(o); rotate(o)) {
      if (nrt(fa[o])) {
        rotate(dir(fa[o]) == dir(o) ? fa[o] : o);
      }
    }
    pushup(o);
  }
  void access(int o) {
    for (int x = 0, i = o; i; i = fa[x = i]) {
      splay(i);
      vir[i] ^= siz[x] ^ siz[ch[i][1]];
      ch[i][1] = x;
      pushup(i);
    }
    splay(o);
  }
  void evert(int o) { access(o), reverse(o), pushdown(o); }
  void expose(int x, int y) { evert(x), access(y); }
  bool link(int x, int y) {
    if (x == y) return false;
    expose(x, y);
    if (fa[x]) return false;
    fa[x] = y;
    vir[y] ^= siz[x];
    siz[y] ^= siz[x];
    return true;
  }
  bool cut(int x, int y) {
    expose(x, y);
    if (fa[x] == y && !ch[x][0] && !ch[x][1] && !ch[y][1]) {
      fa[x] = ch[y][0] = 0;
      pushup(y);
      return true;
    }
    return false;
  }
  
  int siz[N], vir[N], max[N];
  void pushup(int o) {
    siz[o] = siz[ch[o][0]] ^ siz[ch[o][1]] ^ vir[o];
    max[o] = get(max[ch[o][0]], max[ch[o][1]]);
    if (o <= n) {
      siz[o] ^= 1;
    } else {
      max[o] = get(max[o], o - n);
    }
  }
  void reverse(int o) {
    rev[o] ^= 1;
    std::swap(ch[o][0], ch[o][1]);
  }
  void pushdown(int o) {
    if (rev[o]) {
      if (ch[o][0]) reverse(ch[o][0]);
      if (ch[o][1]) reverse(ch[o][1]);
      rev[o] = false;
    }
  }
} t;

int f[N], s[N];
int find(int x) {
  while (x != f[x]) x = f[x] = f[f[x]];
  return x;
}

bool vis[N];

void solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    f[i] = i, s[i] = 1;
    t.siz[i] = 1;
  }

  int cnt = n, ans = -1;

  std::priority_queue<PII> q;
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    std::cin >> x >> y >> z;
    e[i] = {x, y, z};
    t.max[i + n] = i;

    int u = find(x), v = find(y);

    bool ok = true;
    if (u == v) {
      t.expose(x, y);
      int j = t.max[y];
      if (e[j][2] <= z) {
        ok = false;
      } else {
        t.cut(e[j][0], j + n);
        t.cut(e[j][1], j + n);
        vis[j] = true;
      }
      
    } else {
      f[u] = v;
      if (s[u] && s[v]) cnt -= 2;
      s[v] ^= s[u];
    }

    if (ok) {
      t.link(x, i + n);
      t.link(y, i + n);
      q.push({z, i});
    }

    if (cnt) {
      std::cout << "-1\n";
      continue;
    }
    for (; !q.empty(); q.pop()) {
      int j = q.top().second;
      if (vis[j]) continue;
      t.expose(e[j][0], e[j][1]);
      if (!t.vir[e[j][1]]) {
        ans = e[j][2];
        break;
      }
    }
    std::cout << ans << '\n';
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