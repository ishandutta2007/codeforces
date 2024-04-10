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
const int cnt[] = {1, 0, 1, 2, 9};
int n, k;

ll binom(int n, int k) {
  ll res = 1;
  per(i, n, n - k + 1) res *= i;
  rep(i, 1, k) res /= i;
  return res;
}

int main() {
  ll res = 0;
  cin >> n >> k;
  rep(i, 0, k) {
    res += cnt[i] * binom(n, i);
  }
  cout << res;
  return 0;
}