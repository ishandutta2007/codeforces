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

const ll INF = 1e18;

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int T;
  scanf("%d", &T);
  while (T--) {
      int n, m;
      scanf("%d%d", &n, &m);
      vector<int> b(n), w(n);
      for (int i = 0; i < n; i++) scanf("%d", &b[i]);
      for (int i = 0; i < n; i++) scanf("%d", &w[i]);
      vector<vector<int>> e(n);
      for (int i = 0; i < n - 1; i++) {
          int u, v;
          scanf("%d%d", &u, &v);
          u--; v--;
          e[u].push_back(v);
          e[v].push_back(u);
      }

      vector<vector<pair<int, ll>>> dp(n);
      vector<int> sz(n);
      function<void(int, int)> dfs = [&](int v, int pr) {
          sz[v] = 1;
          vector<pair<int, ll>> cdp(sz[v] + 1, make_pair(0, -INF));
          cdp[0] = make_pair(0, w[v] - b[v]);

          for (int to : e[v]) {
              if (to == pr) continue;
              dfs(to, v);

              vector<pair<int, ll>> ndp(sz[v] + sz[to] + 1, make_pair(0, -INF));
              for (int sz1 = 0; sz1 <= sz[v]; sz1++) {
                  for (int sz2 = 0; sz2 <= sz[to]; sz2++) {
                      ndp[sz1 + sz2] = max(ndp[sz1 + sz2], make_pair(cdp[sz1].first + dp[to][sz2].first, cdp[sz1].second + dp[to][sz2].second));
                  }
              }
              sz[v] += sz[to];
              cdp.swap(ndp);
          }
          for (int i = sz[v] - 1; i >= 0; i--) {
//              db2(cdp[i].first, cdp[i].second);
              cdp[i + 1] = max(cdp[i + 1], make_pair(cdp[i].first + (cdp[i].second > 0), 0LL));
          }
          dp[v].swap(cdp);
      };
//      db("");
      dfs(0, -1);
      int res = dp[0][m - 1].first + (dp[0][m - 1].second > 0);
      cout << res << endl;
  }

  return 0;
}