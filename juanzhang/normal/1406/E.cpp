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

typedef double db;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
const int maxn = 1e5 + 10;
int N;

bool del[maxn];
int tot, pri[maxn];

void sieve() {
  rep(i, 2, N) if (!pri[i]) {
    pri[++tot] = i;
    for (int j = i + i; j <= N; j += i) {
      pri[j] = 1;
    }
  }
}

void solve() {
  cin >> N;
  sieve();
//  printf("#%d\n", tot);
  vi tmp;
  int bl = 0;
  rep(i, 1, tot) {
    printf("B %d\n", pri[i]);
    int cnt = 0;
    for (int j = pri[i]; j <= N; j += pri[i]) {
      cnt += !del[j], del[j] = 1;
    }
    fflush(stdout);
    int x = read();
    if (x != cnt) {
      tmp.push_back(pri[i]);
    }
    if ((i == tot || i % 100 == 0) && !bl && tmp.empty()) {
      puts("A 1");
      fflush(stdout);
      cnt = 0;
      rep(j, 1, N) cnt += !del[j];
      int x = read();
      if (x != cnt) bl = i;
    }
  }
  chkmax(bl, 100);
  rep(t, max(1, bl - 99), min(tot, bl)) {
    int i = pri[t];
    printf("A %d\n", i);
    fflush(stdout);
    int x = read();
    if (x) {
      tmp.push_back(i);
      break;
    }
  }
  int res = 1;
  for (int p : tmp) {
    res *= p;
    for (ll t = (ll) p * p; t <= N; t *= p) {
      printf("A %d\n", (int) t);
      fflush(stdout);
      int x = read();
      if (!x) break;
      res *= p;
    }
  }
  printf("C %d\n", res);
  fflush(stdout);
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}