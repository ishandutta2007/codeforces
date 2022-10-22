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
const int maxn = 1e5 + 10;
int n, dis[maxn];

vector <int> E[maxn];

int bfs(int S) {
  static int Q[maxn];
  int l = 1, r = 1;
  memset(dis, -1, (n + 1) << 2);
  Q[1] = S, dis[S] = 0;
  while (l <= r) {
    int u = Q[l++];
    for (int v : E[u]) if (dis[v] == -1) {
      dis[v] = dis[u] + 1, Q[++r] = v;
    }
  }
  int T = 1;
  rep(i, 1, n) if (dis[i] > dis[T]) {
    T = i;
  }
  return T;
}

int A, B, DA, DB;

void solve() {
  cin >> n >> A >> B >> DA >> DB;
  rep(i, 1, n) E[i].clear();
  rep(i, 2, n) {
    int u = read(), v = read();
    E[u].push_back(v), E[v].push_back(u);
  }
  bfs(A);
  if (dis[B] <= DA) {
    return puts("Alice"), void();
  }
  int S = bfs(1);
  int T = bfs(S);
  int len = dis[T];
//  if (len & 1) {
//    puts()
//  } else {
    puts(DB > DA * 2 && DA * 2 < len ? "Bob" : "Alice");
//  }
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}