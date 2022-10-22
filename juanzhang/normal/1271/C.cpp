#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

const int maxn = 4e5 + 10;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n;

struct point {
  int x, y;
} S, a[maxn];

int main() {
  scanf("%d %d %d", &n, &S.x, &S.y);
  rep(i, 1, n) scanf("%d %d", &a[i].x, &a[i].y);
  int res = 0, rx = -1, ry = -1;
  rep(t, 0, 3) {
    int x = S.x + dx[t], y = S.y + dy[t];
    if (x < 0 || y < 0 || x > 1e9 || y > 1e9) continue;
    int cnt = 0;
    rep(i, 1, n) {
      if (t == 0) cnt += a[i].x <= x;
      if (t == 1) cnt += a[i].y >= y;
      if (t == 2) cnt += a[i].x >= x;
      if (t == 3) cnt += a[i].y <= y;
    }
    if (cnt > res) res = cnt, rx = x, ry = y;
  }
  printf("%d\n%d %d", res, rx, ry);
  return 0;
}