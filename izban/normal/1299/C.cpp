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

#ifdef HOME 
#define LOCAL
#endif

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

void print(vector<double> a) {
    for (auto x : a) printf("%.17f\n", x);
}



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
    bool operator< (const _pt<T> &p) const {
        if (!eq(x, p.x)) return lt(x, p.x);
        return lt(y, p.y);
    }
    bool operator== (const _pt<T> &p) const {
        return eq(x, p.x) && eq(y, p.y);
    }
    void read() {
        std::cin >> x >> y;
    }
};
typedef _pt<long long> pt;
std::vector<pt> convex_hull(std::vector<pt> a, int on_side) {
    int n = a.size();
    sort(a.begin(), a.end());
    pt p1 = a[0], p2 = a.back();
    std::vector<pt> up, down;
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1 || (a[i] - p1).turn(p2 - p1) >= 0) {
            while (down.size() > 1 && (a[i] - down.back()).turn(down.back() - down[(int)down.size() - 2]) >= on_side) {
                down.pop_back();
            }
            down.push_back(a[i]);
        }
        if (i == 0 || i == n - 1 || (a[i] - p1).turn(p2 - p1) <= 0) {
            while (up.size() > 1 && (a[i] - up.back()).turn(up.back() - up[(int)up.size() - 2]) <= -on_side) {
                up.pop_back();
            }
            up.push_back(a[i]);
        }
    }
    for (int i = (int)up.size() - 2; i > 0; i--) down.push_back(up[i]);
    return down;
}

vector<double> solve(vector<int> a) {
    int n = a.size();

    vector<pt> b(n + 1);
    b[0] = pt(0, 0);
    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + pt(1, a[i]);
    }

    auto c = convex_hull(b, 0);
    while (c.back().x != n) {
      c.pop_back();
    }
    assert(c[0].x == 0);
    assert(c.back().x == n);

    vector<double> ans(n);
    for (int i = 0; i + 1 < (int)c.size(); i++) {
        ll sum = 0;
        int cnt =0;
        for (int x = c[i].x + 1; x <= c[i + 1].x; x++) {
            sum += a[x - 1];
            cnt++;
        }
        for (int x = c[i].x + 1; x <= c[i + 1].x; x++) {
            ans[x - 1] = sum * 1.0 / cnt;
        }
    }

    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    bool first = 1;
    while (scanf("%d", &n) == 1) {
        if (first) first = 0;
        else printf("\n");

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        print(solve(a));
    }

    return 0;
}