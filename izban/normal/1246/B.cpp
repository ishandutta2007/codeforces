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
#include <numeric>

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

  const int N = 100100;
  vector<int> lp(N);
  iota(lp.begin(), lp.end(), 0);
  for (int i = 2; i < N; i++) {
      for (int j = i + i; j < N; j += i) {
          lp[j] = min(lp[j], i);
      }
  }

  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
      vector<int> a(n);
      for (int i = 0; i < n; i++) scanf("%d", &a[i]);

      ll ans = 0;
      map<vector<pair<int, int>>, int> mp;
      for (int i = 0; i < n; i++) {
          vector<pair<int, int>> vct;
          for (int x = a[i]; x > 1;) {
              int y = lp[x];
              int cnt = 0;
              while (x % y == 0) {
                  cnt++;
                  x /= y;
              }
              cnt %= k;
              if (cnt > 0) {
                  vct.push_back({y, cnt});
              }
          }
          if (mp.count(vct)) {
              ans += mp[vct];
          }
          for (auto &o : vct) {
              o.second = k - o.second;
          }
          mp[vct]++;
      }
      printf("%lld\n", ans);
  }

  return 0;
}