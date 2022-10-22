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
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

const int maxn = 505;
char A[maxn][maxn];
int n, m, q, tot, lg[maxn], sum[4][maxn][maxn], val[9][9][maxn][maxn];

inline int get(char c) {
  if (c == 'R') return 0;
  if (c == 'G') return 1;
  if (c == 'Y') return 2;
  if (c == 'B') return 3;
  return -1;
}

bool getsum(int k, int x1, int y1, int x2, int y2) {
  return sum[k][x2][y2] - sum[k][x2][y1 - 1] - sum[k][x1 - 1][y2] + sum[k][x1 - 1][y1 - 1] == 0;
}

int query(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  int k1 = lg[x2 - x1 + 1], k2 = lg[y2 - y1 + 1];
  return max(max(val[k1][k2][x1][y1], val[k1][k2][x2 - (1 << k1) + 1][y2 - (1 << k2) + 1]),
             max(val[k1][k2][x2 - (1 << k1) + 1][y1], val[k1][k2][x1][y2 - (1 << k2) + 1]));
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  rep(i, 1, n) scanf("%s", A[i] + 1);
  rep(k, 0, 3) rep(i, 1, n) rep(j, 1, m) {
    sum[k][i][j] = sum[k][i - 1][j] + sum[k][i][j - 1] - sum[k][i - 1][j - 1] + (get(A[i][j]) != k);
  }
  rep(i, 1, n - 1) rep(j, 1, m - 1) {
    if (A[i][j] != 'R' || A[i][j + 1] != 'G' || A[i + 1][j] != 'Y' || A[i + 1][j + 1] != 'B') {
      continue;
    }
    int mx0 = 1, mx1 = 1, mx2 = 1, mx3 = 1;
    per(k, min(i, j), 1) {
      if (getsum(0, i - k + 1, j - k + 1, i, j)) {
        mx0 = k; break;
      }
    }
    per(k, min(i, m - j), 1) {
      if (getsum(1, i - k + 1, j + 1, i, j + k)) {
        mx1 = k; break;
      }
    }
    per(k, min(n - i, j), 1) {
      if (getsum(2, i + 1, j - k + 1, i + k, j)) {
        mx2 = k; break;
      }
    }
    per(k, min(n - i, m - j), 1) {
      if (getsum(3, i + 1, j + 1, i + k, j + k)) {
        mx3 = k; break;
      }
    }
    int res = min(min(mx0, mx1), min(mx2, mx3));
    chkmax(tot, res);
    val[0][0][i][j] = res;
  }
  rep(i, 2, max(n, m)) lg[i] = lg[i >> 1] + 1;
  rep(p, 0, 8) rep(q, 0, 8) if (p || q) {
    rep(i, 1, n - (1 << p) + 1) rep(j, 1, m - (1 << q) + 1) {
      val[p][q][i][j] = p ? max(val[p - 1][q][i][j], val[p - 1][q][i + (1 << (p - 1))][j]) :
                            max(val[p][q - 1][i][j], val[p][q - 1][i][j + (1 << (q - 1))]);
    }
  }
  while (q--) {
    int x1 = read(), y1 = read(), x2 = read(), y2 = read();
    int l = 0, r = min(tot, min(x2 - x1 + 1, y2 - y1 + 1)), mid;
    while (l < r) {
      mid = (l + r + 1) >> 1;
      query(x1 + mid - 1, y1 + mid - 1, x2 - mid, y2 - mid) >= mid ? l = mid : r = mid - 1;
    }
    printf("%d\n", r * r * 4);
  }
  return 0;
}