// LUOGU_RID: 89311496
// Author:  HolyK
// Created: Mon Oct 10 01:37:01 2022
#include <algorithm>
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

constexpr int N(2e5 + 5);
int n, a[N], ch[N * 30][2], pos[N * 30], cnt;
int ins(int p, int x) {
  if (!ch[p][x]) {
    ch[p][x] = ++cnt;
    ch[cnt][0] = ch[cnt][1] = 0;
  }
  return ch[p][x];
}

int f[N], c[N], b[N];
int find(int x) {
  while (x != f[x]) x = f[x] = f[f[x]];
  return x;
}

PII min[N];
void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    f[i] = i;
  }

  LL ans = 0;
  for (;;) {
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; i++) {
      c[find(i)]++;
    }
    if (*std::max_element(c + 1, c + n + 1) == n) {
      break;
    }
    for (int i = 1; i <= n + 1; i++) {
      c[i] += c[i - 1];
    }
    for (int i = 1; i <= n; i++) {
      b[--c[find(i)]] = a[i];
    }

    
    std::vector<std::array<int, 3>> e;

    auto ask = [&](int x) {
      int v = 0, p = 1;
      for (int k = 29; k >= 0; k--) {
        int d = x >> k & 1;
        if (!ch[p][d]) {
          d ^= 1;
          v |= 1 << k;
        }
        p = ch[p][d];
      }
      return PII(v, pos[p]);
    };

    auto add = [&](int x) {
      int p = 1;
      for (int k = 29; k >= 0; k--) {
        p = ins(p, x >> k & 1);
      }
      return p;
    };

    cnt = 1;
    ch[1][0] = ch[1][1] = 0;

    for (int i = 1; i <= n; i++) {
      min[i] = {1e9, 0};
      if (cnt > 1) {
        for (int j = c[i]; j < c[i + 1]; j++) {
          smin(min[i], ask(b[j]));
        }
      }
      for (int j = c[i]; j < c[i + 1]; j++) {
        pos[add(b[j])] = i;
      }
    }

    cnt = 1;
    ch[1][0] = ch[1][1] = 0;

    for (int i = n; i; i--) {
      if (cnt > 1) {
        for (int j = c[i]; j < c[i + 1]; j++) {
          smin(min[i], ask(b[j]));
        }
      }
      for (int j = c[i]; j < c[i + 1]; j++) {
        pos[add(b[j])] = i;
      }
      if (min[i].second) e.push_back({min[i].first, min[i].second, i});
    }

    std::sort(e.begin(), e.end());
    for (auto &[z, x, y] : e) {
      x = find(x), y = find(y);
      if (x != y) {
        f[x] = y;
        ans += z;
      }
    }
  }
  std::cout << ans << "\n";
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