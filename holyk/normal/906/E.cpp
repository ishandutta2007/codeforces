// Author:  HolyK
// Created: Thu Nov  4 20:16:24 2021
#include <bits/stdc++.h>
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

constexpr int N(1e6 + 5);

char s[N], *now = s;
std::array<int, 26> ch[N];
int fa[N], len[N], cnt, diff[N], slink[N]; // fa[0] = 1, len[1] = -1, cnt = 1

int jmp(int x) {
  for (; now[~len[x]] != *now; x = fa[x]) ;
  // for (; now[~len[x]] != *now; x = now[~len[fa[x]]] == *now ? fa[x] : slink[x]) ;
  return x; 
}

int ins(int p, int x) {
  if (!ch[p = jmp(p)][x]) {
    int q = ++cnt;
    len[q] = len[p] + 2;
    fa[q] = ch[jmp(fa[p])][x];
    ch[p][x] = q;
    
    // dep[q] = dep[fa[q]] + 1;
    
    // if (len[q] <= 2) {
    //   f[q] = fa[q];
    // } else {
    //   for (int &i = f[q] = f[p]; now[~len[i]] != *now || (len[i] + 2 << 1) > len[q]; i = fa[i]) ;
    //   f[q] = ch[f[q]][x];
    // }
    
    diff[q] = len[q] - len[fa[q]];
    slink[q] = diff[q] == diff[fa[q]] ? slink[fa[q]] : fa[q];
  }
  return ch[p][x];
}

struct Info {
  int x, i;
  bool operator<(const Info &r) const {
    return x < r.x || x == r.x && i < r.i;
  }
} f[N], g[N];

int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::string a, b;
  std::cin >> a >> b;

  fa[0] = 1, len[1] = -1, cnt = 1;

  memset(f, 0x3f, sizeof f);
  memset(g, 0x3f, sizeof g);
  f[0] = {0, 0};
  
  for (int i = 0, p = 0; i < a.size(); i++) {
    // std::cerr << i << "\n";
    *++now = a[i];
    p = ins(p, a[i] - 'a');

    for (int o = p; o; o = slink[o]) {
      if (diff[o] == diff[fa[o]]) {
        g[o] = g[fa[o]];
      } else {
        g[o].x = 1e9;
      }
      
      if (len[slink[o]] + diff[o] & 1) {
        int x = i + 1 - (len[slink[o]] + diff[o] + 1) / 2;
        smin(g[o], Info{f[x].x + (diff[o] > 2), x});
      }
    }
    
    *++now = b[i];
    p = ins(p, b[i] - 'a');
    
    for (int o = p; o; o = slink[o]) {
      // if (i == 21) {
      //   std::cerr << "!! " << f[i + 1].x << " ";
      //   std::cerr << o << " " << len[o] << " " << fa[o] << " " << len[fa[o]] << "\n";
      //   std::cerr << diff[o] << " " << diff[fa[o]] << "\n";
      // }
      if (diff[o] == diff[fa[o]]) {
        g[o] = g[fa[o]];
      } else {
        g[o].x = 1e9;
      }

      if (len[slink[o]] + diff[o] & 1 ^ 1) {
        int x = i + 1 - (len[slink[o]] + diff[o] + 1) / 2;
        smin(g[o], Info{f[x].x + (diff[o] > 2), x});
      }
      smin(f[i + 1], g[o]);
    }
    // std::cerr << i + 1 << " " << f[i + 1].x << " " << f[i + 1].second << "\n";
  }

  // std::cerr << s + 1 << "\n";
  
  if (f[a.size()].x > a.size()) {
    std::cout << "-1\n";
  } else {
    std::vector<PII> ans;
    
    for (int i = a.size(); i; i = f[i].i) {
      auto p = a.substr(f[i].i, i - f[i].i), q = b.substr(f[i].i, i - f[i].i);
      if (p != q) {
        ans.push_back({f[i].i + 1, i});
        std::reverse(p.begin(), p.end());
        assert(p == q);
      }
    }
    
    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
      std::cout << x << " " << y << "\n";
    }
  }
  return 0;
  
}