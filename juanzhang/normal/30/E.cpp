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
const int maxn = 1e5 + 10;
int n;
char A[maxn], B[maxn];

int ext[maxn << 1];
int nxt[maxn], app[maxn];

namespace RMQ {
  int lg[maxn], pos[17][maxn];
  
  int query(int l, int r) {
    int k = lg[r - l + 1];
    int x = pos[k][l], y = pos[k][r - (1 << k) + 1];
    return ext[x] < ext[y] ? y : x;
  }
  
  void build(int *A) {
    rep(i, 1, n) pos[0][i] = i;
    rep(i, 2, n) lg[i] = lg[i >> 1] + 1;
    rep(i, 1, 16) rep(j, 1, n - (1 << i) + 1) {
      int x = pos[i - 1][j], y = pos[i - 1][j + (1 << (i - 1))];
      pos[i][j] = A[x] < A[y] ? y : x;
    }
  }
}

void manacher() {
  static char str[maxn << 1];
  int len = n + n + 1;
  str[1] = '#', str[0] = '!';
  rep(i, 1, n) str[i * 2] = A[i], str[i * 2 + 1] = '#';
  int pos = 0, mx = 0;
  rep(i, 1, len) {
    if (i <= mx) ext[i] = min(ext[2 * pos - i], mx - i);
    while (str[i - ext[i]] == str[i + ext[i]]) ext[i]++;
    if (i + ext[i] > mx) mx = i + ext[i], pos = i;
  }
  rep(i, 1, n) ext[i] = ext[i * 2] / 2;
}

void solve() {
  scanf("%s", A + 1);
  n = strlen(A + 1);
  memcpy(B, A, sizeof A);
  reverse(B + 1, B + n + 1);
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && B[i] != B[j + 1]) j = nxt[j];
    nxt[i] = j += B[i] == B[j + 1];
  }
  for (int i = 1, j = 0; i <= n; i++) {
    while (j && A[i] != B[j + 1]) j = nxt[j];
    j += A[i] == B[j + 1];
    if (!app[j]) app[j] = i;
  }
  manacher();
  RMQ::build(ext);
  int res = 0;
  int ansflgpos = -1;
  rep(i, 1, n) {
    if (res < ext[i] * 2 - 1) res = 2 * ext[i] - 1, ansflgpos = i;
  }
  int l1, r1, l2, r2, l3, r3;
  rep(i, 1, n) if (app[i]) {
    int rpos = n - i, lpos = app[i] + 1;
    if (lpos > rpos) break;
    int l = 1, r = (rpos - lpos) / 2 + 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      int pos = RMQ::query(lpos + mid - 1, rpos - mid + 1);
      ext[pos] >= mid ? l = mid : r = mid - 1;
    }
    int pos = RMQ::query(lpos + r - 1, rpos - r + 1);
    if (res < 2 * i + 2 * r - 1) {
      ansflgpos = -1;
      res = 2 * i + 2 * r - 1;
      l1 = app[i] - i + 1, r1 = app[i];
      l2 = pos - r + 1, r2 = pos + r - 1;
      l3 = n - i + 1, r3 = n;
    }
  }
  if (ansflgpos != -1) {
    printf("1\n%d %d\n", ansflgpos - ext[ansflgpos] + 1, res);
  } else {
    printf("3\n%d %d\n%d %d\n%d %d\n", l1, r1 - l1 + 1, l2, r2 - l2 + 1, l3, r3 - l3 + 1);
  }
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}