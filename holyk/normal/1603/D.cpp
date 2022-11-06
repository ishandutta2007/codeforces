// Author:  HolyK
// Created: Sun Oct 31 13:14:53 2021
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

constexpr int N(1e5 + 5);
bool np[N];
std::vector<int> primes;
int phi[N];
LL sphi[N];
void sieve(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) {
      primes.push_back(i);
      phi[i] = i - 1;
    }
    for (int j : primes) {
      if (1LL * i * j > n) break;
      np[i * j] = true;
      if (i % j == 0) {
        phi[i * j] = phi[i] * j;
        break;
      }
      phi[i * j] = phi[i] * (j - 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    sphi[i] = sphi[i - 1] + phi[i];
  }
}

LL s1[N][320], s2[N][320];
int sqroot[N];

LL cal(LL l, LL r) {
  if (l > r) return 0;
  if (l <= sqroot[r]) {
    return s1[r][l];
  }
  int t = r / l;
  return s2[r][t - 1] + (r / t - l + 1) * sphi[t];
}

LL f[18][N];

struct Interval {
  int l, r, x;
};

void init(int n) {
  sieve(n);
  for (int i = 1; i <= n; i++) {
    sqroot[i] = sqrt(i);
    for (int l = sqroot[i] + 1, r, t; l <= i; l = r + 1) {
      t = i / l, r = i / t;
      s2[i][t] = sphi[t] * (r - l + 1);
    }

    for (int j = 1; j <= sqroot[i]; j++) {
      s2[i][j] += s2[i][j - 1];
    }
    
    s1[i][sqroot[i]] += s2[i][sqroot[i]];
    for (int j = sqroot[i]; j >= 1; j--) {
      s1[i][j] += s1[i][j + 1] + sphi[i / j];
    }
  }
  for (int i = 1; i <= n; i++) f[1][i] = cal(1, i);

  for (int i = 2, l, r; i < 18; i++) {
    static Interval q[N];
    q[l = r = 1] = {i, n, i - 1};
    for (int j = i; j <= n; j++) {
      assert(l <= r && q[l].l <= j && j <= q[l].r);
#define F(x, y) (f[i - 1][x] + cal(x + 1, y))
      f[i][j] = F(q[l].x, j);
      while (l <= r && q[l].r <= j) l++;
      while (l <= r && F(q[r].x, q[r].l) >= F(j, q[r].l)) r--;
      int s = j + 1;
      if (l <= r) {
        int h = std::max(q[r].l, s), t = q[r].r + 1;
        while (h < t) {
          int m = h + t >> 1;
          if (F(q[r].x, m) >= F(j, m)) {
            t = m;
          } else {
            h = m + 1;
          }
        }
        s = h;
        q[r].r = h - 1;
      }
      if (s <= n) q[++r] = {s, n, j};
#undef F
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  init(1e5);
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    if (k >= 18) {
      std::cout << n << "\n";
    } else {
      std::cout << f[k][n] << "\n";
    }
  }
  return 0;
}