#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int M = 55;
const int N = 25050;
const int mod = 1e9 + 7;
namespace ac {

int id = 1, ch[N][10], fail[N];
bool tag[N];
void insert(char *s, int n) {
  int u = 1;
  for(int i = 0; i < n; i ++) {
    int &v = ch[u][s[i]];
    u = v ? v : v = ++ id;
  }
  tag[u] = 1;
}
void build() {
  queue<int> q; int v = 0; fail[1] = 1;
  rep(i, 0, 9) if(v = ch[1][i], v) {
    q.push(v); fail[v] = 1;
  } else ch[1][i] = 1;
  while(q.size()) {
    int u = q.front(); q.pop(); tag[u] |= tag[fail[u]];
    rep(i, 0, 9) if(v = ch[u][i], v) {
      q.push(v); fail[v] = ch[fail[u]][i];
    } else ch[u][i] = ch[fail[u]][i];
  }
}

}
int n, m, dp[2][N][2][2];
char s[M * M], a[M], b[M];
inline void upd(int &x, int y) {
  (x += y) >= mod ? x -= mod : 0;
}
int solve(char *a) {
  int v, cur;
  int row = 0;
  rep(u, 1, ac::id) memset(dp[row][u], 0, sizeof (dp[row][u]));
  dp[0][1][1][0] = 1;
  rep(i, 0, m - 1) {
    row ^= 1;
    rep(u, 1, ac::id) memset(dp[row][u], 0, sizeof (dp[row][u]));
    rep(u, 1, ac::id) {
      rep(lim, 0, 1) {
        rep(t, 0, 1) if(cur = dp[row ^ 1][u][lim][t], cur) {
          int z = lim ? a[i + 1] : 9;
          rep(k, 0, z) {
            v = ac::ch[u][k];
            upd(dp[row][v][lim && (k == z)][t || ac::tag[v]], cur);
          }
        }
      }
    }
  }
  int res = 0;
  rep(u, 1, ac::id)
    rep(lim, 0, 1)
      upd(res, dp[row][u][lim][1]);
  return res;
}
int main() {
  scanf("%s%s%s", s + 1, a + 1, b + 1);
  n = strlen(s + 1); m = strlen(a + 1);
  if(n < m / 2) { puts("0"); return 0; }
  rep(i, 1, n) s[i] &= 15;
  rep(i, 1, m) a[i] &= 15, b[i] &= 15;
  -- a[m];
  per(i, m, 1) {
    if(a[i] < 0) {
      a[i] += 10; -- a[i - 1];
    }
  }
  rep(i, 1, n - (m / 2) + 1)
    ac::insert(&s[i], m / 2);
  ac::build();
  printf("%d\n", (solve(b) - solve(a) + mod) % mod);
  return 0;
}