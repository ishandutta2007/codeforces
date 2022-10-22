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

const int maxn = 1e5 + 10;
int n, a[maxn];

int par[maxn], sz[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  if ((x = find(x)) != ((y = find(y)))) {
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x, sz[x] += sz[y];
  }
}

int main() {
  n = read();
  rep(i, 1, n) par[i] = i, sz[i] = 1;
  rep(i, 1, n) {
    a[i] = read();
    unite(i, a[i]);
  }
  multiset <int> S;
  rep(i, 1, n) if (find(i) == i) {
    S.insert(sz[i]);
  }
  if (S.size() < 2) {
    cout << 1ll * n * n;
  } else {
    int x = *S.rbegin();
    S.erase(S.find(x));
    int y = *S.rbegin();
    S.erase(S.find(y));
    long long res = 1ll * (x + y) * (x + y);
    for (int x : S) {
      res += 1ll * x * x;
    }
    cout << res;
  }
  return 0;
}