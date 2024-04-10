// LUOGU_RID: 92515206
// Author:  HolyK
// Created: Tue Nov  1 23:44:28 2022
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

constexpr int P(1e9 + 7);
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
inline void dec(int &x, int y) {
  x -= y;
  if (x < 0) x += P;
}
inline int mod(LL x) { return x % P; }
int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P) {
    if (k & 1) r = 1LL * r * x % P;
  }
  return r;
}
struct Z {
  int x;
  Z() : x(0) {}
  Z(int v) : x(v < 0 ? v + P : v >= P ? v - P : v) {}
  Z(LL v) : x((v %= P) < 0 ? v + P : v) {}
  explicit operator bool() { return !!x; }
  Z inv() const { return Z(fpow(x)); }
  Z pow(int k) const { return Z(fpow(x, k)); }
  Z operator-() const { return Z(P - x); }
  Z &operator+=(const Z &r) { return inc(x, r.x), *this; }
  Z &operator-=(const Z &r) { return dec(x, r.x), *this; }
  Z &operator*=(const Z &r) { return x = LL(x) * r.x % P, *this; }
  Z &operator/=(const Z &r) { return x = LL(x) * fpow(r.x) % P, *this; }
  inline friend Z operator+(const Z &a, const Z &b) { return Z(a) += b; }
  inline friend Z operator-(const Z &a, const Z &b) { return Z(a) -= b; }
  inline friend Z operator*(const Z &a, const Z &b) { return Z(a) *= b; }
  inline friend Z operator/(const Z &a, const Z &b) { return Z(a) /= b; }
  inline friend std::ostream &operator<<(std::ostream &os, const Z &r) {
    return os << r.x;
  }
};

constexpr int N(2e3 + 5);
std::array<int, 10> ch[N], fch[N];
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

Z dp[2][N][51][2][2][2];

void solve() {
  fa[0] = -1;
  std::string s, l, r;
  std::cin >> s >> l >> r;
  int d = r.size();
  for (int i = 0, p = 0; i < s.size(); i++) {
    p = ins(p, s[i] - '0');
  }

  {
    std::vector<int> p(cnt);
    std::iota(p.begin(), p.end(), 1);
    std::sort(p.begin(), p.end(), [](int i, int j) {
      return len[i] < len[j];
    });

    for (int i = 0; i < 10; i++) {
      fch[0][i] = ch[0][i] ? 0 : -1;
    }
    for (int i : p) {
      for (int j = 0; j < 10; j++) {
        fch[i][j] = ch[i][j] ? i : fch[fa[i]][j];
      }
    }
  }

  assert(l.size() == d);
  
  // [pos][len][lb][ub][ok]
  dp[0][0][0][1][1][0] = 1;
  for (int i = 0; i < d; i++) {
    int lx = l[i] - '0', rx = r[i] - '0';
    auto &f = dp[i & 1], &g = dp[i & 1 ^ 1];
    memset(g, 0, sizeof dp[0]);

    for (int p = 0; p <= cnt; p++) {
      for (int l = 0; l <= d; l++) {
        for (int lb = 0; lb < 2; lb++) {
          for (int rb = 0; rb < 2; rb++) {
            for (int ok = 0; ok < 2; ok++) {
              if (!f[p][l][lb][rb][ok]) continue;
              
              int s = lb ? lx : 0, e = rb ? rx : 9, np, nl;
              for (int x = s; x <= e; x++) {
                if (fch[p][x] == -1) {
                  np = nl = 0;
                } else if (ch[p][x]) {
                  np = ch[p][x];
                  nl = l + 1;
                } else {
                  np = fch[p][x];
                  nl = len[np] + 1;
                  np = ch[np][x];
                }
                // std::cerr << "! " << p << " " << l << " " << np << " " << nl << " " << x << "\n";
                g[np][nl][lb && x == s][rb && x == e][ok || nl >= (d >> 1)] += f[p][l][lb][rb][ok];
              }
            }
          }
        }
      }
    }
  }

  auto &f = dp[d & 1];
  Z ans;
  for (int i = 0; i <= cnt; i++) {
    for (int j = 0; j <= d; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          ans += f[i][j][k][l][1];
        }
      }
    }
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