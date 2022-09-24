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

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int T;
  scanf("%d", &T);
  while (T--) {
      int n, k;
      scanf("%d%d", &n, &k);
      vector<vector<pair<int, int>>> e(n);
      for (int i = 0; i < n - 1; i++) {
          int u, v, w;
          scanf("%d%d%d", &u, &v, &w);
          u--; v--;
          e[u].push_back({v, w});
          e[v].push_back({u, w});
      }

      vector<vector<ll>> dp(n, vector<ll>(2));
      function<void(int, int)> dfs = [&](int v, int pr) {
          ll sum = 0;
          vector<ll> vct;
          for (auto o : e[v]) {
              int to = o.first;
              if (to == pr) continue;
              dfs(to, v);
              sum += dp[to][0];
              vct.push_back(max(0LL, dp[to][1] + o.second - dp[to][0]));
          }
          sort(vct.begin(), vct.end());
          reverse(vct.begin(), vct.end());

          dp[v][0] = dp[v][1] = sum;
          for (int i = 0; i < min((int)vct.size(), k); i++) dp[v][0] += vct[i];
          for (int i = 0; i < min((int)vct.size(), k - 1); i++) dp[v][1] += vct[i];
      };
      dfs(0, -1);
      printf("%lld\n", max(dp[0][0], dp[0][1]));
  }

  return 0;
}