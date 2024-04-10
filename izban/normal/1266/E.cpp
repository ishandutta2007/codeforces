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

struct change {
    int s, t, u;
};

vector<ll> solve(vector<int> a, vector<change> b) {
    ll sum = 0;
    for (auto x : a) sum += x;

    vector<ll> ans;

    int n = a.size();
    vector<int> cntr(n);
    auto change_counter = [&](int i, int delta) {
        sum -= max(0, a[i] - cntr[i]);
        cntr[i] += delta;
        sum += max(0, a[i] - cntr[i]);
    };

    map<pair<int, int>, int> mp;
    for (auto c : b) {
        auto it = mp.find({c.s, c.t});
        if (it != mp.end()) {
            change_counter(it->second, -1);
            mp.erase(it);
        }

        if (c.u != -1) {
            mp[{c.s, c.t}] = c.u;
            change_counter(c.u, +1);
        }
        ans.push_back(sum);
    }

    return ans;
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int n;
  while (scanf("%d", &n)  == 1) {
      vector<int> a(n);
      for  (int i = 0; i < n; i++) {
          scanf("%d", &a[i]);
      }

      int q;
      scanf("%d", &q);
      vector<change> b(q);
      for (int i = 0; i < q; i++) {
          scanf("%d%d%d", &b[i].s, &b[i].t, &b[i].u);
          b[i].s--;
          b[i].u--;
      }

      auto ans = solve(a, b);
      for (auto x : ans) printf("%lld\n", x);
  }

  return 0;
}