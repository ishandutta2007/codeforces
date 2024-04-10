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
int n, A[maxn];

int lef[maxn], rig[maxn];

int st[maxn], ls[maxn], rs[maxn];

void solve() {
  cin >> n;
  int top = 0, pos[32];
  memset(pos, 0, sizeof pos);
  rep(i, 1, n) {
    A[i] = read();
    lef[i] = 1;
    rep(j, 0, 29) {
      if (A[i] >> j & 1) {
        pos[j] = i;
      } else {
        chkmax(lef[i], pos[j] + 1);
      }
    }
    while (top && A[st[top]] < A[i]) top--;
    ls[i] = st[top] + 1, st[++top] = i;
  }
  top = 0, st[0] = n + 1;
  fill(pos, pos + 30, n + 1);
  per(i, n, 1) {
    rig[i] = n;
    rep(j, 0, 29) {
      if (A[i] >> j & 1) {
        pos[j] = i;
      } else {
        chkmin(rig[i], pos[j] - 1);
      }
    }
    while (top && A[st[top]] <= A[i]) top--;
    rs[i] = st[top] - 1, st[++top] = i;
  }
  ll ans = 0;
  rep(i, 1, n) {
    int L = max(lef[i], ls[i]);
    int R = min(rig[i], rs[i]);
    ans += 1ll * (R - i + 1) * (i - L + 1);
  }
  ans = 1ll * n * (n + 1) / 2 - ans;
  cout << ans << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}