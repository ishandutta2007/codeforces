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
int n, k, A[105];

void solve() {
  cin >> n >> k;
  rep(i, 1, n) A[i] = read();
  int m = 0;
  int T = 0;
  while (++T < 500) {
    int pos = 1;
    while (pos <= n && !A[pos]) pos++;
    if (pos > n) break;
    set <int> S;
    int lst = 0;
    if (pos > 1) S.insert(0);
    rep(i, pos, n) {
      S.insert(A[i]);
      if ((int) S.size() > k) {
        rep(j, i, n) A[j] -= lst;
        break;
      }
      lst = A[i], A[i] = 0;
    }
    m++;
//    putchar('#');
//    rep(i,1,n)printf("%d%c",A[i],"\n "[i<n]);
  }
  cout << (T > 400 ? -1 : m) << endl;
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}