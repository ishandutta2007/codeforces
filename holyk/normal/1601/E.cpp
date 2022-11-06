// Author:  HolyK
// Created: Thu Oct 28 09:32:31 2021
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

constexpr int N(3e5 + 5);
int n, q, k, a[N], next[N], min[19][N], lg[N];

int get(int i, int j) {
  return a[i] < a[j] ? i : j;
}
int askMin(int l, int r) {
  int k = lg[r - l + 1];
  return get(min[k][l], min[k][r - (1 << k) + 1]);
}

LL f[19][N];
LL cal(int l, int r, int t) {
  // std::cerr << "cal " << l << " " << r << " " << t << "\n";
  if (l > n) return 0; 
  int cnt = (r - l + k) / k;
  if ((cnt & -cnt) == cnt && lg[cnt] <= t) {
    return f[lg[cnt]][l];
  }

  for (int i = t; i >= 0; i--) {
    if (cnt >> i) {
      cnt -= 1 << i;
      LL res = f[i][l];
      int p = askMin(l, std::min(n, l + (k << i))), q = next[p], x = a[p];
     
      assert(p);
      if (q > n || q > r) {
        return res + 1LL * cnt * x;
      }
      
      p = l + (k << i);
      q = (q - l - 1) / k * k + l;
      assert(p <= q);
      res += 1LL * (q - p) / k * x + x - a[q];
      return res + cal(q, r, i);
    }
  }
  return 0;
}

int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> q >> k;

  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    f[0][i] = a[i];
    min[0][i] = i;
  }

  for (int i = n; i; i--) {
    static int s[N], t;
    while (t && a[s[t]] >= a[i]) t--;
    next[i] = t ? s[t] : n + 1;
    s[++t] = i;
  }
  
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i < 19; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      min[i][j] = get(min[i - 1][j], min[i - 1][j + (1 << i - 1)]);
    }
  }

  int lim = lg[(n + k - 1) / k];
  // std::cerr << lim << "\n";
  for (int i = 1; i <= lim; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = cal(j, j + (k << i) - 1, i - 1);
    }
  }
  // std::cerr << ">>\n";
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << cal(l, r, lim) << "\n";
  }
  return 0;
}