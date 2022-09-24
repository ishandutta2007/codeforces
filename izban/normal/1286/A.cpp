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

void upd(int &x, int y) {
    x = min(x, y);
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int n;
  while (cin >> n) {
      vector<int> a(n);
      vector<int> used(n);
      for (int i = 0; i < n; i++) {
          cin >> a[i];
          a[i]--;
          if (a[i] >= 0) {
              used[a[i]] = 1;
          } else {

          }
      }

      int c0 = 0, c1 = 0;
      for (int i = 0; i < n; i++) {
          if (!used[i]) {
              if (i % 2 == 0) c0++;
              else c1++;
          }
      }
      vector<int> c({c0, c1});

      const int INF = 1e9;
      vector<vector<vector<vector<int>>>> dp(n + 1,
              vector<vector<vector<int>>>(c0 + 1,
                      vector<vector<int>>(c1 + 1,
                              vector<int>(2, INF))));
      dp[0][0][0][0] = dp[0][0][0][1] = 0;
      for (int i = 0; i < n; i++) {
          vector<int> x(2);
          for (x[0] = 0; x[0] <= c[0]; x[0]++) {
              for (x[1] = 0; x[1] <= c[1]; x[1]++) {
                  for (int last = 0; last < 2; last++) {
                      if (dp[i][x[0]][x[1]][last] == INF) continue;

                      for (int nw = 0; nw < 2; nw++) {
                          if (a[i] != -1 && nw != a[i] % 2) continue;
                          if (x[nw] + (a[i] == -1) <= c[nw]) {
                              int d0 = nw == 0;
                              int d1 = nw == 1;
                              if (a[i] != -1) d0 = d1 = 0;
                              upd(dp[i + 1][x[0] + d0][x[1] + d1][nw], dp[i][x[0]][x[1]][last] + (last != nw));
                          }
                      }
                  }
              }
          }
      }
      int ans = min(dp[n][c0][c1][0], dp[n][c0][c1][1]);
      cout << ans << endl;
  }

  return 0;
}