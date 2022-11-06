// Author:  HolyK
// Created: Thu Aug 25 01:11:46 2022
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

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

struct H {
  typedef uint64_t ULL;
  ULL x;
  H(ULL x = 0) : x(x) {}
#define OP(O, A, B)                                     \
  H operator O(H o) {                                   \
    ULL r = x;                                          \
    asm(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); \
    return r;                                           \
  }
  OP(+, , "d"(o.x))
  OP(*, "mul %1\n", "r"(o.x) : "rdx")
  H operator-(H o) { return *this + ~o.x; }
  ULL get() const { return x + !~x; }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
};

constexpr int N(2e5 + 5);
H pw[N];
struct Node {
  H h;
  int ls, rs, w;
} t[N * 120];
int cnt;
void pushup(int o) {
  t[o].w = t[t[o].ls].w + t[t[o].rs].w;
  t[o].h = t[t[o].ls].h + t[t[o].rs].h;
}
bool ins(int &o, int l, int r, int x) {
  if (r < x) return false;
  if (l >= x && t[o].w == r - l + 1) {
    o = 0;
    return false;
  }
  t[++cnt] = t[o], o = cnt;
  if (l == r) {
    t[o].h = pw[l];
    t[o].w = 1;
    return true;
  }
  int m = l + r >> 1;
  bool res = ins(t[o].ls, l, m, x) || ins(t[o].rs, m + 1, r, x);
  pushup(o);
  return res;
}
int cmp(int p, int q, int l, int r) {
  if (t[p].h == t[q].h) return 0;
  if (!t[p].w) return -1;
  if (!t[q].w) return 1;
  int m = l + r >> 1, res = cmp(t[p].rs, t[q].rs, m + 1, r);
  if (!res) res = cmp(t[p].ls, t[q].ls, l, m);
  return res;
}

bool vis[N];
int d[N], pre[N];
std::vector<PII> g[N];

Z dfs(int o, int l, int r) {
  if (!t[o].w) return 0;
  if (l == r) return fpow(2, l);
  int m = l + r >> 1;
  return dfs(t[o].ls, l, m) + dfs(t[o].rs, m + 1, r);
}

constexpr int M(2e5);
void solve() {
  int n, m;
  std::cin >> n >> m;

  while (m--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  pw[0] = 1;
  for (int i = 1; i <= M; i++) {
    pw[i] = pw[i - 1] * 131;
  }

  std::priority_queue<PII, std::vector<PII>, std::function<bool(PII, PII)>> q([&](PII i, PII j) {
    return cmp(i.first, j.first, 0, M) > 0;
  });

  int s, t, r = 0;
  ins(r, 0, M, M);
  std::cin >> s >> t;
  for (int i = 1; i <= n; i++) {
    if (i != s) d[i] = r;
  }
  
  q.push({0, s});
  while (!q.empty()) {
    auto [_, x] = q.top();
    q.pop();
    if (x == t) break;
    if (vis[x]) continue;
    vis[x] = true;
    for (auto [y, z] : g[x]) {
      if (vis[y]) continue;
      int r = d[x];
      ins(r, 0, M, z);
      if (cmp(r, d[y], 0, M) < 0) {
        q.push({d[y] = r, y});
        pre[y] = x;
      }
    }
  }

  if (d[t] == r) {
    std::cout << "-1\n";
    return;
  }
  
  std::cout << dfs(d[t], 0, M) << "\n";

  std::vector<int> ans;
  for (int x = t; x != s; x = pre[x]) {
    ans.push_back(x);
  }
  ans.push_back(s);
  
  std::reverse(ans.begin(), ans.end());
  std::cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
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