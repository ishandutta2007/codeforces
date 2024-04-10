// LUOGU_RID: 91864028
// Author:  HolyK
// Created: Fri Oct 28 11:14:17 2022
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

constexpr int N(1e6 + 5);
int ch[N][26], cnt = 1, fa[N], q[N], len[N];
int ins(int p, int x) {
  if (!ch[p][x]) {
    ch[p][x] = ++cnt;
    len[cnt] = len[p] + 1;
  }
  return ch[p][x];
}

int head[N], ne[N], in[N], out[N], dfn, last[N];
void dfs(int x) {
  in[x] = ++dfn;
  for (int y = head[x]; y; y = ne[y]) dfs(y);
  out[x] = dfn;
}
void build() {
  for (int i = 1, r = q[1] = 1; i <= r; i++) {
    int x = q[i];
    for (int j = 0; j < 26; j++) {
      int &y = ch[x][j], z = ch[fa[x]][j];
      if (y) {
        q[++r] = y, fa[y] = z ?: 1;
        if (!last[y]) last[y] = last[z];
      } else {
        y = z;
      }
    }
  }

  for (int i = 2; i <= cnt; i++) {
    int x = fa[i];
    ne[i] = head[x], head[x] = i;
  }

  dfs(1);
}

int c[N], d[N];
void add(int p, int x) {
  for (; p <= cnt; p += p & -p) c[p] += x;
}
int ask(int p) {
  int r = 0;
  for (; p; p -= p & -p) r += c[p];
  return r;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> node(n);
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    int p = 1;
    node[i].reserve(s.size());
    for (char c : s) node[i].push_back(p = ins(p, c - 'a'));
    last[p] = p;
  }

  build();

  assert(dfn == cnt);

  int ans = 0;
  for (auto &p : node) {
    int k = p.size();
    for (int i : p) add(in[i], 1);

    std::vector<int> f;
    for (int i = k - 1, min = 1e9; i >= 0; i--) {
      int x = i == k - 1 ? last[fa[p[i]]] : last[p[i]];
      if (!x) continue;
      if (!d[x]++) f.push_back(x);
      if (!smin(min, i - len[x])) d[x] = 1e9;
    }
    for (int x : f) {
      if (ask(out[x]) - ask(in[x] - 1) == d[x]) ans++;
      d[x] = 0;
    }
    // std::vector<int> f(k);
    // for (int i = 0; i < k; i++) {
    //   f[i] = i + 1 == k ? last[fa[p[i]]] : last[p[i]];
    //   if (f[i]) d[f[i]]++;
    // }

    // std::vector<int> r;
    // for (int i = 0; i < k; i++) {
    //   int x = f[i], z = d[x];
    //   d[x] = 0;
    //   if (!x || ask(out[x]) - ask(in[x] - 1) != z) continue;
    //   while (!r.empty() && r.back() >= i - len[x]) r.pop_back();
    //   r.push_back(i - len[x]);
    // }
    // ans += r.size();
    for (int i : p) add(in[i], -1);
  }
  std::cout << ans << "\n";
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