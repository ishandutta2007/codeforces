#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
  string what;
  __timestamper(const char* what) : what(what){};
  __timestamper(const string& what) : what(what){};
  ~__timestamper(){
    TIMESTAMPf("%s", what.data());
	}
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

const int MOD = (int)1e9 + 7;

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
      vector<string> a(n);
      for (int i = 0; i < n; i++) {
          static char buf[22222];
          scanf("%s", buf);
          a[i] = buf;
      }

      vector<vector<int>> right(n, vector<int>(m, 0));
      vector<vector<int>> down(n, vector<int>(m, 0));

      for (int i = 0; i < n; i++) {
          right[i][m - 1] = 0;
          for (int j = m - 2; j >= 0; j--) {
              right[i][j] = right[i][j + 1] + (a[i][j + 1] == '.');
          }
      }
      for (int j = 0; j < m; j++) {
          down[n - 1][j] = 0;
          for (int i = n - 2; i >= 0; i--) {
              down[i][j] = down[i + 1][j] + (a[i + 1][j] == '.');
          }
      }

//      for (int i = 0; i < n; i++) {
//          dbv(right[i]);
//      }
      vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, 0)));
      dp[1][1][0] = 1;
      if (n > 1) dp[2][1][0] = MOD - 1;

      dp[1][1][1] = 1;
      if (m > 1) dp[1][2][1] = MOD - 1;

      for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
              add(dp[i][j][1], dp[i][j - 1][1]);
              add(dp[i][j][0], dp[i - 1][j][0]);
              if (j < m) {
                  int last = j + right[i - 1][j - 1];
//                  for (int t = j + 1; t <= last; t++) add(dp[i][t][1], dp[i][j][0]);
                  add(dp[i][j + 1][1], dp[i][j][0]);
                  if (last < m) add(dp[i][last+1][1], MOD - dp[i][j][0]);
              }
              if (i < n) {
                  int last = i + down[i - 1][j - 1];
//                  for (int t = i + 1; t <= last; t++) add(dp[t][j][0], dp[i][j][1]);
                  add(dp[i + 1][j][0], dp[i][j][1]);
                  if (last < n) add(dp[last+1][j][0], MOD - dp[i][j][1]);
              }
          }
      }
//      for (int i = 0; i <= n; i++) {
//          for (int j= 0; j <= m; j++) {
//              cout << "("<<dp[i][j][0] << "," << dp[i][j][1] << ") ";
//          }
//          cout << endl;
//      }

      int ans = 0;
      add(ans, dp[n][m][0]);
      add(ans, dp[n][m][1]);

      if (n == 1 && m == 1) ans = 1;
      printf("%d\n", ans);
  }

  return 0;
}