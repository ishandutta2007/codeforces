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
  freopen("a.in", "r", stdin);
//  freopen("a.out", "w", stdout);
#endif

  int T;
  scanf("%d", &T);
  while (T--) {
      static char buf[(int)2.01e7];
      scanf("%s", buf);
      string s = buf;


      int n = s.length();
      vector<int> ans;
      int i = 0;
      while (i + 2 < n) {
          if (i + 4 < n && s.substr(i, 5) == "twone") {
              ans.push_back(i + 2);
              i += 3;
              continue;
          }
          if (s.substr(i, 3) == "one" || s.substr(i, 3) == "two") {
              ans.push_back(i + 1);
              i += 3;
              continue;
          }
          i++;
      }

      printf("%d\n", (int)ans.size());
      for (int i = 0; i < (int)ans.size(); i++) printf("%d ", ans[i] + 1);
      printf("\n");
  }

  return 0;
}