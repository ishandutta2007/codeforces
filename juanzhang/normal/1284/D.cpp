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

typedef unsigned long long u64;
const int maxn = 1e5 + 10;
int n;
u64 ansA[maxn], ansB[maxn];

struct segment {
  int l, r; u64 val;
  
  bool operator < (const segment &o) const {
    return l < o.l || (l == o.l && r < o.r);
  }
} A[maxn], B[maxn];

void solve(segment *A, u64 *ans) {
  static u64 sum[maxn], tmp[maxn];
  memset(tmp, 0, sizeof tmp);
  sort(A + 1, A + n + 1);
  rep(i, 1, n) {
    sum[i] = sum[i - 1] ^ A[i].val;
  }
  rep(i, 1, n) {
    int l = i + 1, r = n, res = n + 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      A[mid].l > A[i].r ? r = (res = mid) - 1 : l = mid + 1;
    }
    ans[i] = sum[res - 1] ^ sum[i];
    tmp[i] ^= A[i].val, tmp[res] ^= A[i].val;
  }
  rep(i, 1, n) {
    tmp[i] ^= tmp[i - 1];
    ans[i] ^= tmp[i];
  }
  sort(ans + 1, ans + n + 1);
}

int main() {
  n = read();
  rep(i, 1, n) {
    A[i].l = read(), A[i].r = read(), B[i].l = read(), B[i].r = read();
    A[i].val = B[i].val = (u64((unsigned) Rnd()) << 32) | ((unsigned) Rnd());
  }
  solve(A, ansA), solve(B, ansB);
  rep(i, 1, n) {
    if (ansA[i] != ansB[i]) {
      return puts("NO"), 0;
    }
  }
  puts("YES");
  return 0;
}