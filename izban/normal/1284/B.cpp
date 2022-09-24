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

  int n;
  while (scanf("%d", &n) == 1) {
      vector<vector<int>> a(n);
      for (int i = 0; i < n; i++) {
          int k;
          scanf("%d", &k);
          a[i].resize(k);
          for (int j = 0; j < k; j++) scanf("%d", &a[i][j]);
      }

      int cnt = 0;
      vector<pair<int, int>> b;
      for (int i = 0; i < n; i++) {
          const int INF = 1e9;
          int mn = INF, mx = -INF;
          bool ok = 0;
          for (int x : a[i]) {
              if (x > mn) {
                  ok = 1;
              }
              mn = min(mn, x);
              mx = max(mx, x);
          }
          if (ok) cnt++;
          else b.push_back({mn, mx});
      }

      vector<int> mins;
      for (auto o : b) mins.push_back(o.first);
      sort(mins.begin(), mins.end());

      ll ans = 0;
      ans += 1LL * cnt * cnt;
      ans += 1LL * cnt * mins.size();
      ans += 1LL * mins.size() * cnt;
      for (auto o : b) {
          ans += lower_bound(mins.begin(), mins.end(), o.second) - mins.begin();
      }
      printf("%lld\n", ans);
  }


  return 0;
}