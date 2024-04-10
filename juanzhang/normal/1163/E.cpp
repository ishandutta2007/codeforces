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
int n, A[200010];

vector <int> vec;

struct LB {
  int bit[18];
  
  void ins(int x) {
    int tmp = x;
    per(i, 17, 0) if (x >> i & 1) {
      if (!bit[i]) {
        vec.push_back(tmp);
        return bit[i] = x, void();
      }
      x ^= bit[i];
    }
  }
} base;

int cnt, ans[1 << 18 | 5];

void dfs(int now) {
  static int cur;
  if (now == cnt) return;
  dfs(now + 1), ans[++cur] = vec[now], dfs(now + 1);
}

void solve() {
  cin >> n;
  rep(i, 1, n) A[i] = read();
  sort(A + 1, A + n + 1);
  for (int i = 0, j = 1; i < 19; i++) {
    for (; j <= n && (A[j] < 1 << i); j++) base.ins(A[j]);
    if ((int) vec.size() == i) cnt = i;
  }
  dfs(0);
  printf("%d\n", cnt);
  reverse(ans + 1, ans + (1 << cnt) + 1);
  rep(i, 1, 1 << cnt) printf("%d ", ans[i] ^= ans[i - 1]);
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}