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

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
      vector<string> a(n);
      for (int i = 0; i < n; i++) {
          static char buf[(int)1.01e6];
          scanf("%s", buf);
          a[i] = buf;
      }

      auto calc_s = [&](vector<string> aa) {
          vector<vector<int>> s(n + 1, vector<int>(m + 1));
          for (int i = 1; i <= n; i++) {
              for (int j = 1; j <= m; j++) {
                  s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (int)(aa[i - 1][j - 1] == 'X');
              }
          }
          return s;
      };
      auto s = calc_s(a);

      auto ok = [&](int x1, int y1, int x2, int y2) {
          if (x1 < 0 || y1 < 0 || x2 >= n || y2 >= m) return false;
          int sum = s[x2 + 1][y2 + 1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x1][y1];
          return sum == (x2 - x1 + 1) * (y2 - y1 + 1);
      };

      vector<string> nres;

      auto check = [&](int M) {
          vector<string> res(n, string(m, '.'));
          vector<vector<int>> b(n + 1, vector<int>(m + 1));
          for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                  if (ok(i - M, j - M, i + M, j + M)) {
                      res[i][j] = 'X';
                      b[i-M][j-M]++;
                      b[i+M+1][j-M]--;
                      b[i-M][j+M+1]--;
                      b[i+M+1][j+M+1]++;
                  }
              }
          }
          auto ss = calc_s(res);
          bool ok = 1;
          for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                  if (i) b[i][j] += b[i - 1][j];
                  if (j) b[i][j] += b[i][j - 1];
                  if (i && j) b[i][j] -= b[i - 1][j - 1];
                  ok &= (b[i][j] > 0) == (a[i][j] == 'X');
              }
          }
          if (ok) {
              nres = res;
          }
          return ok;
      };

      int L = -1;
      int R = min(n, m);
      while (R - L > 1) {
          int M = (L + R) >> 1;

          if (check(M)) L = M;
          else R = M;
      }
      assert(L >= 0);
      check(L);
      printf("%d\n", L);
      for (int i = 0; i < n; i++) printf("%s\n", nres[i].c_str());
  }

  return 0;
}