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
const int maxn = 1e6 + 10;
int n, A[maxn], B[maxn], val[maxn];

int check(int mid) {
  memset(val, 0, (n + 1) << 2);
  val[1] = mid, val[2] = A[1] - mid;
  rep(i, 2, n) {
    if (val[i] >= B[i]) {
      val[i % n + 1] += A[i];
    } else if (val[i] + A[i] >= B[i]) {
      val[i % n + 1] += A[i] - (B[i] - val[i]), val[i] = B[i];
    } else {
      return 1;
    }
  }
  if (val[1] < B[1]) return 2;
  return 0;
}

void solve() {
  cin >> n;
  ll s1 = 0, s2 = 0;
  rep(i, 1, n) s1 += B[i] = read();
  rep(i, 1, n) s2 += A[i] = read();
  if (s1 > s2) return puts("NO"), void();
  int l = 0, r = min(A[1], B[1]);
  while (l <= r) {
    int mid = (l + r) >> 1, val = check(mid);
    if (!val) {
      return puts("YES"), void();
    } else if (val == 1) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  puts("NO");
}

int main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}