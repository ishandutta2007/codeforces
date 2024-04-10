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
const int INF = 1e9;

int subsolve(vector<string> a) {
    int n = a.size();
    int m = a[0].size();

    bool anyA = 0;
    bool anyP = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            anyA |= a[i][j] == 'A';
            anyP |= a[i][j] == 'P';
        }
    }
    if (!anyA) return INF;
    if (!anyP) return 0;
    if (a[0] == string(m, 'A')) return 1;

    if (a[0][0] == 'A' || a[0][m - 1] == 'A') return 2;
    for (int i = 0; i < n; i++) {
        if (a[i] == string(m, 'A')) return 2;
    }

    if (a[0] != string(m, 'P')) return 3;

    return 4;
}

int solve(vector<string> a) {
    int res = INF;
    for (int it = 0; it < 4; it++) {
        res = min(res, subsolve(a));
        int n = a.size();
        int m = a[0].size();
        vector<string> b(m, string(n, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[m - 1 - j][i] = a[i][j];
            }
        }
        a = b;
    }
    return res;
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int T;
  scanf("%d", &T);
  while (T--) {
      int n, m;
      scanf("%d%d", &n, &m);
      vector<string> a(n);
      for (int i = 0; i < n; i++) {
          static char buf[(int)1.01e5];
          scanf("%s", buf);
          a[i] = buf;
      }

      int res = solve(a);
      if (res == INF) printf("MORTAL\n");
      else printf("%d\n", res);
  }

  return 0;
}