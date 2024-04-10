// LUOGU_RID: 91480842
// Author:  HolyK
// Created: Tue Oct 25 16:41:08 2022
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

constexpr int N(1e5 + 5);
struct ACAM{
  int ch[N][26], cnt = 1, q[N], fa[N], head[N], ne[N];
  int ins(int p, int x) {
    if (!ch[p][x]) ch[p][x] = ++cnt;
    return ch[p][x];
  }
  void build() {
    int l, r;
    q[l = r = 1] = 1;
    while (l <= r) {
      int x = q[l++];
      if (x > 1 && !fa[x]) fa[x] = 1;
      for (int i = 0; i < 26; i++) {
        int &y = ch[x][i], z = ch[fa[x]][i];
        if (y) {
          q[++r] = y, fa[y] = z;
        } else {
          y = z;
        }
      }
    }

    for (int i = 2; i <= r; i++) {
      int x = fa[q[i]];
      assert(x);
      ne[i] = head[x], head[x] = i;
    }
    
    dfs(1);
  }

  int in[N], out[N], dfn;
  void dfs(int x) {
    in[x] = dfn++;
    for (int i = head[x]; i; i = ne[i]) {
      dfs(q[i]);
    }
    out[x] = dfn;
  }

  int val[N];
  void clear() {
    memset(val, 0, cnt + 1 << 2);
  }
  void cal() {
    for (int i = cnt; i; i--) {
      val[fa[q[i]]] += val[q[i]];
    }
  }
} ac;

template <class T>
struct DS {
  T s0[N], s1[(N >> 8) + 1];
  void add(int l, int r, const T &x) {
    while (l & 255 && l < r) s0[l++] += x;
    while (l + 256 <= r) s1[l >> 8] += x, l += 256;
    while (l < r) s0[l++] += x;
  }
  T ask(int p) {
    return s0[p] + s1[p >> 8];
  }
};

DS<int> ds;

int n, m, pos[N];
std::string s[N];
void solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
    int p = 1;
    for (char c : s[i]) {
      p = ac.ins(p, c - 'a');
    }
    pos[i] = p;
  }

  std::vector<LL> ans(m);
  std::vector<std::array<int, 4>> q0, q1;
  for (int i = 0, l, r, k; i < m; i++) {
    std::cin >> l >> r >> k;
    if (s[k].size() < 350) {
      q0.push_back({r, 1, k, i});
      q0.push_back({l - 1, -1, k, i});
    } else {
      q1.push_back({k, l, r, i});
    }
  }

  std::sort(q0.begin(), q0.end());
  std::sort(q1.begin(), q1.end());

  ac.build();
  
  for (int i = 0, j = 1; i < q0.size(); i++) {
    while (j <= q0[i][0]) {
      int x = pos[j++];
      ds.add(ac.in[x], ac.out[x], 1);
    }
    int p = 1;
    LL res = 0;
    for (char c : s[q0[i][2]]) {
      p = ac.ch[p][c - 'a'];
      res += ds.ask(ac.in[p]);
    }
    ans[q0[i][3]] += q0[i][1] * res;
  }

  std::vector<LL> sum(n + 1);
  for (int i = 0; i < q1.size(); i++) {
    auto &[k, l, r, id] = q1[i];
    if (!i || q1[i - 1][0] != k) {
      ac.clear();
      int p = 1;
      for (char c : s[k]) {
        p = ac.ch[p][c - 'a'];
        ac.val[p]++;
      }
      ac.cal();
      for (int j = 1; j <= n; j++) {
        sum[j] = sum[j - 1] + ac.val[pos[j]];
      }
    }
    ans[id] = sum[r] - sum[l - 1];
  }

  for (auto z : ans) std::cout << z << "\n";
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