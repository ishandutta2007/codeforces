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
  while (cin >> n >> m) {
      vector<pair<int, int>> ed(m);
      for (int i = 0; i < m; i++) {
          cin >> ed[i].first >> ed[i].second;
          ed[i].first--; ed[i].second--;
      }

      vector<vector<int>> num(7, vector<int>(7));
      int cc = 0;
      for (int i = 0; i <= 6; i++) {
          for (int j = i; j <= 6; j++) {
              num[i][j] = cc++;
          }
      }
//      for (int i = 0; i <= 6; i++) {
//          dbv(num[i]);
//      }

      vector<int> col(n, -1);
      int ans = 0;
      function<void(int)> rec = [&](int cur) {
          if (cur == n) {
              vector<char> used(cc);
              for (auto o : ed) {
                  int a = col[o.first];
                  int b = col[o.second];
                  if (a > b) swap(a, b);
                  used[num[a][b]] = 1;
              }
              int cnt = 0;
              for (auto x : used) cnt += x;
              ans = max(ans, cnt);
              return;
          }
          for (int x = 1; x <= 6; x++) {
              col[cur] = x;
              rec(cur + 1);
          }
      };
      rec(0);
      cout << ans << endl;
  }

  return 0;
}