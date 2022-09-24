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

ll solve(vector<ll> _a, vector<ll> _b) {
    vector<pair<ll, ll>> a;
    for (int i = 0; i < (int)_a.size(); i++) {
        a.push_back({_a[i], _b[i]});
    }
    int n = a.size();
    sort(a.begin(), a.end());

    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((a[i].first | a[j].first) != a[j].first) {
                deg[i]++;
            }
        }
    }

    for (int taken = n; taken >= 1; taken--) {
        int cur = -1;
        for (int v = 0; v < n; v++) {
            if (deg[v] == taken - 1) {
                cur = v;
                break;
            }
        }
        if (cur == -1) break;
        deg[cur] = -1;
        for (int j = 0; j < n; j++) {
            if (deg[j] >= 0 && (a[j].first | a[cur].first) != a[cur].first) {
                deg[j]--;
            }
        }
    }
    ll sum = 0;
    for (int i= 0; i < n; i++) if (deg[i] >= 0) sum += a[i].second;
    return sum;
}


int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
//  test();

  int n;
  while (cin >> n) {
      vector<ll> a(n), b(n);
      for (int i = 0; i < n; i++) cin >> a[i];
      for (int i = 0; i < n; i++) cin >> b[i];

      cout << solve(a, b) << endl;
  }

  return 0;
}