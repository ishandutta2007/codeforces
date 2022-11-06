// Author:  HolyK
// Created: Fri Aug 12 17:28:39 2022
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

constexpr int N(1e6 + 5);
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

int node[N], in[N], out[N], dfn;
std::vector<int> g[N];
void dfs(int x) {
  in[x] = dfn++;
  for (int y : g[x]) dfs(y);
  out[x] = dfn;
}

int dp[N], f[20][N];

int get(int o, int l) {
  for (int i = 19; i >= 0; i--) {
    if (len[f[i][o]] >= l) o = f[i][o];
  }
  return o;
}

void solve() {
  fa[0] = -1, cnt = 0, ch[0].fill(0);

  int n;
  {
    std::string s;
    std::cin >> n >> s;
    std::reverse(s.begin(), s.end());

    for (int i = 0, p = 0; i < n; i++) {
      p = ins(p, s[i] - 'a');
      node[i + 1] = p;
    }
  }
  

  for (int i = 1; i <= cnt; i++) {
    g[fa[i]].push_back(i);
  }

  dfs(0);

  for (int i = 1; i <= cnt; i++) f[0][i] = fa[i];
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= cnt; j++) {
      f[i][j] = f[i - 1][f[i - 1][j]];
    }
  }

  int s = 1 << std::__lg(dfn * 2 - 1);
  std::vector<int> t(s * 2);

  auto ask = [&](int l, int r, int k) {
    for (l += s, r += s; l < r; l >>= 1, r >>= 1) {
      if (l & 1 && t[l++] >= k) return true;
      if (r & 1 && t[--r] >= k) return true;
    }
    return false;
  };
  
  for (int i = 1, j = 1, o; i <= n; i++) {
    for (dp[i] = dp[i - 1] + 1; dp[i] > 1; dp[i]--) {
      for (; j <= i - dp[i]; j++) {
        for (int x = s + in[node[j]]; x; x >>= 1)
          smax(t[x], dp[j]);
      }
      
      int x = dp[i] - 1;
      o = get(node[i], x);
      if (ask(in[o], out[o], x)) break;
      o = get(node[i - 1], x);
      if (ask(in[o], out[o], x)) break;
    }
  }

  std::cout << *std::max_element(dp + 1, dp + n + 1) << "\n";
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