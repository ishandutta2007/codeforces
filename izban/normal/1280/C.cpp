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
      int k;
      scanf("%d", &k);
      int n = 2 * k;
      vector<vector<pair<int, int>>> e(n);
      for (int i = 0; i < n - 1; i++) {
          int u, v, w;
          scanf("%d%d%d", &u, &v, &w);
          u--; v--;
          e[u].push_back({v, w});
          e[v].push_back({u, w});
      }

      ll ansMin = 0;
      ll ansMax = 0;
      vector<int> cnt(n);
      function<void(int, int)> dfs = [&](int v, int pr) {
          cnt[v] = 1;
          for (auto o : e[v]) {
              int to = o.first;
              if (to == pr) continue;
              dfs(to, v);
              cnt[v] += cnt[to];
              if (cnt[to] % 2 == 1) {
                  ansMin += o.second;
              }
              ansMax += min(cnt[to], n - cnt[to]) * 1LL * o.second;
          }
      };
      dfs(0, -1);

      cout << ansMin << " " << ansMax << endl;
  }

  return 0;
}