// Author:  HolyK
// Created: Wed Aug  3 13:37:52 2022
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

constexpr int N(2e6 + 5);
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

int s1[N], s2[N], s3[N];
Z ans[N];
void solve() {
  fa[0] = -1, cnt = 0, ch[0].fill(0);
  std::string s, t, w;
  std::cin >> s >> t >> w;
  int p = 0;
  for (char c : s) p = ins(p, c - 'a'), s1[p]++;
  p = 0;
  for (char c : t) p = ins(p, c - 'a'), s2[p]++;
  p = 0;
  for (char c : w) p = ins(p, c - 'a'), s3[p]++;

  std::vector<int> v(cnt);
  std::iota(v.begin(), v.end(), 1);
  std::sort(v.begin(), v.end(), [&](int i, int j) {
    return len[i] > len[j]; 
  });

  for (int i : v) {
    s1[fa[i]] += s1[i];
    s2[fa[i]] += s2[i];
    s3[fa[i]] += s3[i];
    if (s1[i] && s2[i] && s3[i]) {
      ans[len[fa[i]] + 1] += Z(s1[i]) * s2[i] * s3[i];
      ans[len[i] + 1] -= Z(s1[i]) * s2[i] * s3[i];
    }
  }
  int k = std::min({s.length(), t.length(), w.length()});
  for (int i = 1; i <= k; i++) {
    ans[i] += ans[i - 1];
    std::cout << ans[i] << " \n"[i == k];
  }
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