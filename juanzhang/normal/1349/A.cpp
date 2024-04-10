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
const int maxn = 2e5 + 10;
int n, val1[maxn], val2[maxn], cnt[maxn];

void add(int v, int x) {
  if (val1[v] > x) {
    val2[v] = val1[v], val1[v] = x;
  } else if (val2[v] > x) {
    val2[v] = x;
  }
}

void solve() {
  memset(val1, 0x3f, sizeof val1);
  memset(val2, 0x3f, sizeof val2);
  cin >> n;
  rep(T, 1, n) {
    int x = read();
    int tmp = sqrt(x) + 0.5;
    rep(i, 2, tmp) if (x % i == 0) {
      int s = 0;
      while (x % i == 0) x /= i, s++;
      add(i, s), cnt[i]++;
    }
    if (x > 1) add(x, 1), cnt[x]++;
  }
  ll ans = 1;
  rep(i, 1, 2e5) {
    if (cnt[i] < n - 1) continue;
    if (cnt[i] < n) val2[i] = val1[i];
    if (val2[i] < 1e9) {
      while (val2[i]--) ans *= i;
    }
  }
  cout << ans << endl;
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}