#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1005, LOG = 10;

int rmq[LOG][LOG][MAXN][MAXN];
int dp[MAXN][MAXN];

int readint() {
  char c;
  do {
    c = getchar();
  } while(c != '0' && c != '1');
  return c - '0';
}

int get(int x, int y, int a, int b) {
  int k, l;
  for(k = 0; (1 << k) <= a - x + 1; ++k) {}
  for(l = 0; (1 << l) <= b - y + 1; ++l) {}

  --k; --l;

  int dx = a - x - (1 << k) + 1;
  int dy = b - y - (1 << l) + 1;

  int ret = rmq[k][l][a][b];
  ret = max(ret, rmq[k][l][a - dx][b]);
  ret = max(ret, rmq[k][l][a][b - dy]);
  ret = max(ret, rmq[k][l][a - dx][b - dy]);

  return ret;
}

int main() {
    
  ios_base::sync_with_stdio(false); cin.tie(0);
    
  int n, m; cin >> n >> m;

  FOR(i, 1, n + 1) FOR(j, 1, m + 1) {
    int x; cin >> x;
    if(x) {
      dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
    }
  }

  FOR(i, 1, n + 1) FOR(j, 1, m + 1) {
    rmq[0][0][i][j] = dp[i][j];
    for(int l = 1; (1 << l) <= j; ++l) {
      rmq[0][l][i][j] = max(rmq[0][l - 1][i][j], rmq[0][l - 1][i][j - (1 << (l-1))]);
    }
    for(int k = 1; (1 << k) <= i; ++k) for(int l = 0; (1 << l) <= j; ++l) {
      rmq[k][l][i][j] = max(rmq[k - 1][l][i][j], rmq[k - 1][l][i - (1 << (k-1))][j]);
    }
  }

  int t; cin >> t;
  while(t --> 0) {
    int x, y, a, b; cin >> x >> y >> a >> b;

    int lo = 0, hi = min(a - x, b - y) + 1;
    while(lo < hi) {
      int mid = (lo + hi + 1) >> 1;

      if(get(x + mid - 1, y + mid - 1, a, b) >= mid)
        lo = mid;
      else
        hi = mid - 1;
    }
    cout << lo << "\n";
  }
}