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

template <typename T>
struct fenwick {
    int n;
    vector<T> f;

    fenwick() {}

    fenwick(int N) {
        n = N;
        f.assign(N, T(0));
    }

    fenwick(vector<T> a) {
        n = a.size();
        for (int i = 0; i < n; i++) add(i, a[i]);
    }

    void add(int x, T y) {
        for (; x < n; x |= x + 1) f[x] += y;
    }

    T get(int x) {
        T res(0);
        for (; x >= 0; x = (x & (x + 1)) - 1) res += f[x];
        return res;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }

    // return min i: sum(0, i) > x
    int upper_bound(T x) {
        int k = 1;
        while (2 * k <= n) k *= 2;

        int res = 0;
        while (k > 0) {
            if (f[res + k - 1] <= x) {
                x -= f[res + k - 1];
                res += k;
            }
            k /= 2;
        }
        return res;
    }
};

vector<int> solve(vector<int> a, vector<pair<pair<int, int>, int>> c) {
    int n = a.size();
    int q = c.size();

    sort(c.begin(), c.end());

    fenwick<int> f(n + 1);
    vector<pair<int, int>> vct(n);
    for (int i = 0; i < n; i++) vct[i] = {a[i], i};
    sort(vct.begin(), vct.end(), [](pair<int, int> x, pair<int, int> y) {
        if (x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });

    vector<int> ans(q);
    int added = 0;
    for (auto o : c) {
        while (added < o.first.first) {
            f.add(vct[added].second, +1);
            added++;
        }
        int L = -1, R = n;
        while (R - L > 1) {
            int M = (L + R) >> 1;
            if (f.get(M) >= o.first.second) R = M;
            else L = M;
        }
        assert(R < n);
        ans[o.second] = a[R];
    }
    return ans;
}

void stress() {
    for (int it = 0;; it++) {
        db(it);
        mt19937 rnd(it);

        int n = rnd() % (int)2e5 + 1;
        int q = rnd() % (int)2e5 + 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] =rnd() % (int)1e9 + 1;
        vector<pair<pair<int, int>, int>> c(q);
        for (int i = 0; i < q; i++) {
            c[i].second =i ;
            c[i].first.first = rnd() % n + 1;
            c[i].first.second = rnd() % c[i].first.first + 1;
        }
        solve(a, c);
    }
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
//  stress();

  int n;
  bool first = 1;
  while (scanf("%d", &n) == 1) {
      if (first) first = 0;
      else printf("\n");

      vector<int> a(n);
      for (int i = 0; i < n; i++) scanf("%d", &a[i]);
      int q;
      scanf("%d", &q);
      vector<pair<pair<int, int>, int>> c(q);
      for (int i = 0; i < q; i++) {
          scanf("%d%d", &c[i].first.first, &c[i].first.second);
          c[i].second = i;
      }

      auto ans = solve(a, c);
      for (int x : ans) printf("%d\n", x);
  }

  return 0;
}