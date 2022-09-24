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

  int n, q;
  while (scanf("%d%d", &n, &q) == 2) {
      vector<vector<int>> a(2, vector<int>(n));

      int cnt = 0;

      auto add = [&](int x, int y, int delta) {
          if (a[x][y]) {
              for (int d = -1; d <= 1; d++) {
                  if (0 <= y + d && y + d < n) {
                      cnt += a[x ^ 1][y + d] * delta;
                  }
              }
          }
      };

      auto change = [&](int x, int y) {
          add(x, y, -1);
          a[x][y] ^= 1;
          add(x, y, +1);
      };

      while (q--) {
          int x, y;
          scanf("%d%d", &x, &y);
          x--; y--;
          change(x, y);
          string t = cnt == 0 ? "Yes" : "No";
          printf("%s\n", t.c_str());
      }
  }

  return 0;
}