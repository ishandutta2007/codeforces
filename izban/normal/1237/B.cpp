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
      vector<int> a(n), b(n);
      for (int i= 0; i < n; i++) {
          scanf("%d", &a[i]);
          a[i]--;
      }
      for (int i= 0; i < n; i++) {
          scanf("%d", &b[i]);
          b[i]--;
      }

      vector<int> ra(n), rb(n);
      for (int i = 0; i < n; i++) ra[a[i]] = i;
      for (int i = 0; i < n; i++) rb[b[i]] = i;

      int ans =0;
      int mx = 0;
      for (int i = 0; i < n; i++) {
          mx = max(mx, rb[a[i]]);
          if (mx > rb[a[i]]) {
              ans++;
          }
      }


//      for (int i = 0; i < n; i++) b[i] = ra[b[i]];
//
//
//      vector<int> mxrb = rb;
//      for (int i = 1; i < n; i++) mxrb[i] = max(mxrb[i], mxrb[i - 1]);
//
//      int ans = 0;
//      for (int i = 0; i < n; i++) {
//          ans += rb[i] > i;
//      }
      cout << ans << endl;
  }

  return 0;
}