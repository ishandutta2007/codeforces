// Author:  HolyK
// Created: Fri Nov  5 08:15:06 2021
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

constexpr int N(1.2e6 + 5);
std::array<int, 26> ch[N];
int len[N], fa[N], cnt; // fa[0] = -1
int ins(int last, int x) {
  if (ch[last][x] && len[last] + 1 == len[ch[last][x]]) return ch[last][x];
  int p = last, np = ++cnt, q;
  len[np] = len[p] + 1;
  for (; ~p && !ch[p][x]; p = fa[p]) ch[p][x] = np;
  if (p == -1) {
    fa[np] = 0;
  } else if (len[q = ch[p][x]] == len[p] + 1) {
    fa[np] = q;
  } else {
    int nq = p == last ? np : ++cnt;
    len[nq] = len[p] + 1;
    ch[nq] = ch[q];
    for (; ~p && ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
    fa[np] = nq;
    fa[nq] = fa[q];
    fa[q] = nq;    
  }
  return np;
}

int n, m, pos[N], val[N];
std::vector<int> q[N], g[N];

int in[N], out[N];
void dfs(int x) {
  in[x] = cnt++;
  for (int y : g[x]) {
    dfs(y);
  }
  out[x] = cnt;
}

int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  fa[0] = -1;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
      std::string s;
      std::cin >> s;
      int p = 0;
      for (char c : s) {
        p = ins(p, c - 'a');
      }
      pos[i] = p;
  }

  for (int i = 0; i < m; i++) {
    int opt;
    std::cin >> opt;
    q[i].push_back(opt);
    if (opt == 1) {
      int x, y;
      std::cin >> x >> y;
      x--;
      q[i].push_back(x);
      q[i].push_back(y);
    } else {
      std::string s;
      std::cin >> s;
      int p = 0;
      for (char c : s) {
        p = ins(p, c - 'a');
        q[i].push_back(p);
      }
    }
  }

  for (int i = 1; i <= cnt; i++) g[fa[i]].push_back(i);
  dfs(0);
  
  int s = 1 << std::__lg(cnt * 2 + 1);
  std::vector<std::priority_queue<int>> q1(s * 2), q2(s * 2);
  auto add = [&](int l, int r, int x) {
    for (l += s, r += s; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        q1[l++].push(x);
      }
      if (r & 1) {
        q1[--r].push(x);
      }
    }
  };

  auto del = [&](int l, int r, int x) {
    for (l += s, r += s; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        q2[l++].push(x);
      }
      if (r & 1) {
        q2[--r].push(x);
      }
    }
  };
  
  for (int i = 0; i < n; i++) {
    add(in[pos[i]], out[pos[i]], 0);
  }

  for (int i = 0; i < m; i++){
    if (q[i][0] == 1) {
      int x = q[i][1];
      del(in[pos[x]], out[pos[x]], val[x]);
      add(in[pos[x]], out[pos[x]], val[x] = q[i][2]);
    } else {
      int ans = -1;
      for (int j = 1; j < q[i].size(); j++) {
        for (int o = s + in[q[i][j]]; o; o >>= 1) {
          while (!q2[o].empty() && q1[o].top() == q2[o].top()) {
            q1[o].pop(), q2[o].pop();
          }
          if (!q1[o].empty()) smax(ans, q1[o].top());
        }
      }
      std::cout << ans << "\n";
    }
  }
  return 0;
}