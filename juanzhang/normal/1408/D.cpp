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
const int maxn = 2010;
int n, m;

struct node {
  int x, y;
  
  bool operator < (const node &o) const {
    return x < o.x;
  }
} A[maxn], B[maxn];

int data[1000010];

void solve() {
  cin >> n >> m;
  rep(i, 1, n) {
    A[i].x = read(), A[i].y = read();
  }
  rep(i, 1, m) {
    B[i].x = read(), B[i].y = read();
  }
  sort(B + 1, B + m + 1);
  rep(i, 1, n) {
    int yy = 0;
    per(j, m, 1) if (B[j].x >= A[i].x) {
      chkmax(yy, B[j].y);
      chkmax(data[B[j].x - A[i].x], yy - A[i].y + 1);
    }
  }
  int ans = 1e9, yy = 0;
  per(i, 1e6 + 1, 0) {
    chkmax(yy, data[i]);
    chkmin(ans, i + yy);
  }
  cout << ans << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}