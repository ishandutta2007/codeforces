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
int n, P, tot, a[40], data[20];

set <int> mp;

int main() {
  cin >> n >> P;
  rep(i, 1, n) a[i] = read() % P;
  tot = n - n / 2;
  rep(i, 1, tot) data[i - 1] = a[n - tot + i];
  int all = (1 << tot) - 1;
  rep(S, 0, all) {
    int sum = 0;
    rep(i, 0, tot - 1) if (S >> i & 1) {
      sum += data[i];
      if (sum >= P) sum -= P;
    }
    mp.insert(sum);
  }
  int res = *mp.rbegin();
  tot = n / 2;
  rep(i, 1, tot) data[i - 1] = a[i];
  all = (1 << tot) - 1;
  rep(S, 0, all) {
    int sum = 0;
    rep(i, 0, tot - 1) if (S >> i & 1) {
      sum += data[i];
      if (sum >= P) sum -= P;
    }
    int val = *mp.rbegin();
    int tmp = (sum + val) % P;
    chkmax(res, tmp);
    auto it = mp.lower_bound(P - sum);
    if (it == mp.begin()) continue;
    --it;
    chkmax(res, sum + (*it));
  }
  cout << res;
  return 0;
}