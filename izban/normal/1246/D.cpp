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
#include <random>

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

void solve(vector<int> p) {
    int n = p.size();
    vector<vector<int>> e(n);
    for (int i = 1; i < n; i++) {
        e[p[i]].push_back(i);
    }

    vector<int> cnt(n, 1);
    for (int i = n - 1; i > 0; i--) {
        cnt[p[i]] += cnt[i];
    }
    vector<int> mx(n, 1);
    for (int i = n - 1; i > 0; i--) {
        mx[p[i]] = max(mx[p[i]], mx[i] + 1);
    }

    deque<int> ans_b, ans_q;

    function<void(int)> dfs = [&](int v) {
        sort(e[v].begin(), e[v].end(), [&](int x, int y) {
            return mx[x] < mx[y];
//            return cnt[x] < cnt[y];
        });

        ans_b.push_back(v);


        for (int i = 0; i < (int)e[v].size(); i++) {
//        for (int i = (int)e[v].size() - 1; i >= 0; i--) {
            int to = e[v][i];
            dfs(to);
        }

        for (int i = 1; i < (int)e[v].size(); i++) {
            for (int j = 0; j < mx[e[v][i - 1]]; j++) {
                ans_q.push_back(e[v][i]);
            }
        }
    };
    dfs(0);

    assert((int)ans_b.size() == n);
    assert((int)ans_q.size() <= (int)1e6);

    vector<int> pp(n);
    assert(ans_b[0] == 0);
    for (int i = 1; i < n; i++) pp[ans_b[i]] = ans_b[i - 1];

    for (auto v : ans_q) {
        assert(pp[v] != 0);
        pp[v] = pp[pp[v]];
    }
    assert(p == pp);


    for (int i = 0; i < n; i++) printf("%d%c", ans_b[i], " \n"[i + 1 == n]);
    printf("%d\n", (int)ans_q.size());
    for (int i = 0; i < (int)ans_q.size(); i++) printf("%d%c", ans_q[i], " \n"[i + 1 == (int)ans_q.size()]);
}

void stress() {
    for (int it = 0;; it++) {
        mt19937 rnd(it);
        db(it);

        int n = rnd() % 100 + 1;
        vector<int> p(n);
        for (int i = 1; i < n; i++) p[i] = rnd() % i;
        solve(p);
    }
}

void test() {
    int n = 1e5;
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        p[i] = (i - 1) / 2;
    }
    solve(p);
    exit(0);
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
//  test();
//  stress();

  int n;
  while (scanf("%d", &n) == 1) {
      vector<int> p(n);
      for (int i = 1; i < n; i++) {
          scanf("%d", &p[i]);
      }

      solve(p);
  }

  return 0;
}