/**
 *    author:  tourist
 *    created: 12.01.2022 19:02:06       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
class fenwick {
 public:
  basic_string<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> p(n, -1);
  vector<int> st;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push_back(i);
    } else {
      if (!st.empty()) {
        p[i] = st.back();
        p[st.back()] = i;
        st.pop_back();
      }
    }
  }
  vector<vector<int>> g(n);
  vector<int> idx(n, -1);
  vector<int> par(n, -1);
  int beg = 0;
  while (beg < n) {
    if (p[beg] == -1) {
      beg += 1;
      continue;
    }
    int end = beg;
    while (end + 1 < n && p[end + 1] != -1) {
      end += 1;
    }
    // s[beg..end] is RBS
    st.assign(1, (int) g.size());
    g.emplace_back();
    for (int i = beg; i <= end; i++) {
      assert(!st.empty());
      if (s[i] == '(') {
        idx[i] = (int) g[st.back()].size();
        par[i] = st.back();
        g[st.back()].push_back(i);
        st.push_back(i);
      } else {
        idx[i] = idx[st.back()];
        st.pop_back();
      }
    }
    beg = end + 1;
  }
  vector<fenwick<int>> gf(g.size(), fenwick<int>(0));
  for (int i = 0; i < (int) g.size(); i++) {
    if (!g[i].empty()) {
      gf[i].n = (int) g[i].size();
      gf[i].fenw.resize(gf[i].n);
      for (int j = 0; j < gf[i].n; j++) {
        gf[i].modify(j, +1);
      }
    }
  }
  fenwick<long long> fenw(n);
  vector<long long> val(n);
  vector<int> deg(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(' && p[i] != -1) {
      deg[i] = (int) g[i].size();
      val[i] = (long long) deg[i] * (deg[i] + 1) / 2;
      fenw.modify(i, val[i]);
    }
  }
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --l; --r;
    if (t == 1) {
      int x = par[l];
      if (x < n) {
        deg[x] -= 1;
        long long new_val = (long long) deg[x] * (deg[x] + 1) / 2;
        fenw.modify(x, new_val - val[x]);
        val[x] = new_val;
      }
      gf[x].modify(idx[l], -1);
    } else {
      int x = par[l];
      long long res = fenw.get(r) - fenw.get(l - 1);
      long long outer = gf[x].get(idx[r]) - gf[x].get(idx[l] - 1);
      res += outer * (outer + 1) / 2;
      cout << res << '\n';
    }
  }
  return 0;
}