// Author:  HolyK
// Created: Fri Aug  5 14:50:19 2022
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

std::vector<int> g[N];
int in[N], id[N], dfn, siz[N], top[N], son[N];
void dfs1(int x) {
  siz[x] = 1;
  for (int y : g[x]) {
    dfs1(y);
    siz[x] += siz[y];
    if (!son[x] || siz[y] > siz[son[x]]) son[x] = y;
  }
}
void dfs2(int x) {
  in[x] = dfn++;
  id[in[x]] = x;
  if (!son[x]) return;
  top[son[x]] = top[x];
  dfs2(son[x]);
  g[x].erase(std::find(g[x].begin(), g[x].end(), son[x]));
  for (int y : g[x]) {
    top[y] = y;
    dfs2(y);
  }
}

int n, ql[N], qr[N], node[N], pos[N];
std::vector<int> q1[N];
std::vector<PII> q2[N];
LL ans[N];

int vn;
struct Info {
  LL s;
  int c, v;
  void up() {
    if (v != vn) v = vn, s = c = 0;
  }
} c[N];
void add(int p, int x, int i) {
  for (; p <= n; p += p & -p) {
    c[p].up();
    c[p].s += i * x;
    c[p].c += x;
  }
}
std::pair<LL, int> ask(int p) {
  LL s = 0;
  int r = 0;
  for (; p; p -= p & -p) {
    c[p].up();
    s += c[p].s;
    r += c[p].c;
  }
  return {s, r};
}

void dfs3(int x) {
  for (int y : g[x]) {
    dfs3(y), vn++;
  }
  if (son[x]) dfs3(son[x]);
  if (pos[x]) add(pos[x], 1, pos[x]);
  for (int y : g[x]) {
    for (int i = in[y]; i < in[y] + siz[y]; i++) {
      int v = id[i];
      if (pos[v]) add(pos[v], 1, pos[v]);
    }
  }
  for (auto [i, l] : q2[x]) {
    int k = l < 0 ? l = -l, -1 : 1;
    auto v1 = ask(qr[i]);
    auto v2 = ask(ql[i] - 1);
    auto v3 = qr[i] - ql[i] + 1 <= l ? v1 : ask(ql[i] + l - 1);
    ans[i] += k * ((v3.second - v2.second) * (1LL - ql[i]) + v3.first - v2.first + 1LL * (v1.second - v3.second) * l);

    // std::cerr << "! " << x << " " << l << " " << k << " " << (v3.second - v2.second) * (ql[i] - 1LL) + v3.first - v2.first + 1LL * (v1.second - v3.second) * l << "\n";
  }
}

struct Seq {
  int id, x, y;
} a[N * 20], b[N * 20];

struct {
  LL c[N];
  void add(int p, LL x) {
    for (; p; p -= p & -p) c[p] += x;
  }
  LL ask(int p) {
    LL r = 0;
    for (; p <= n; p += p & -p) r += c[p];
    return r;
  }
} fen;
void cal(int l, int r) {
  if (r - l <= 1) return;
  int m = l + r >> 1;
  cal(l, m), cal(m, r);
  vn++;
  for (int i = l, j = m, k = l; k < r; k++) {
    if (j == r || i < m && a[i].x <= a[j].x) {
      b[k] = a[i++];
      if (b[k].id == -1) {
        int u = std::max(b[k].x - b[k].y + 1, 1);
        add(u, 1, b[k].x);
        fen.add(u, b[k].y);
      }
    } else {
      b[k] = a[j++];
      if (b[k].id != -1) {
        int o = b[k].id;
        auto [s, c] = ask(ql[o]);
        ans[o] += b[k].y * (s - (ql[o] - 1LL) * c) + fen.ask(ql[o] + 1);
      }
    }
  }
  for (int i = l; i < m; i++) {
    if (a[i].id == -1) {
      int u = std::max(a[i].x - a[i].y + 1, 1);
      fen.add(u, -a[i].y);
    }
  }
  for (int i = l; i < r; i++) a[i] = b[i];
}
void solve() {
  fa[0] = -1, cnt = 0, ch[0].fill(0);

  {
    std::string s;
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    n = s.length();

    for (int i = 1, p = 0; i <= n; i++) {
      p = ins(p, s[i - 1] - 'a');
      node[i] = p;
      pos[p] = i;
    }
  }
  

  for (int i = 1; i <= cnt; i++) {
    g[fa[i]].push_back(i);
  }
  dfs1(0), dfs2(0);

  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    std::cin >> r >> l;
    l = n - l + 1, r = n - r + 1;
    ql[i] = l, qr[i] = r;
    int o = node[r];
    for (; ~o; o = fa[top[o]]) {
      q1[o].push_back(i);
      q2[o].push_back({i, len[o]});
      if (top[o]) {
        q2[top[o]].push_back({i, -len[fa[top[o]]]});
      }
    }
  }

  dfs3(0);

  for (int i = 0, j; i < dfn; ) {
    for (j = i + 1; j < dfn && id[j - 1] == fa[id[j]]; j++) ;

    int an = 0;
    for (; i < j; i++) {
      int x = id[i];
      for (int id : q1[x]) {
        a[an++] = {id, qr[id], 1};
        a[an++] = {id, ql[id] - 1, -1};
      }
      if (pos[x]) a[an++] = {-1, pos[x], len[x]};
      for (int y : g[x]) {
        for (int k = in[y]; k < in[y] + siz[y]; k++) {
          int v = id[k];
          if (pos[v]) {
            a[an++] = {-1, pos[v], len[x]};
          }
        } 
      }
      
    }
    
    cal(0, an);
  }

  for (int i = 0; i < q; i++) {
    std::cout << ans[i] << "\n";
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