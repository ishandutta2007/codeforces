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

ll solve(vector<vector<int>> e) {
    int n= e.size();

    vector<vector<int>> sz(n, vector<int>(n));
    vector<vector<int>> par(n, vector<int>(n));

    vector<vector<pair<int, int>>> vct(n);
    for (int s = 0; s < n; s++) {
        function<void(int, int, int)> dfs = [&](int v, int pr, int ch) {
            if (s < v) {
                vct[ch].push_back({s, v});
            }
            par[s][v] = pr;
            sz[s][v] = 1;
            for (int to : e[v]) {
                if (to == pr) continue;
                dfs(to, v, ch + 1);
                sz[s][v] += sz[s][to];
            }
        };
        dfs(s, -1, 0);
    }

    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int len = 1; len < n; len++) {
        for (auto o : vct[len]) {
            int u = o.first;
            int v = o.second;

            int s1 = sz[u][v];
            int s2 = sz[v][u];

            ll best = max(dp[u][par[u][v]], dp[v][par[v][u]]);
            best +=1LL *  s1 * s2;
            dp[o.first][o.second] = dp[o.second][o.first] = best;
        }
    }
    ll ans = 0;
    for (auto v : dp) {
        ans = max(ans, *max_element(v.begin(), v.end()));
    }
    return ans;
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
      vector<vector<int>> e(n);
      for (int i = 0; i < n - 1; i++) {
          int u, v;
          scanf("%d%d", &u, &v);
          u--; v--;
          e[u].push_back(v);
          e[v].push_back(u);
      }

      printf("%lld\n", solve(e));
  }

  return 0;
}