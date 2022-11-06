// Author:  HolyK
// Created: Mon Oct 24 01:00:13 2022
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
using U = uint32_t;

constexpr U N(5e4 + 5), B(64), S(N / B + 5);
U pr[N], np[N], pn;
std::vector<U> fac[N];
void init() {
  const U n = 5e4;
  for (U i = 2; i <= n; i++) {
    if (!np[i]) {
      pr[pn++] = i;
      for (U j = i * i; j <= n; j += i) np[j] = 1;
    }
  }
  for (U i = 1; i <= n; i++) {
    for (U j = i; j <= n; j += i) {
      fac[j].push_back(i);
    } 
  }
}

U n, tot, q, a[N], b[N], c[N][S];

U tag[S], min[S];
void push(U x) {
  if (!tag[x]) return;
  U l = x * B, r = std::min(n, l + B);
  for (U i = l; i < r; i++) a[i] = tag[x];
  tag[x] = 0;
}
void cal(U x) {
  U l = x * B, r = std::min(n, l + B);
  min[x] = -1;
  for (U i = l; i < r; i++) {
    U g = std::gcd(a[i], b[i]);
    smin(min[x], a[i] * b[i] / (g * g));
  }
}
void solve() {
  init();
  
  std::cin >> n >> q;
  tot = (n - 1) / B + 1;
  
  for (U i = 0; i < n; i++) std::cin >> a[i];
  for (U i = 0; i < n; i++) std::cin >> b[i];
  for (U i = 0; i < tot; i++) cal(i);
  
  memset(c, -1, sizeof c);
  for (U i = 0; i < n; i++) {
    for (U x : fac[b[i]]) {
      smin(c[x][i / B], b[i] / x);
    }
  }
  for (U i = 1; i <= 50000; i++) {
    for (U j = 0; j < tot; j++) {
      if (!~c[i][j]) continue;
      for (U k = 0; k < pn && pr[k] * i <= 50000; k++) {
        smin(c[i * pr[k]][j], c[i][j] * pr[k]);
      }
    }
  }

  while (q--) {
    U opt, l, r;
    std::cin >> opt >> l >> r;
    l--, r--;
    U bl = l / B, br = r / B;
    if (opt == 1) {
      U x;
      std::cin >> x;
      if (bl == br) {
        push(bl);
        for (U i = l; i <= r; i++) a[i] = x;
        cal(bl);
      } else {
        push(bl);
        for (U i = l, k = bl * B + B; i < k; i++) a[i] = x;
        cal(bl);
        push(br);
        for (U i = br * B; i <= r; i++) a[i] = x;
        cal(br);
        for (U i = bl + 1; i < br; i++) tag[i] = x, min[i] = c[x][i];
      }
    } else {
      U ans = -1;
      if (bl == br) {
        push(bl), min[bl] = -1;
        for (U i = bl * B, k = std::min(n, i + B); i < k; i++) {
          U g = std::gcd(a[i], b[i]), z = a[i] * b[i] / (g * g);
          smin(min[bl], z);
          if (l <= i && i <= r) smin(ans, z);
        }
      } else {
        push(bl), min[bl] = -1;
        for (U i = bl * B, k = i + B; i < k; i++) {
          U g = std::gcd(a[i], b[i]), z = a[i] * b[i] / (g * g);
          smin(min[bl], z);
          if (l <= i) smin(ans, z);
        }
        push(br), min[br] = -1;
        for (U i = br * B, k = std::min(n, i + B); i < k; i++) {
          U g = std::gcd(a[i], b[i]), z = a[i] * b[i] / (g * g);
          smin(min[br], z);
          if (i <= r) smin(ans, z);
        }
        for (U i = bl + 1; i < br; i++) {
          smin(ans, min[i]);
        }
      }
      std::cout << ans << "\n";
    }
  }
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