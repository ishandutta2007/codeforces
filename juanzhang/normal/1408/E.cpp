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
typedef pair <int, int> pii;
const int maxn = 2e5 + 10;
int N, M, n, m, A[maxn], B[maxn];

int par[maxn];

struct edge {
  int u, v, w;
} E[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void solve() {
  cin >> m >> n;
  rep(i, 1, m) A[i] = read();
  rep(i, 1, n) B[i] = read();
  ll sum = 0;
  N = n + m, M = 0;
  rep(i, 1, m) {
    int k = read();
    while (k--) {
      int x = read();
      E[++M] = {i, m + x, A[i] + B[x]}, sum += A[i] + B[x];
    }
  }
  rep(i, 1, N) par[i] = i;
  sort(E + 1, E + M + 1, [] (edge P, edge Q) {
    return P.w > Q.w;
  });
  ll ans = 0;
  rep(i, 1, M) {
    int u = E[i].u, v = E[i].v;
    if (find(u) != find(v)) {
      par[find(u)] = par[find(v)], ans += E[i].w;
    }
  }
  cout << sum - ans << endl;
}

signed main() {
  solve();
  return 0;
}