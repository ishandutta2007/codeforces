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

typedef long long ll;
const int maxn = 1e6 + 10, P = 1e9 + 7;
int n, a[maxn], inv[maxn];

int qp(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % P) {
    if (k & 1) res = 1ll * res * a % P;
  }
  return res;
}

int main() {
  cin >> n;
  rep(i, 1, n) a[i] = read();
  inv[1] = 1;
  int fac = 1;
  rep(i, 2, n) {
    fac = 1ll * fac * i % P;
    inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
  }
  sort(a + 1, a + n + 1);
  int res = 0;
  rep(i, 1, n) {
    int j = i;
    while (j < n && a[i] == a[j + 1]) j++;
    if (j < n) res = (res + 1ll * a[i] * (j - i + 1) % P * inv[n - i + 1]) % P;
    i = j;
  }
  cout << 1ll * res * fac % P;
  return 0;
}