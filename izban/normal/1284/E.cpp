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

namespace dbl_utils {
    typedef double dbl;

    const dbl EPS = 1e-9;

    bool eq(dbl a, dbl b) {
        return fabs(a - b) < EPS;
    }

    bool ne(dbl a, dbl b) {
        return !eq(a, b);
    }

    bool lt(dbl a, dbl b) {
        return a < b && !eq(a, b);
    }

    bool le(dbl a, dbl b) {
        return !lt(b, a);
    }

    bool ge(dbl a, dbl b) {
        return !lt(b, a);
    }

    bool gt(dbl a, dbl b) {
        return lt(b, a);
    }

    int sign(dbl x) {
        if (eq(x, 0)) return 0;
        if (x > 0) return 1;
        return -1;
    }
}
using namespace dbl_utils;

template <typename T>
struct _pt {
    T x, y;

    _pt<T>() {}
    _pt<T>(T _x, T _y) : x(_x), y(_y) {}

    _pt<T> operator+ (const _pt<T> &p) const {
        return _pt<T>(x + p.x, y + p.y);
    }

    _pt<T>& operator+= (const _pt<T> &p) {
        return *this = *this + p;
    }

    _pt<T> operator- (const _pt<T> &p) const {
        return _pt<T>(x - p.x, y - p.y);
    }

    _pt<T>& operator-= (const _pt<T> &p) {
        return *this = *this - p;
    }

    _pt<T> operator* (T d) const {
        return _pt<T>(x * d, y * d);
    }

    _pt<T>& operator*= (T d) {
        return *this = *this * d;
    }

    T operator* (const _pt<T> &p) const {
        return x * p.y - y * p.x;
    }

    T operator% (const _pt<T> &p) const {
        return x * p.x + y * p.y;
    }

    T d2() const {
        return *this % *this;
    }

    dbl d() const {
        return sqrt((dbl)d2());
    }

    dbl ang() const {
        return atan2((dbl)y, (dbl)x);
    }

    _pt<T> rotate90() const {
        return _pt<T>(-y, x);
    }

    _pt<T> rotate(dbl ang) {
        return _pt<T>(x * cos(ang) - y * sin(ang),
                      x * sin(ang) + y * cos(ang));
    }

    int turn(const _pt<T> &p) const {
        return sign((*this) * p);
    }

    int up() const {
        if (y > 0 || y == 0 && x > 0) return 1;
        if (y < 0 || y == 0 && x < 0) return -1;
        return 0;
    }

    bool operator< (const _pt<T> &p) const {
        if (!eq(x, p.x)) return lt(x, p.x);
        return lt(y, p.y);
    }

    bool operator== (const _pt<T> &p) const {
        return eq(x, p.x) && eq(y, p.y);
    }

    void read() {
        cin >> x >> y;
    }
};
typedef _pt<long long> pt;


int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
      vector<pt>  a(n);
      for (int i = 0; i < n; i++) {
          scanf("%lld%lld", &a[i].x, &a[i].y);
      }

      ll ans = 0;
      for (int j = 0; j < n; j++) {
          vector<pt> b;
          for (int i = 0; i < n; i++) if (i != j) b.push_back(a[j] - a[i]);

          sort(b.begin(), b.end(), [&](const pt &p1, const pt &p2) {
             if (p1.up() != p2.up()) {
                 return p1.up() > p2.up();
             }
             return p1 * p2 > 0;
          });
          for (int i = 0; i < n; i++) b.push_back(b[i]);

          ll all = 0;
          all += 1LL * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;

          int nxt = 0;
          for (int i = 0; i < n - 1; i++) {
              nxt = max(nxt, i + 1);
              while ((b[i] * b[nxt]) > 0) nxt++;
              assert(nxt < (int)b.size());

              int num = nxt - i;
              ll cur = 1LL * (num - 1) * (num - 2) * (num - 3) / 6;
              all -= cur;
          }
          ans += all;
      }
      printf("%lld\n", ans);
  }

  return 0;
}