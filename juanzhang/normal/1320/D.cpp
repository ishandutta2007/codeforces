#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

const int maxn = 2e5 + 10;
int n, q, a[maxn], sum[maxn], pos[maxn], lef[maxn], rig[maxn];

typedef pair <int, int> pii;
const int P1 = 1e9 + 7, P2 = 1e9 + 9;
int len, base, pow1[maxn], pow2[maxn];

struct Hash {
  int v1, v2;

  Hash() {}
  Hash(int x, int y) : v1(x), v2(y) {}

  void print() {
    printf("#(%d %d)\n", v1, v2);
  }
  
  void get(const Hash &o, int x) {
    v1 = (1ll * o.v1 * base + x) % P1;
    v2 = (1ll * o.v2 * base + x) % P2;
  }

  bool operator == (const Hash &o) const {
    return v1 == o.v1 && v2 == o.v2;
  }
} data[maxn];

Hash getsum(int l, int r) {
  return Hash((data[r].v1 + 1ll * (P1 - data[l - 1].v1) * pow1[r - l + 1]) % P1,
              (data[r].v2 + 1ll * (P2 - data[l - 1].v2) * pow2[r - l + 1]) % P2);
}

Hash query(int l, int r) {
  int L = rig[l], R = lef[r];
  if (L > R) return {(r - l + 1) % 2 + 1, (r - l + 1) % 2 + 1};
  int sz = pos[R] - pos[L] + 1;
  Hash res = getsum(pos[L], pos[R]);
  if ((L - l) % 2 != 0) {
    res.v1 = (2ll * pow1[sz] + res.v1) % P1;
    res.v2 = (2ll * pow2[sz] + res.v2) % P2;
  }
  if ((r - R) % 2 != 0) {
    res.get(res, 2);
  }
  return res;
}

int main() {
  base = Rnd();
  if (base < 0) base = -base;
  base %= 19260817, base += 257;
  pow1[0] = pow2[0] = 1;
  for (int i = 1; i < maxn; i++) {
    pow1[i] = 1ll * base * pow1[i - 1] % P1;
    pow2[i] = 1ll * base * pow2[i - 1] % P2;
  }
  cin >> n;
  lef[0] = 0, rig[n + 1] = n + 1;
  rep(i, 1, n) scanf("%1d", a + i);
  rep(i, 1, n) lef[i] = a[i] ? lef[i - 1] : i;
  per(i, n, 1) rig[i] = a[i] ? rig[i + 1] : i;
  rep(i, 1, n) {
    pos[i] = pos[i - 1];
    if (a[i] && a[i + 1]) continue;
    if (!a[i] || (i - lef[i]) % 2 != 0) {
      pos[i]++;
      data[pos[i]].get(data[pos[i] - 1], a[i] + 1);
    }
  }
  len = pos[n];
  cin >> q;
  while (q--) {
    int l1 = read(), l2 = read(), len = read();
    int r1 = l1 + len - 1, r2 = l2 + len - 1;
    puts(sum[r1] - sum[l1] == sum[r2] - sum[l2] && query(l1, r1) == query(l2, r2) ? "Yes" : "No");
  }
  return 0;
}