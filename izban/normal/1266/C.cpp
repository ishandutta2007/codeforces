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

vector<vector<int>> solve(int n, int m) {
    if (n == 1 && m == 1) return vector<vector<int>>();
    vector<vector<int>> ans(n, vector<int>(m));

    if (n == 1 || m == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = i + j + 2;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = (i + 1) * (n + j + 1);
            }
        }
    }

    vector<int> g;
    for (int i = 0; i < n; i++) {
        int gg = 0;
        for (int j = 0; j < m; j++) {
            gg = __gcd(gg, ans[i][j]);
        }
        g.push_back(gg);
    }
    for (int j = 0; j < m; j++) {
        int gg = 0;
        for (int i = 0; i < n; i++) {
            gg = __gcd(gg, ans[i][j]);
        }
        g.push_back(gg);
    }
    sort(g.begin(), g.end());
//    db2(n, m);
//    dbv(g);
    for (int i = 1; i < (int)g.size(); i++) assert(g[i] != g[i - 1]);
    assert(g.back() == n + m);

    return ans;
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
//  for (int n = 1; n <= 10; n++) {
//      for (int m =1; m <= 10; m++) {
//          solve(n, m);
//      }
//  }

  int n, m;
  while (cin >> n >> m) {
      auto a = solve(n, m);
      if (a.empty()) printf("0\n");
      else {
          for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                  printf("%d ", a[i][j]);
              }
              printf("\n");
          }
      }
  }

  return 0;
}