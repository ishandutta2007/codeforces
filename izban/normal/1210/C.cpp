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

const int MOD = 1e9 + 7;

int solve(vector<ll> x, vector<vector<int>> e) {
    int n = x.size();

    int ans = 0;
    function<void(int, int, vector<pair<ll, int>>)> dfs = [&](int v, int pr, vector<pair<ll, int>> vct) {
        for (auto &o : vct) {
            o.first = __gcd(o.first, x[v]);
        }
        vct.emplace_back(x[v], 1);

        int j = 0;
        for (int i = 1; i < (int)vct.size(); i++) {
            if (vct[i].first == vct[j].first) {
                vct[j].second += vct[i].second;
            } else {
                vct[++j] = vct[i];
            }
        }
        vct.resize(j + 1);
        for (const auto &o : vct) {
//            db3(v, o.first, o.second);
            ans = (ans + 1LL * o.first * o.second) % MOD;
        }
        for (int to : e[v]) {
            if (to == pr) continue;
            dfs(to, v, vct);
        }
    };
    dfs(0, -1, {});
    return ans;
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
      vector<ll> x(n);
      for (int i = 0; i < n; i++) scanf("%lld", &x[i]);
      vector<vector<int>> e(n);
      for (int i = 0; i < n- 1; i++) {
          int u, v;
          scanf("%d%d", &u, &v);
          u--; v--;
          e[u].push_back(v);
          e[v].push_back(u);
      }

      printf("%d\n", solve(x, e));
      
//      db("");
  }

  return 0;
}