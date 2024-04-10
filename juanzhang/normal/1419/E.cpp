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
int N;

int cnt, pri[9], id[1 << 9];

vector <int> fac, num[1 << 9];

void getfac(int x) {
  fac.clear();
  rep(i, 1, sqrt(x) + 0.5) if (x % i == 0) {
    if (i != 1) fac.push_back(i);
    if (x / i != i) fac.push_back(x / i);
  }
  cnt = 0;
  rep(i, 2, sqrt(x) + 0.5) if (x % i == 0) {
    pri[cnt++] = i;
    while (x % i == 0) x /= i;
  }
  if (x > 1) pri[cnt++] = x;
  rep(i, 0, (1 << cnt) - 1) num[i].clear();
  for (int x : fac) {
    int S = 0;
    rep(i, 0, cnt - 1) if (x % pri[i] == 0) S |= 1 << i;
    num[S].push_back(x);
  }
}

void solve() {
  cin >> N;
  getfac(N);
  rep(i, 1, (1 << cnt) - 1) {
    id[i] = i;
  }
  rep(i, 1, cnt - 1) {
    swap(id[1 << i], id[(1 << i) + (1 << (i - 1))]);
  }
  bool flg = cnt == 2;
  if (flg && (int) num[3].size() > 1) {
    rep(i, 1, num[3].size() - 1) printf("%d ", num[3][i]);
    for (int x : num[1]) printf("%d ", x);
    printf("%d ", num[3][0]);
    for (int x : num[2]) printf("%d ", x);
    flg = 0;
  } else {
    rep(i, 1, (1 << cnt) - 1) {
      for (int x : num[id[i]]) printf("%d ", x);
    }
  }
  puts("");
  puts(flg ? "1" : "0");
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}