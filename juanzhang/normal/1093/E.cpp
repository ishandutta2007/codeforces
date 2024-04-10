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
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 4e5 + 10;
int n, q, A[maxn], B[maxn], P[maxn], Q[maxn];

int bsz = 700, bl[maxn];
//int bsz = 100;

struct BIT {
  int c[maxn];

  void add(int pos, int x) {
    for (; pos <= n; pos += pos & -pos) {
      c[pos] += x;
    }
  }

  int query(int pos) {
    int res = 0;
    for (; pos; pos &= pos - 1) {
      res += c[pos];
    }
    return res;
  }
} bit[300];

void solve() {
  cin >> n >> q;
  rep(i, 1, n) A[i] = read(), P[A[i]] = i;
  rep(i, 1, n) B[i] = read(), Q[B[i]] = i;
//  bsz = max(1.0, sqrt(n));
//bsz = 50;
  rep(i, 1, n) {
    bl[i] = (i - 1) / bsz + 1;
  }
  rep(i, 1, n) {
    bit[bl[P[i]]].add(Q[i], 1);
  }
  while (q--) {
//    putchar('#');
//    rep(i, 1, n) printf("%d%c", P[i], "\n "[i < n]);
//    putchar('#');
//    rep(i, 1, n) printf("%d%c", Q[i], "\n "[i < n]);
//    putchar('#');
//    rep(i, 1, n) printf("%d%c", Q[A[i]], "\n "[i < n]);

    int op = read(), l1 = read(), r1 = read();
    if (op == 1) {
      int res = 0;
      int l2 = read(), r2 = read();
      int L = bl[l1], R = bl[r1];
      rep(i, l1, min(r1, L * bsz)) {
        res += l2 <= Q[A[i]] && Q[A[i]] <= r2;
      }
      if (L == R) {
        printf("%d\n", res); continue;
      }
      rep(i, (R - 1) * bsz + 1, r1) {
        res += l2 <= Q[A[i]] && Q[A[i]] <= r2;
      }
      rep(i, L + 1, R - 1) {
        res += bit[i].query(r2) - bit[i].query(l2 - 1);
      }
      printf("%d\n", res);
    } else {
      int x = B[l1], y = B[r1];
      bit[bl[P[x]]].add(l1, -1), bit[bl[P[x]]].add(r1, 1);
      bit[bl[P[y]]].add(r1, -1), bit[bl[P[y]]].add(l1, 1);
      swap(B[l1], B[r1]), swap(Q[x], Q[y]);
    }
  }
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}