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

string OK = "YES";
string NO = "NO";
string solve(ll x) {
    for (int i = 1; i <= 6; i++) {
        if (21 - i == x) {
            return OK;
        }
    }
    for (int up = 1; up <= 6; up++) {
        for (int down = 1; down <= 6; down++) {
            ll left = x - up;
            if (left >= 28) {
                if (left % 14 == 0) {
                    return OK;
                }
            }
        }
    }
    return NO;

    vector<int> can;
    for (int i = 1; i <= 6; i++) {
        for (int j = i + 1; j <= 6; j++) {
            if ((i + j) != 7) {
                can.push_back(i + j);
            }
        }
    }
    sort(can.begin(), can.end());
    can.resize(unique(can.begin(), can.end()) - can.begin());
    for (int mask = 0; mask < (1 << 6); mask++) {
        int cnt = 0;
        int sum = 0;
        for (int i = 1; i <= 6; i++) {
            if (((mask >> (i - 1)) & 1) && ((mask >> (7 - i)) & 1)) {
                continue;
            }
            if (mask & (1 << (i - 1))) {
                cnt++;
                sum += i;
            }
        }
        if (cnt != 3) continue;

        for (int y : can) {
            if (x >= sum && (x - sum) % y == 0) {
//                db(mask);
//                db(y);
                return OK;
            }
        }
    }
    return NO;
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
      ll x;
      cin >> x;
      cout << solve(x) << endl;
  }

  return 0;
}