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
const int maxn = 2e5 + 10;
int n, ans[maxn];
char A[maxn];

void solve() {
  scanf("%d %s", &n, A + 1);
  int res=0;
  queue <int> q0, q1;
  rep(i, 1, n) {
    if (A[i] == '1') {
      if (q0.empty()) {
        res++, ans[i] = res, q1.push(res);
      } else {
        ans[i] = q0.front(), q0.pop(), q1.push(ans[i]);
      }
    } else {
      if (q1.empty()) {
        res++, ans[i] = res, q0.push(res);
      } else {
        ans[i] = q1.front(), q1.pop(), q0.push(ans[i]);
      }
    }
  }
  printf("%d\n",res);
  rep(i,1,n)printf("%d%c",ans[i],"\n "[i<n]);
}

int main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}