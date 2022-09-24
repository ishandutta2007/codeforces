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

  const ll MX = 1e16;

  ll x0, y0, ax, ay, bx, by;
  ll xs, ys, t;
  while (cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t) {
      vector<pair<ll, ll>> a;
      a.push_back({x0, y0});
      while (1) {
          if (a.back().first > MX || a.back().second > MX) break;
          a.push_back({ax * a.back().first + bx, ay * a.back().second + by});
      }

      int n = a.size();
      int ans = 0;
      for (int i = 0; i < n; i++) {
          for (int d = -1; d <= 1; d += 2) {
              ll cx = xs, cy = ys;
              ll ct = t;
              int cur = 0;
              for (int j = i; 0 <= j && j < n; j += d) {
                  ct -= abs(cx - a[j].first) + abs(cy - a[j].second);
                  if (ct < 0) break;
                  cx = a[j].first;
                  cy = a[j].second;
                  cur++;
                  ans = max(ans, cur);
              }
          }
      }
      cout << ans << endl;
  }

  return 0;
}