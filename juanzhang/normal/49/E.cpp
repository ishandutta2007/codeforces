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

char A[55], B[55];

vector <int> fuck[26], shit[26 * 26];

int dp[55][55];
bool F[55][55][26], G[55][55][26];

void solve() {
  int qcnt;
  scanf("%s %s %d", A + 1, B + 1, &qcnt);
  while (qcnt--) {
    char str[10];
    scanf("%s", str);
    char c = *str, c1 = str[3], c2 = str[4];
    fuck[c - 'a'].push_back(26 * (c1 - 'a') + c2 - 'a');
    shit[26 * (c1 - 'a') + c2 - 'a'].push_back(c - 'a');
  }
  int N = strlen(A + 1);
  rep(i, 1, N) F[i][i][A[i] - 'a'] = 1;
  rep(sz, 2, N) {
    rep(i, 1, N - sz + 1) {
      int j = i + sz - 1;
      rep(k, i, j - 1) {
        rep(c1, 0, 25) if (F[i][k][c1]) {
          rep(c2, 0, 25) if (F[k + 1][j][c2]) {
            for (int x : shit[c1 * 26 + c2]) F[i][j][x] = 1;
          }
        }
      }
    }
  }
  int M = strlen(B + 1);
  rep(i, 1, M) G[i][i][B[i] - 'a'] = 1;
  rep(sz, 2, M) {
    rep(i, 1, M - sz + 1) {
      int j = i + sz - 1;
      rep(k, i, j - 1) {
        rep(c1, 0, 25) if (G[i][k][c1]) {
          rep(c2, 0, 25) if (G[k + 1][j][c2]) {
            for (int x : shit[c1 * 26 + c2]) G[i][j][x] = 1;
          }
        }
      }
    }
  }
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  rep(i, 1, N) {
    rep(j, 1, M) {
      dp[i][j] = 1e9;
      rep(p, 0, i - 1) rep(q, 0, j - 1) if (dp[p][q] != -1) {
        rep(ch, 0, 25) if (F[p + 1][i][ch] && G[q + 1][j][ch]) {
          chkmin(dp[i][j], dp[p][q] + 1);
        }
      }
      if (dp[i][j] > 1e8) dp[i][j] = -1;
    }
  }
  printf("%d\n", dp[N][M]);
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}