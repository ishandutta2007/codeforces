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

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int T;
  scanf("%d", &T);
  while (T--) {
      int n;
      scanf("%d", &n);
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
          scanf("%d", &a[i]);
          a[i]--;
      }
      auto v = a;
      sort(v.begin(), v.end());
      v.resize(unique(v.begin(), v.end()) - v.begin());
      int m = v.size();
      for (auto &x : a) x = lower_bound(v.begin(), v.end(), x) - v.begin();

      vector<int> mn(m, INF), mx(m, -INF);
      for (int i = 0; i < n; i++) {
          mn[a[i]] = min(mn[a[i]], i);
          mx[a[i]] = max(mx[a[i]], i);
      }

      vector<int> pref(m + 1);
      for (int i = 0; i < m; i++) {
          pref[i + 1] = pref[i] + (int)(mn[i] != INF);
      }
      vector<int> suf(m + 1);
      for (int i = m - 1; i >= 0; i--) {
          suf[i] = suf[i + 1] + (mn[i] != INF);
      }

//      for (int i = 1; i < n; i++) {
//          mx[i] = max(mx[i], mx[i - 1]);
//      }

      int ans = INF;

      int j = -1;
      for (int i = 0; i < m; i++) {
          j = max(j, i);
          while (j + 1 < m && mn[j + 1] > mx[j]) {
              j++;
          }
          ans = min(ans, pref[i] + suf[j + 1]);
      }
      printf("%d\n", ans);
  }

  return 0;
}